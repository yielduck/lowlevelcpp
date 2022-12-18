#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdint>

int main()
{
    using i64 = std::int64_t;

    i64 t0, t1, n;
    std::cin >> t0 >> t1 >> n;

    std::map<i64, std::vector<i64>> entry;
    i64 record, time, person;
    while(std::cin >> record >> time >> person)
        entry[person].push_back(time);

    i64 id = 0, dtMax = 0;
    for(auto const e : entry)
    {
        auto v = e.second;
        v.push_back(t0);
        v.push_back(t1);
        std::sort(v.begin(), v.end());

        for(std::size_t i = 0; i + 1 < v.size(); ++i)
        {
            auto const dt = v[i + 1] - v[i];
            if(dtMax < dt)
            {
                dtMax = dt;
                id = e.first;
            }
        }
    }
    std::cout << id << std::endl;
}
