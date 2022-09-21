
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "Passenger.h"
using namespace std;



int main(){


    ifstream inputstream;
    string line, firstName, lastName, fullName,startLocation, endLocation;
    int age;
    inputstream.open("proj3_passengers.csv");
    while(getline(inputstream,line)){
        stringstream ss(line);
        getline(ss, firstName,',');
        getline(ss,lastName,',');
        fullName = firstName + " " + lastName;
        getline(ss,startLocation,',');
        age = std::stoi(startLocation);
        getline(ss, startLocation,',');
        getline(ss,endLocation,'\n');
          
        if(startLocation.compare("dummy_string") != 0){

            //Passenger* temp = new Passenger(fullName, age, startLocation, endLocation);
            //BoardPassenger(temp);
            cout<<"Is equal"<<endl;
        }
        
    
       //cout<<firstName<<endl;
       //cout<<startLocation<<endl;
    }


}