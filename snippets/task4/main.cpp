#include "include/camera.h"
#include "include/image.h"
#include "include/tree.h"
#include "include/wfobj.h"

#include <fstream>
#include <iostream>

#include <SFML/Graphics.hpp>

extern "C" // black magic
{
void _ZN2sf6StringC1EPKcRKSt6locale() {}
}

struct Hit
{
    vec3 position;
    vec3 normal;
    vec3 albedo;
};

int main()
{
    using u32 = unsigned int;

    u32 const width  = 1280u;
    u32 const height = 720u;

    sf::RenderWindow window(sf::VideoMode(width, height), "The window");

    float const fwidth  =  width;
    float const fheight = height;

    std::ifstream mesh("../A6M.obj");
    std::vector<Triangle> triangle = parseOBJ(mesh);
    Tree const tree = createTree(triangle);
    Image const image = createImage("../A6M.png");

    auto const closestHit = [&](Ray const &ray)
        -> std::optional<Hit>
    {
        auto const opt = rayTreeIntersection(ray, tree);
        if(!opt)
            return std::nullopt;
        auto const [tri, i] = *opt;
        vec2 const tex = interpolate(tri.t, i);
        return
        {{
            .position = ray.point(i.t),
            .normal = normalize(interpolate(tri.n, i)),
            .albedo = sample(image, interpolate(tri.t, i)),
        }};
    };

    auto const trace = [&closestHit](Ray const &ray)
    {
        vec3 const   skyColor = {0.53f, 0.81f, 0.92f};
        vec3 const lightColor = {1.00f, 0.98f, 0.88f};
        vec3 const lightDir   = normalize({3.f, 3.f, -1.f});

        std::optional<Hit> const hit = closestHit(ray);
        if(!hit)
            return dot(ray.direction, lightDir) < 0.999f
                ? skyColor
                : lightColor * 2.f;

        Ray const shadowRay =
        {
            .origin = hit->position,
            .direction = lightDir
        };
        std::optional<Hit> const shadowHit = closestHit(shadowRay);
        float const NL = std::max(0.f, dot(hit->normal, lightDir));

        vec3 const color = !shadowHit
            ? lightColor * NL
            : vec3{0.f, 0.f, 0.f};

        return (skyColor * 0.3f + color) * hit->albedo;
    };
    auto const tonemap = [](vec3 const c)
    {
        float const exposure = 1.f;
        float const almost256 = 255.999f;
        return RGBA
        {
            .r = static_cast<unsigned char>(almost256 * (1.f - std::exp(-exposure * c.x))),
            .g = static_cast<unsigned char>(almost256 * (1.f - std::exp(-exposure * c.y))),
            .b = static_cast<unsigned char>(almost256 * (1.f - std::exp(-exposure * c.z))),
            .a = 255,
        };
    };

    std::vector<RGBA> color(width * height);
    sf::Texture texture;
    texture.create(width, height);

    sf::Sprite sprite(texture);

    float phi = 0.f;
    float theta = 0.4f;
    float const r = 15.f;
    Camera camera =
    {
        .position = {0.f, 0.f, r},
        .at = {0.f, 0.f, 0.f},
        .up = {0.f, 1.f, 0.f},
        .aspectRatio = fwidth / fheight,
        .verticalFOV = 0.55f,
    };

    while(window.isOpen())
    {
        phi -= 0.1f;
        camera.position = vec3
        {
            std::cos(theta) * std::sin(phi),
            std::sin(theta),
            std::cos(theta) * std::cos(phi),
        } * r;

        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        for(u32 y = 0u; y < height; ++y)
        for(u32 x = 0u; x <  width; ++x)
        {
            float const u = -1.f + 2.f * float(x) / fwidth;
            float const v = -1.f + 2.f * float(y) / fheight;
            color[y * width + x] = tonemap(trace(camera.castRay(u, -v)));
        }

        texture.update(reinterpret_cast<sf::Uint8 const *>(color.data()));
        window.draw(sprite);

        window.display();
    }

    destroyTree(tree);
    deleteImage(image);
}
