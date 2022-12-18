void getStats
(
    Pilot* pilots,
    unsigned int n,
    double deviation_rate,
    unsigned int* n_average_total,
    unsigned int* n_average_by_measurements
)
{
    *n_average_total = 0;
    double avg[N_MEASUREMENTS] = {};
    for(unsigned int m = 0; m < N_MEASUREMENTS; ++m)
    {
        n_average_by_measurements[m] = 0;
        avg[m] = 0.;
        for(unsigned int i = 0; i < n; ++i)
            avg[m] += pilots[i].measurements[m] / n;
    }
    for(unsigned int i = 0; i < n; ++i)
    {
        bool good = true;
        for(unsigned int m = 0; m < N_MEASUREMENTS; ++m)
        {
            if(std::abs(avg[m] - pilots[i].measurements[m]) < deviation_rate * avg[m])
                n_average_by_measurements[m]++;
            else
                good = false;
        }
        if(good)
            *n_average_total += 1;
    }
}
