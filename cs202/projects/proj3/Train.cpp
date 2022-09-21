#include "Train.h"
#include <cstring>
#include <iomanip>


Train::Train(Route* metro){
    m_route = metro;
    m_head = new Car(0,1);
    m_totalCars = 1;

}

Train::~Train(){


    Car* temp = m_head;
    Car* next = NULL;
    while(temp != NULL){
        next = temp -> m_next;
        delete temp;
        temp = next;
    }

    
    
    while(temp != NULL){
        std::vector <Passenger*>:: iterator passengerNum = temp -> m_passengers.begin();
        while(passengerNum != temp-> m_passengers.end()){

            delete *passengerNum;
            temp -> m_passengers.erase(passengerNum);
        }    
    }
}
void Train::AddCar(){
    m_totalCars++;
 
    Car* temp = new Car(0,m_totalCars);
    cout<<"Current Car Is full - Adding Car "<<temp ->m_carNumber<<endl;
    
    
    
    temp-> m_next = NULL;
    if(m_head == NULL){

        m_head = temp;
        
    }
    else{
        Car* previous = nullptr;
        Car* curr = m_head;
        while(curr != NULL){
            previous = curr;
            curr = curr -> m_next;
        }
        previous -> m_next = temp;
        
    }
    
    
  
    
    
}

void Train::TrainStatus(){
    Car* temp = m_head;
    cout<<"Number of Cars: "<<m_totalCars<<endl;
    while(temp != NULL){

        cout<<"Car "<<temp -> m_carNumber<<": Number of Passengers: "<<temp -> m_capacity<<endl;
        temp  = temp -> m_next;
    }
    
    m_route -> PrintRouteDetails();
}


void Train::LoadPassengers(string passName){

    ifstream inputstream;
    string line, firstName, lastName, fullName,startLocation, endLocation;
    int age;
    int count = 0;
    inputstream.open(passName);
    while(getline(inputstream,line)){
        
        stringstream ss(line);
        getline(ss, firstName,',');
        getline(ss,lastName,',');
        fullName = firstName + " " + lastName;
        getline(ss,startLocation,',');
        age = std::stoi(startLocation);
        getline(ss, startLocation,',');
        getline(ss,endLocation,'\n');
      
        
       
        if(startLocation.compare(m_route -> GetCurrentStop() -> GetName()) == 0){
            
            Passenger* temp = new Passenger(fullName, age, startLocation, endLocation);
            BoardPassenger(temp);
            count++;
            
        }
        

       
    }
    cout<<"Boarded "<<count<< " passengers."<<endl;
    inputstream.close();
}


void Train::BoardPassenger(Passenger* person){
    Car* temp = m_head;
    
    if(IsTrainFull() == true){
        
        AddCar();
        cout<<person->GetName()<< " Boards the train (Destination: "<<person->GetFinalDestination()<<")"<<endl;
        while (temp -> m_next != NULL) {
            temp = temp->m_next;
        }
        temp -> AddPassenger(person);
        temp -> m_capacity++;
        
        
    }
    else{
        
        while(temp != NULL){

            if(temp -> m_capacity != CAR_CAPACITY){
                cout<<person->GetName()<< " Boards the train (Destination: "<<person->GetFinalDestination()<<")"<<endl;
                temp -> AddPassenger(person);
                temp -> m_capacity++;
                
                
                
            }
            
            temp = temp -> m_next;
        }
        

        
    }
    
    
}


void Train::DisembarkPassengers(){

    Car* temp = m_head;
    int disembarked = 0;

    while(temp != NULL){
        std::vector <Passenger*>:: iterator passengerNum = temp -> m_passengers.begin();
        while(passengerNum != temp-> m_passengers.end()){
          
            if((*passengerNum) -> GetFinalDestination().compare(m_route -> GetCurrentStop() -> GetName()) == 0  ){
                disembarked++;
                temp ->m_capacity--;
                cout<<(*passengerNum) ->GetName()<<" Disembark the train (Destination: "<<(*passengerNum) -> GetFinalDestination()<<")"<<endl;
                delete *passengerNum;
                temp -> m_passengers.erase(passengerNum);
                
            }
            passengerNum++;
            
        }
        temp = temp -> m_next;
            
        
    }
    cout<<disembarked<<" passengers disembarked"<<endl;

    
}



void Train::TravelToNextStop(){
    
    if(m_route -> GetCurrentStop() -> GetNextStop() == NULL){

        cout<<"You reached the end you should probably turn around."<<endl;

    }
    else{

        m_route -> SetCurrentStop(m_route -> GetCurrentStop() -> GetNextStop());
        cout<<"Arriving at "<<m_route -> GetCurrentStop() -> GetName()<<endl;
    }
}


void Train::TurnTrainAround(){

    if(m_route -> GetCurrentStop() -> GetNumber() == 30 || m_route -> GetCurrentStop() -> GetNumber() == 1){

        m_route -> ReverseRoute();
    }
    else{
        cout<<"You havn't reached the end of the route"<<endl;
    }
}



bool Train::IsTrainFull(){

    
    Car* temp = m_head;
    bool full;

    while(temp != NULL){
        if(temp -> m_capacity == CAR_CAPACITY){
            full = true;
        }
        else{
            full = false;
        }

        temp = temp -> m_next; 
    }

    return full;
}