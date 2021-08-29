#ifndef MATRIX
#define MATRIX

#include <math.h>

class matrix{
    private:

    public:
        //4D to 3D projection
        void project_4Dto3D(double *vec4, double *vec3, double distance);

        //3D rotations
        void rotateX_3d(double *vec3, double angle);
        void rotateY_3d(double *vec3, double angle);
        void rotateZ_3d(double *vec3, double angle);

        //4D rotations
        void rotateXY_4d(double *vec4, double angle);
        void rotateYZ_4d(double *vec4, double angle);
        void rotateXZ_4d(double *vec4, double angle);
        void rotateXW_4d(double *vec4, double angle);
        void rotateYW_4d(double *vec4, double angle);
        void rotateZW_4d(double *vec4, double angle);
        
};

#endif