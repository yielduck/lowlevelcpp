mat3 operator*(mat3 const m1, mat3 const m2)
{
    mat3 m;
    for(int i = 0; i < 3; ++i)
    for(int j = 0; j < 3; ++j)
        m[i][j] = m1[i][0] * m2[0][j]
                + m1[i][1] * m2[1][j]
                + m1[i][2] * m2[2][j];
    return m;
}
