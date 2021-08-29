#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <unistd.h>

#define PI 3.1415926535897932

const double default_rotation_angle= 2.0, max_rotation_angle = 20.0, min_rotation_angle = 1.0, rotation_step = 1.0;
double rotation_angle = default_rotation_angle;

const double default_distance = 1.5, min_distance = 1.5, max_distance = 4.0, distance_step = 0.1;
double distance = default_distance;

float color[8][3] = {
	{1.0, 0.0, 0.0},//RED
	{0.0, 1.0, 0.0},//BLUE
	{0.0, 0.0, 1.0},//GREEN
	{1.0, 1.0, 1.0} //WHITE
};

double hypercube[16][4] = {
	{+1, +1, +1, +1},
	{-1, +1, +1, +1},
	{+1, -1, +1, +1},
	{-1, -1, +1, +1},
	
	{+1, +1, -1, +1},
	{-1, +1, -1, +1},
	{+1, -1, -1, +1},
	{-1, -1, -1, +1},
	
	{+1, +1, +1, -1},
	{-1, +1, +1, -1},
	{+1, -1, +1, -1},
	{-1, -1, +1, -1},
	
	{+1, +1, -1, -1},
	{-1, +1, -1, -1},
	{+1, -1, -1, -1},
	{-1, -1, -1, -1}
	
};

double cube[8][3] = {
    {+1, +1, +1},
	{-1, +1, +1},
	{+1, -1, +1},
	{-1, -1, +1},

	{+1, +1, -1},
	{-1, +1, -1},
	{+1, -1, -1},
	{-1, -1, -1}
};

double projected_cube[16][3] = {
    {+1, +1, +1},
	{-1, +1, +1},
	{+1, -1, +1},
	{-1, -1, +1},

	{+1, +1, +1},
	{-1, +1, +1},
	{+1, -1, +1},
	{-1, -1, +1},

	{+1, +1, -1},
	{-1, +1, -1},
	{+1, -1, -1},
	{-1, -1, -1},

	{+1, +1, -1},
	{-1, +1, -1},
	{+1, -1, -1},
	{-1, -1, -1}
};

double deg_to_radians(double deg){
	return (deg*(PI/180.0));
}

int mod(int current, int size){
	return current%size;
}

