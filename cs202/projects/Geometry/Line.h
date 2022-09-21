#ifndef LINE_H
#define LINE_H
#include "Point.h"
#include <cmath>

class Line: public Point{

    public:
        Line(double x1,double y1, double x2,double y2);
        

    protected:
        
        double x1,y1,x2,y2;
        
       

        
};

#endif
