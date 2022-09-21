#include "Passenger.h"


Passenger::Passenger(string name, int age, string start, string end){

    m_fullName = name;
    m_age = age;
    m_startLocation = start;
    m_finalDestination = end;

}


string Passenger::GetName(){

    return m_fullName;
}


string Passenger::GetStartLocation(){
    return m_startLocation;
}

string Passenger::GetFinalDestination(){

    return m_finalDestination;
}