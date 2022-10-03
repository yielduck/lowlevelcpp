namespace my
{

double powi(double const x, int const a)
{
    if(a == 0)
        return 1.;
    if(a < 0)
        return powi(1. / x, -a);
    if(a % 2 == 0)
        return powi(x * x, a / 2);
    else
        return x * powi(x, a - 1);
}

} // namespace my
