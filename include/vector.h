#ifndef VECTOR4
#define VECTOR4

#define xyzw(v) v.x,v.y,v.z,v.w
#define xyz(v) v.x,v.y,v.z

struct vec4{
    enum class Plane {XY = 0, XZ = 1, XW = 2, YZ = 3, YW = 4, ZW = 5};

    double x, y, z, w;
    vec4(const double, const double, const double, const double);
    vec4();

    void rotate(double, Plane);

};

struct vec3{
    enum class Plane {XY = 0, XZ = 1, YZ = 2};

    double x, y, z;
    vec3(const double, const double, const double);
    vec3();

    void rotate(double, Plane);

};

#endif