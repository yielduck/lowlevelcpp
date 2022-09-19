double pow(double x, int a)
{
    if(a < 0)
    {
        x = 1. / x;
        a = -a;
    }

    double accum = 1.;
    while(a != 0)
    {
        if(a % 2 == 0)
        {
            x *= x;
            a /= 2;
        }
        else
        {
            accum *= x;
            a -= 1;
        }
    }
    return accum;
}
