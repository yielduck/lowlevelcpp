struct vec2
{
    int x, y;
};
vec2 operator-(vec2 const v1, vec2 const v2)
{
    return
    {
        .x = v1.x - v2.x,
        .y = v1.y - v2.y,
    };
}

#include <iostream>
#include <vector>
int main()
{
    vec2 pmin, pmax;
    std::cin >> pmin.x >> pmin.y;
    std::cin >> pmax.x >> pmax.y;

    unsigned int n;
    std::cin >> n;

    std::vector<vec2> point;
    point.reserve(n);

    vec2 p;
    for(unsigned int i = 0u; i < n; ++i)
    {
        std::cin >> p.x >> p.y;
        point.push_back(p);
    }

    for(int py = pmax.y; py >= pmin.y; --py)
    {
        for(int px = pmin.x; px <= pmax.x; ++px)
        {
            vec2 p = {px, py};

            // https://en.wikipedia.org/wiki/Point_in_polygon
            // cast a ray from (p.x, p.y) in positive-x direction, count winding number
            // counting intersection number will fail when ray crosses the polygon vertex

            int wn = 0;
            int wnv = 0; // separate winding number for vertices -- count them twice, divide by two at the end
            for(unsigned int j = 0u; j < n; ++j)
            {
                vec2 const p0 = point[ j         ];
                vec2 const p1 = point[(j + 1) % n];
                vec2 const dp1 = p1 - p0;
                vec2 const dp  = p  - p0;

                if(dp1.y != 0)
                {
                    double const t = double(dp.y) / double(dp1.y);
                    double const x = p0.x + t * dp1.x;
                    if(t < 0. || t > 1. || x < p.x)
                        continue;
                    if(x == p.x)
                    {
                        wn = -1;
                        wnv = 0;
                        break;
                    }
                    int const dwn = dp1.y > 0 ? 1 : -1;
                    if(t == 0. || t == 1.)
                        wnv += dwn;
                    else
                        wn += dwn;
                }
                else if(p.y == p0.y)
                {
                    double const t = double(dp.x) / double(dp1.x);
                    if(t >= 0. && t <= 1.)
                    {
                        wn = -1;
                        wnv = 0;
                        break;
                    }
                }
            }
            std::cout << (wn + wnv / 2 != 0 ? '0' : '.');
        }
        std::cout << std::endl;
    }
}
