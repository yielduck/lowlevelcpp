#include <cstdio>
#include <vector>
#include <algorithm>

struct vec3
{
    int x, y, z;
};

int dot(vec3 const &v1, vec3 const &v2)
{
    return v1.x * v2.x
         + v1.y * v2.y
         + v1.z * v2.z;
}

int main()
{
    vec3 r;
    std::vector<vec3> v;
    while(3 == std::scanf("(%i, %i, %i) ", &r.x, &r.y, &r.z))
        v.push_back(r);
    auto const shorter = [](vec3 const &v1, vec3 const &v2) {return dot(v1, v1) < dot(v2, v2);};
    std::sort(v.begin(), v.end(), shorter);
    for(vec3 const &a : v)
        std::printf("(%i, %i, %i) ", a.x, a.y, a.z);
    std::puts("");
}
