double pow(double const x, int const a)
{
    if(a == 0)
        return 1.;
    if(a < 0)
        return pow(1. / x, -a);
    if(a % 2 == 0)
        return pow(x * x, a / 2);
    else
        return x * pow(x, a - 1);
}