void project_3d(double *vec4, double *vec3, double distance){
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

//* 3D ROTATIONS
void rotateX_3d(double *vec3, double angle){
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

void rotateY_3d(double *vec3, double angle){
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

void rotateZ_3d(double *vec3, double angle){
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

//* 4D ROTATIONS
void rotateXY_4d(double *vec4, double angle){
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

void rotateYZ_4d(double *vec4, double angle){
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

void rotateXZ_4d(double *vec4, double angle){
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

void rotateXW_4d(double *vec4, double angle){
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

void rotateYW_4d(double *vec4, double angle){
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

void rotateZW_4d(double *vec4, double angle){
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

#define hypercube(x) hypercube[x][0],hypercube[x][1],hypercube[x][2],hypercube[x][3]
#define cube(x) cube[x][0],cube[x][1],cube[x][2]
#define projected_cube(x) projected_cube[x][0],projected_cube[x][1],projected_cube[x][2]
#define color(x) color[x][0],color[x][1],color[x][2]

//CONTROLS

void controller(unsigned char k, int degree){
    switch(k){
        //PITCH : YZ
        //pitch +
        case 'w':
            for(int i = 0; i < 16; i++)
                rotateYZ_4d(hypercube[i], deg_to_radians(degree));
            break;
        // pitch -
        case 's':
            for(int i = 0; i < 16; i++)
                rotateYZ_4d(hypercube[i], deg_to_radians(-degree));
            break;
        //ROLL XY
        //roll left (-) counter-clockwise
        case 'a':
            for(int i = 0; i < 16; i++)
                rotateXY_4d(hypercube[i], deg_to_radians(-degree));
            break;
        //roll right (+) clockwise
        case 'd':
            for(int i = 0; i < 16; i++)
                rotateXY_4d(hypercube[i], deg_to_radians(degree));
            break;
        //YAW XZ
        //yaw left +
        case 'q':
            for(int i = 0; i < 16; i++)
                rotateXZ_4d(hypercube[i], deg_to_radians(degree));
            break;
        //yaw right -
        case 'e':
            for(int i = 0; i < 16; i++)
                rotateXZ_4d(hypercube[i], deg_to_radians(-degree));
            break;
        //INTO THE 4D lol
        //XW +
        case 'W':
            for(int i = 0; i < 16; i++)
                rotateXW_4d(hypercube[i], deg_to_radians(degree));
            break;
        // XW -
        case 'S':
            for(int i = 0; i < 16; i++)
                rotateXW_4d(hypercube[i], deg_to_radians(-degree));
            break;
        //YW -
        case 'A':
            for(int i = 0; i < 16; i++)
                rotateYW_4d(hypercube[i], deg_to_radians(-degree));
            break;
        //YW +
        case 'D':
            for(int i = 0; i < 16; i++)
                rotateYW_4d(hypercube[i], deg_to_radians(degree));
            break;
        //ZW
        //ZW +
        case 'Q':
            for(int i = 0; i < 16; i++)
                rotateZW_4d(hypercube[i], deg_to_radians(degree));
            break;
        //ZW -
        case 'E':
            for(int i = 0; i < 16; i++)
                rotateZW_4d(hypercube[i], deg_to_radians(-degree));
            break;
		//ROTATION SPEEDS
        //increase rotation speed
        case '+':
            if(rotation_angle < max_rotation_angle)
                rotation_angle += rotation_step;
            break;
        //decrease rotation speed
        case '-':
            if(rotation_angle > min_rotation_angle)
                rotation_angle -= rotation_step;
            break;
		case '>':
        	if(distance < max_distance)
                distance += distance_step;
        	break;
        //decrease rotation speed
        case '<':
            if(distance > min_distance)
                distance -= distance_step;
        	break;  
    }
}

void keyboard_function(unsigned char k, int x, int y){
    controller(k, rotation_angle);
}

void pipeline(){
	for(int i = 0; i < 16; i++){
		//rotateXY_4d(hypercube[i], deg_to_radians(1));
		//rotateYZ_4d(hypercube[i], deg_to_radians(1));
		//rotateXZ_4d(hypercube[i], deg_to_radians(1));
		// rotateXW_4d(hypercube[i], deg_to_radians(1));
		// rotateYW_4d(hypercube[i], deg_to_radians(1));
		//rotateZW_4d(hypercube[i], deg_to_radians(1));
		
		project_3d(hypercube[i], projected_cube[i], distance);

		//rotateX_3d(projected_cube[i], deg_to_radians(50));
		//rotateY_3d(projected_cube[i], deg_to_radians(50));
        //rotateZ_3d(projected_cube[i], deg_to_radians(50));
	}
}

void display_4d(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glBegin(GL_POINTS);
		for(int x =0; x < 16; x++){
			glColor3f(color(3));
			glVertex3d(projected_cube(x));
		}
	glEnd();
	//X DELTA RENDERER
	glBegin(GL_LINES);
		for(int offset = 0; offset < 16; offset +=4)
			for(int x = offset; x < offset+3; x+=2){
				glColor3f(color(0));
				glVertex3d(projected_cube(x));
				glVertex3d(projected_cube(x+1));
			}
	glEnd();
	//Y DELTA RENDERER
	glBegin(GL_LINES);
		for(int offset = 0; offset < 16; offset +=4)
			for(int x = offset; x < offset+2; x++){
				glColor3f(color(1));
				glVertex3d(projected_cube(x));
				glVertex3d(projected_cube(x+2));
			}
	//Z DELTA RENDERER
	glBegin(GL_LINES);
		for(int offset = 0; offset < 16; offset +=8)
			for(int x = offset; x < offset+4; x++){
				glColor3f(color(2));
				glVertex3d(projected_cube(x));
				glVertex3d(projected_cube(x+4));
			}
	glEnd();
	//W DELTA RENDERER
	glBegin(GL_LINES);
		for(int x = 0; x < 8; x++){
			glColor3f(color(3));
			glVertex3d(projected_cube(x));
			glVertex3d(projected_cube(x+8));
		}
	glEnd();
	glPopMatrix();

	glPushMatrix();
		glBegin(GL_LINES);
			//glColor3f(1.0, 0.0, 0.0);
			glColor3f(color(0));
            glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 0.0);
		glEnd();
		glBegin(GL_LINES);
			//glColor3f(1.0, 0.0, 0.0);
			glColor3f(color(1));
            glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 3.0, 0.0);
		glEnd();
        glBegin(GL_LINES);
			//glColor3f(1.0, 0.0, 0.0);
			glColor3f(color(2));
            glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 0.0, -3.0);
		glEnd();
	glPopMatrix();

	glFlush();
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
		glBegin(GL_LINES);
		for(int x =0; x < 4; x++){
				int next = mod(x+1, 4);
				// glColor3f(1.0, 0.0, 0.0);
				glColor3f(color(0));
				glVertex3d(cube(x));
				glVertex3d(cube(next));
		}
		glEnd();
		glBegin(GL_LINES);
		for(int x =4; x < 8; x++){
				int next = mod(x+1, 8);
				if(x+1 == 8)
					next = 4;
				// glColor3f(1.0, 0.0, 0.0);
				glColor3f(color(1));
				glVertex3d(cube(x));
				glVertex3d(cube(next));
			}
		glEnd();
		glBegin(GL_LINES);
		for(int x =0; x < 4; x++){
				// glColor3f(1.0, 0.0, 0.0);
				glColor3f(color(2));
				glVertex3d(cube(x));
				glVertex3d(cube(x+4));
			}
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glBegin(GL_LINES);
			//glColor3f(1.0, 0.0, 0.0);
			glColor3f(color(3));
            glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(2.0, 0.0, 0.0);
		glEnd();
		glBegin(GL_LINES);
			//glColor3f(1.0, 0.0, 0.0);
			glColor3f(color(3));
            glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 2.0, 0.0);
		glEnd();
        glBegin(GL_LINES);
			//glColor3f(1.0, 0.0, 0.0);
			glColor3f(color(3));
            glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 0.0, 2.0);
		glEnd();
	glPopMatrix();

	glFlush();
}

void idle()
{	
	pipeline();
	//Sleep(33);
	//usleep is a sleep function for unix systems and is not portable
	//accepts microseconds ie 1 millisecond = 1000 microsecond
	usleep(33*1000);
	glutPostRedisplay();
}

void init(){

    glEnable(GL_DEPTH_TEST);
    glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3.0, 3.0, -3.0, 3.0, -5.0, 5.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(-0.3, 0.2, 0.14, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0);

	glRotatef(-90, 0, 1, 0);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutCreateWindow("4D VISUALIZER");

    init();
	glutDisplayFunc(display_4d);
    glutKeyboardFunc(keyboard_function);
	glutIdleFunc(idle);
	
	glutMainLoop();

	return 0;
}