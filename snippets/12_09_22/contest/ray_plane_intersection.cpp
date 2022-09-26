vec3 operator+(vec3 const v1, vec3 const v2)
{
    return
    {
        v1.x + v2.x,
        v1.y + v2.y,
        v1.z + v2.z,
    };
}
vec3 operator-(vec3 const v1, vec3 const v2)
{
    return
    {
        v1.x - v2.x,
        v1.y - v2.y,
        v1.z - v2.z,
    };
}
vec3 operator*(vec3 const v, float const f)
{
    return
    {
        v.x * f,
        v.y * f,
        v.z * f,
    };
}
float dot(vec3 const v1, vec3 const v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
vec3 rayPlaneIntersection(Ray const ray, Plane const plane)
{
    float const t = dot(plane.point - ray.origin, plane.norm)
                  / dot(           ray.direction, plane.norm);
    return ray.origin + ray.direction * t;
}
