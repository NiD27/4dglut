#ifndef HYPERCUBE
#define HYPERCUBE

#include "./matrix.h"

class hypercube{

        const double default_hypercube4D[16][4];
        const double default_hypercube3D[16][3];
        public:
        double hypercube4D[16][4];
		double hypercube3D[16][3];

        hypercube();

};

#endif