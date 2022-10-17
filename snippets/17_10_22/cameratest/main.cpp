#include <camera.h>
#include <iostream>

std::ostream &operator<<(std::ostream &out, vec3 const &v)
{
    return (out << "(" << v.x << ", " << v.y << ", " << v.z << ")");
}
int main()
{
    Camera const camera =
    {
        .position = {0.f, 0.f, -1.f},
        .at = {0.f, 0.f, 0.f},
        .up = {0.f, 1.f, 0.f},
        .aspectRatio = 1.f,
        .verticalFOV = 1.f,
    };
    Ray const ray = camera.castRay(0.f, 0.f);
    std::cout << ray.origin << std::endl;
    std::cout << ray.direction << std::endl;
}
