float dot(vec3 const v1, vec3 const v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
vec3 operator*(mat3 const m, vec3 const v)
{
    return
    {
        dot(m.x, v),
        dot(m.y, v),
        dot(m.z, v),
    };
}
