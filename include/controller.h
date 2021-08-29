#ifndef CONTROLLER
#define CONTROLLER

#include "utils.h"
#include "hypercube.h"

class controller: public matrix{
    private:
        const double default_rotation_angle, default_distance;
        const double min_rotation_angle, max_rotation_angle, rotation_step;
        const double min_distance, max_distance;
        double rotation_angle;
        double distance;
        //hypercube *hc;
        hypercube hc;
        //matrix mat;
    public:
        //controller(hypercube *hc);
        controller();
        void keyboard_function(unsigned char k, int x, int y);
        void keymapper(unsigned char k);
        void pipeline();
};

#endif