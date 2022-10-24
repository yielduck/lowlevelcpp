unsigned long long primorial(int n)
{
    unsigned long long const N = n;
    unsigned long long const primes[] =
    {
         2,  3,  5,  7, 11,
        13, 17, 19, 23, 29,
        31, 37, 41, 43, 47,
    };

    unsigned long long result = 1;
    for(int i = 0; i < 15; ++i)
        if(primes[i] <= N)
            result *= primes[i];

    return result;
}
