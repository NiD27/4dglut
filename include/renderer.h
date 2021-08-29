#ifndef RENDERER
#define RENDERER

#include <GL/glut.h>
#include <unistd.h>

#include "hypercube.h"
#include "controller.h"

#define hypercube3D(x) hc.hypercube3D[x][0],hc.hypercube3D[x][1],hc.hypercube3D[x][2]

class renderer{
    private:
        hypercube hc;
        controller *ctrl;
    public:
        renderer();

        void initialize_renderer();
        void keyboard_relay(unsigned char k, int x, int y);
        void display_hypercube();
        void idle();

};

#endif