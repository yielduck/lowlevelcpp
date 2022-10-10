mat3 transpose(mat3 const m)
{
    return
    {
        {m.x.x, m.y.x, m.z.x},
        {m.x.y, m.y.y, m.z.y},
        {m.x.z, m.y.z, m.z.z},
    };
}
