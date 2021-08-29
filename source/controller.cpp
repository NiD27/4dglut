#include "../include/controller.h"
#include <iostream>
//controller::controller(hypercube *hc):

controller::controller():
default_rotation_angle(2.0), max_rotation_angle(1.0),
min_rotation_angle(20.0), rotation_step(1.0),
default_distance(2.0), min_distance(1.0), max_distance(10.0)
{
    rotation_angle = default_rotation_angle;
    //this->hc = hc;
    distance = default_distance;
    // matrix matx;
    // this->mat = matx;
}

void controller::keyboard_function(unsigned char k, int x, int y){
    controller::keymapper(k);
}

void controller::keymapper(unsigned char k){
    double degree = utils::deg_to_radians(rotation_angle);
    switch(k){
        //PITCH : YZ
        //pitch +
        case 'w':
            for(int i = 0; i < 16; i++)
                rotateYZ_4d(hc.hypercube4D[i], degree);
            break;
        // pitch -
        case 's':
            for(int i = 0; i < 16; i++)
                rotateYZ_4d(hc.hypercube4D[i], -degree);
            break;
        //ROLL XY
        //roll left (-) counter-clockwise
        case 'a':
            for(int i = 0; i < 16; i++)
                rotateXY_4d(hc.hypercube4D[i], -degree);
            break;
        //roll right (+) clockwise
        case 'd':
            for(int i = 0; i < 16; i++)
                rotateXY_4d(hc.hypercube4D[i], degree);
            break;
        //YAW XZ
        //yaw left +
        case 'q':
            for(int i = 0; i < 16; i++)
                rotateXZ_4d(hc.hypercube4D[i], degree);
            break;
        //yaw right -
        case 'e':
            for(int i = 0; i < 16; i++)
                rotateXZ_4d(hc.hypercube4D[i], -degree);
            break;
        //INTO THE 4D lol
        //XW +
        case 'W':
            for(int i = 0; i < 16; i++)
                rotateXW_4d(hc.hypercube4D[i], degree);
            break;
        // XW -
        case 'S':
            for(int i = 0; i < 16; i++)
                rotateXW_4d(hc.hypercube4D[i], -degree);
            break;
        //YW -
        case 'A':
            for(int i = 0; i < 16; i++)
                rotateYW_4d(hc.hypercube4D[i], -degree);
            break;
        //YW +
        case 'D':
            for(int i = 0; i < 16; i++)
                rotateYW_4d(hc.hypercube4D[i], degree);
            break;
        //ZW
        //ZW +
        case 'Q':
            for(int i = 0; i < 16; i++)
                rotateZW_4d(hc.hypercube4D[i], degree);
            break;
        //ZW -
        case 'E':
            for(int i = 0; i < 16; i++)
                rotateZW_4d(hc.hypercube4D[i], -degree);
            break;
        //ROTATION SPEEDS
        //increase rotation speed
        case '+':
            if(rotation_angle <= max_rotation_angle)
                rotation_angle += rotation_step;
            break;
        //decrease rotation speed
        case '-':
            if(rotation_angle >= min_rotation_angle)
                rotation_angle -= rotation_step;
            break;
    }
}

#define hypercube3D(x) hc.hypercube3D[x][0]<<hc.hypercube3D[x][1]<<hc.hypercube3D[x][2]
#define hypercube4D(x) hc.hypercube4D[x][0]<<hc.hypercube4D[x][1]<<hc.hypercube4D[x][2]<<hc.hypercube4D[x][3]
void controller::pipeline(){
    
    for(int i = 0; i < 16; i++){
        project_4Dto3D(hc.hypercube4D[i], hc.hypercube3D[i], distance);
    }
    
}