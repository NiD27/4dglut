#include "../include/matrix.h"

//4D to 3D projection
void matrix::project_4Dto3D(double *vec4, double *vec3, double distance){
    //STEREOGRAPHIC PROJECTION

	double s = 1/(distance - vec4[3]);
    	double pm[3][4] = {
        {s, 0.0, 0.0, 0.0},
        {0.0, s, 0.0, 0.0},
        {0.0, 0.0, s, 0.0}
    };

    //REGULAR PROJECTION
    // double pm[3][4] = {
    //     {1.0, 0.0, 0.0, 0.0},
    //     {0.0, 1.0, 0.0, 0.0},
    //     {0.0, 0.0, 1.0, 0.0}
    // };

    double sum[3] = {0.0, 0.0, 0.0};
    for(int i = 0; i < 3; i++){
        sum[i] = 0.0;
        for(int j = 0; j < 4; j++)
            sum[i] += pm[i][j] * vec4[j];
    }
    vec3[0] = sum[0]; vec3[1] = sum[1]; vec3[2] = sum[2];
}

//3D rotations
void matrix::rotateX_3d(double *vec3, double angle){
	double rotateX_3d_mat[3][3] = {
	{1.0, 0.0, 0.0},
	{0.0, cos(angle), -sin(angle)},
	{0.0, sin(angle), cos(angle)}
	};

	double sum[3]={0.0, 0.0, 0.0};
	for(int i = 0; i < 3; i++){
		sum[i] = 0.0;
		for(int j = 0; j < 3; j++)
			sum[i] += rotateX_3d_mat[i][j] * vec3[j];
	}
	vec3[0] = sum[0]; vec3[1] = sum[1]; vec3[2] = sum[2];
}

void matrix::rotateY_3d(double *vec3, double angle){
	double rotateY_3d_mat[3][3] = {
	{cos(angle), 0.0, sin(angle)},
	{0.0, 1.0, 0.0},
	{-sin(angle), 0.0, cos(angle)}
	};

	double sum[3]={0.0, 0.0, 0.0};
	for(int i = 0; i < 3; i++){
		sum[i] = 0.0;
		for(int j = 0; j < 3; j++)
			sum[i] += rotateY_3d_mat[i][j] * vec3[j];
	}
	vec3[0] = sum[0]; vec3[1] = sum[1]; vec3[2] = sum[2];
}

void matrix::rotateZ_3d(double *vec3, double angle){
	double rotateZ_3d_mat[3][3] = {
	{cos(angle), -sin(angle), 0.0},
	{sin(angle), cos(angle), 0.0},
	{0.0, 0.0, 1.0}
	};

	double sum[3]={0.0, 0.0, 0.0};
	for(int i = 0; i < 3; i++){
		sum[i] = 0.0;
		for(int j = 0; j < 3; j++)
			sum[i] += rotateZ_3d_mat[i][j] * vec3[j];
	}
	vec3[0] = sum[0]; vec3[1] = sum[1]; vec3[2] = sum[2];
}

//4D rotations
void matrix::rotateXY_4d(double *vec4, double angle){
	double rotateXY_4d_mat[4][4] = {
		{cos(angle), sin(angle), 0, 0},
		{-sin(angle), cos(angle), 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
	double sum[4];
	for(int i = 0; i < 4; i++){
		sum[i] = 0.0;
		for(int j = 0; j < 4; j++)
			sum[i] += rotateXY_4d_mat[i][j] * vec4[j];
	}
	vec4[0] = sum[0]; vec4[1] = sum[1]; vec4[2] = sum[2]; vec4[3] = sum[3];
}

void matrix::rotateYZ_4d(double *vec4, double angle){
	double rotateYZ_4d_mat[4][4] = {
		{1, 0, 0, 0},
		{0, cos(angle), sin(angle), 0},
		{0, -sin(angle), cos(angle), 0},
		{0, 0, 0, 1}
	};
	double sum[4];
	for(int i = 0; i < 4; i++){
		sum[i] = 0.0;
		for(int j = 0; j < 4; j++)
			sum[i] += rotateYZ_4d_mat[i][j] * vec4[j];
	}
	vec4[0] = sum[0]; vec4[1] = sum[1]; vec4[2] = sum[2]; vec4[3] = sum[3];
}

void matrix::rotateXZ_4d(double *vec4, double angle){
	double rotateXZ_4d_mat[4][4] = {
		{cos(angle), 0, -sin(angle), 0},
		{0, 1, 0, 0},
		{sin(angle), 0, cos(angle), 0},
		{0, 0, 0, 1}
	};
	double sum[4];
	for(int i = 0; i < 4; i++){
		sum[i] = 0.0;
		for(int j = 0; j < 4; j++)
			sum[i] += rotateXZ_4d_mat[i][j] * vec4[j];
	}
	vec4[0] = sum[0]; vec4[1] = sum[1]; vec4[2] = sum[2]; vec4[3] = sum[3];
}

void matrix::rotateXW_4d(double *vec4, double angle){
	double rotateXW_4d_mat[4][4] = {
		{cos(angle), 0, 0, sin(angle)},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{-sin(angle), 0, 0, cos(angle)}
	};
	double sum[4];
	for(int i = 0; i < 4; i++){
		sum[i] = 0.0;
		for(int j = 0; j < 4; j++)
			sum[i] += rotateXW_4d_mat[i][j] * vec4[j];
	}
	vec4[0] = sum[0]; vec4[1] = sum[1]; vec4[2] = sum[2]; vec4[3] = sum[3];
}

void matrix::rotateYW_4d(double *vec4, double angle){
	double rotateYW_4d_mat[4][4] = {
		{1, 0, 0, 0},
		{0, cos(angle), 0, -sin(angle)},
		{0, 0, 1, 0},
		{0, sin(angle), 0, cos(angle)}
	};
	double sum[4];
	for(int i = 0; i < 4; i++){
		sum[i] = 0.0;
		for(int j = 0; j < 4; j++)
			sum[i] += rotateYW_4d_mat[i][j] * vec4[j];
	}
	vec4[0] = sum[0]; vec4[1] = sum[1]; vec4[2] = sum[2]; vec4[3] = sum[3];
}

void matrix::rotateZW_4d(double *vec4, double angle){
	double rotateZW_4d_mat[4][4] = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, cos(angle), -sin(angle)},
		{0, 0, sin(angle), cos(angle)}
	};
	double sum[4];
	for(int i = 0; i < 4; i++){
		sum[i] = 0.0;
		for(int j = 0; j < 4; j++)
			sum[i] += rotateZW_4d_mat[i][j] * vec4[j];
	}
	vec4[0] = sum[0]; vec4[1] = sum[1]; vec4[2] = sum[2]; vec4[3] = sum[3];
}
