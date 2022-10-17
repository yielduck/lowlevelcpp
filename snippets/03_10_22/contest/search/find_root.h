inline double findRoot(Segment s, F const f)
{
    bool const ascending = f(s.begin) < 0.;
    double const precision = 1e-6;
    while(s.end - s.begin > precision)
    {
        double const mid = (s.begin + s.end) * 0.5;
        s = (f(mid) < 0.) != ascending
            ? Segment{s.begin, mid}
            : Segment{mid, s.end};
    }
    return (s.begin + s.end) * 0.5;
}
