#include "Point.h"


Point::Point(double x, double y){
    SetX(x);
    SetY(y);

}

void Point::SetX(double x){

    m_xCoordinate = x;
}

void Point::SetY(double y){
    m_yCoordinate = y;

}

double Point::GetX(){
    return m_xCoordinate;
}

double Point::GetY(){

    return m_yCoordinate;
}