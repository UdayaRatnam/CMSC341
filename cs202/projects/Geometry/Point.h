#ifndef POINT_H
#define POINT_H






class Point{


    public:
        Point(double x, double y);
        void SetX(double x);
        void SetY(double y);
        double GetX();
        double GetY();
    protected:
        double m_xCoordinate;
        double m_yCoordinate;

};

#endif

