#include <iostream>
#include <cstring>
#include <vector>

template<typename T>
T parse(char const *s)
{
    char const byte[4] = {s[3], s[2], s[1], s[0]};
    return *reinterpret_cast<T const *>(byte);
}
int main()
{
    std::vector<char> byte;

    char c;
    while(std::cin >> c)
    {
        char b = (c - '0') << 7;
        for(int i = 6; i >= 0; --i)
        {
            std::cin >> c;
            b |= ((c - '0') << i);
        }
        byte.push_back(b);
    }

    bool any = false;

    char const *s = byte.data();
    char const * const end = s + byte.size();
    while(s != end)
    {
        //int const id = parse<int>(s);
        s += sizeof(int);
        char const * const name = s;
        s += std::strlen(name) + 1;
        float const eccentricity = parse<float>(s);
        s += sizeof(float);
        float const semimajor = parse<float>(s);
        s += sizeof(float);
        int const craters = parse<int>(s);
        s += sizeof(int);
        float const resources = parse<float>(s);
        s += sizeof(float);

        float const ae = 149597870700.f;
        bool const good = eccentricity < 0.2f
                       && semimajor >= 1.5f * ae
                       && semimajor <= 2.5f * ae
                       && craters < 100
                       && resources > 0.02f;
        if(good)
        {
            std::cout << name << ' ';
            any = true;
        }
    }
    if(false == any)
        std::cout << "nothing useful" << std::endl;
}
