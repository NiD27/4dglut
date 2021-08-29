#ifndef UTILS
#define UTILS

#define PI 3.1415926535897932

#define RED     1.0,0.0,0.0
#define GREEN   0.0,1.0,0.0
#define BLUE    0.0,0.0,1.0
#define YELLOW  1.0,1.0,0.0
#define CYAN    0.0,1.0,1.0
#define PINK    1.0,0.0,1.0
#define WHITE   1.0,1.0,1.0
#define COLOR(color) color

class utils{
    private:

    public:
    static double deg_to_radians(double degree);
};

#endif