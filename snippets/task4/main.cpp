#include "include/camera.h"
#include "include/image.h"
#include "include/tree.h"
#include "include/wfobj.h"

#include <fstream>
#include <iostream>

struct Hit
{
    vec3 position;
    vec3 normal;
    vec3 albedo;
};

int main()
{
    using u32 = unsigned int;

    u32 const width  = 1920u;
    u32 const height = 1080u;

    float const fwidth  =  width;
    float const fheight = height;

    Camera const camera =
    {
        .position = {-4.f, 3.6f, 12.f},
        .at = {0.f, 0.f, 0.f},
        .up = {0.f, 1.f, 0.f},
        .aspectRatio = fwidth / fheight,
        .verticalFOV = 0.55f,
    };

    std::ifstream mesh("../A6M.obj");
    std::vector<Triangle> triangle = parseOBJ(mesh);
    Tree const tree = createTree(triangle);
    Image const image = createImage("../A6M.png");

    auto const closestHit = [&](Ray const &ray)
        -> std::optional<Hit>
    {
        /* bruteforce:
        if(triangle.size() == 0u)
            return std::nullopt;

        std::vector<RayTriangleIntersection> intersection;
        for(auto const &t : triangle)
            intersection.push_back(rayTriangleIntersection(ray, t));

        auto const it = std::min_element(intersection.begin(), intersection.end());
        if(false == happened(*it))
            return std::nullopt;

        float const t = it->t;
        auto const i = it - intersection.begin();

        vec2 const tex = interpolate(triangle[i].t, *it);
        return
        {{
            .position = ray.point(t),
            .normal = normalize(interpolate(triangle[i].n, *it)),
            .albedo = sample(image, tex),
        }}; */

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
        float const exposure = 0.3f;
        float const almost256 = 255.999f;
        return vec3
        {
            almost256 * (1.f - std::exp(-exposure * c.x)),
            almost256 * (1.f - std::exp(-exposure * c.y)),
            almost256 * (1.f - std::exp(-exposure * c.z)),
        };
    };

    std::cout << "P3\n" << width << " " << height << "\n255\n";
    for(u32 y = 0u; y < height; ++y)
    for(u32 x = 0u; x <  width; ++x)
    {
        float const u = -1.f + 2.f * float(x) / fwidth;
        float const v = -1.f + 2.f * float(y) / fheight;
        float const du = 1.f / fwidth;
        float const dv = 1.f / fheight;

        // 4 rays for antialiasing
        vec3 const color = tonemap
        (
            trace(camera.castRay(u - du, -v - dv))
          + trace(camera.castRay(u - du, -v + dv))
          + trace(camera.castRay(u + du, -v - dv))
          + trace(camera.castRay(u + du, -v + dv))
        );

        std::cout << u32(color.x) << " ";
        std::cout << u32(color.y) << " ";
        std::cout << u32(color.z) << " ";
    }

    destroyTree(tree);
    deleteImage(image);
}
