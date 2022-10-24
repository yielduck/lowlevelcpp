void message(int y, int x, int l)
{
    char str[51];
    str[0] = ouija[y][x];
    for(int i = 1; i < l; ++i)
    {
        int dy, dx;
        std::cin >> dy >> dx;

        y += dy;
        x += dx;
        if(x < 0 || x > 12 ||
           y < 0 || y >  2  )
        {
            std::cout << "THE SPIRITS ARE RESTLESS" << std::endl;
            return;
        }

        str[i] = ouija[y][x];
    }
    str[l] = '\0';
    std::cout << str << std::endl;
}
