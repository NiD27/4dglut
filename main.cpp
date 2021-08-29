#include <GL/glut.h>
#include "include/controller.h"


//!THE MEMBER ACCESS THING
controller ctrl;


void main_display_hypercube();
void main_keyboard_relay(unsigned char k, int x, int y);
void main_idle();

int main(int argc, char **argv){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutCreateWindow("4D VISUALIZER");

    ctrl.initialize_renderer();
 	glutDisplayFunc(main_display_hypercube);
    glutKeyboardFunc(main_keyboard_relay);
	glutIdleFunc(main_idle);

	glutMainLoop();

    return 0;
}

void main_display_hypercube(){
    ctrl.display_hypercube();
}

void main_keyboard_relay(unsigned char k, int x, int y){
    ctrl.keyboard_function(k, x, y);
}



void main_idle(){
    ctrl.idle();
}