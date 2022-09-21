#include "Route.h"
#include <iomanip>




Route::Route(){
    m_head = nullptr;
    m_tail = nullptr;
    m_currentStop = nullptr;
    m_totalStops = 0;
    
}

Route::~Route(){

    Stop* m_currentStop = m_head;
    while(m_currentStop != NULL){
        Stop* next = m_currentStop->GetNextStop();
        delete m_currentStop;
        m_currentStop = next;
        m_totalStops = 0;
    }
    m_head = NULL;
    m_tail = NULL;
    
}


void Route::LoadRoute(string fileName){
    string line, stopName,temp;
    int stopNumber;
    ifstream inputstream;
    cout<<fileName<<endl;
    inputstream.open(fileName);
    while(getline(inputstream, line)){
        stringstream ss(line);
        getline(ss,stopName,',');
        getline(ss,temp,'\n');
        stopNumber = std::stoi(temp);
        AddStop(stopName,stopNumber);
       
    }
   

    m_currentStop = m_head;
    inputstream.close();
}


void Route::AddStop(string name, int stop){
    Stop* temp = new Stop(name,stop);
    temp->SetNextStop(nullptr);
    
    m_totalStops++; 

    if(m_head == nullptr){
        m_tail = temp;
        m_head = temp;
        
    }
    else{
        m_tail->SetNextStop(temp);
        m_tail = m_tail -> GetNextStop();
    }
    
    
}


void Route::PrintRouteDetails(){

    cout<<"Current Stop: "<<GetCurrentStop() -> GetName()<<" ("<<m_currentStop -> GetNumber()<<")"<<endl;
    cout<<"Next Stop is: "<<m_currentStop->GetNextStop() -> GetName()<<" ("<<m_currentStop -> GetNextStop() -> GetNumber()<<")"<<endl;

}

Stop* Route::GetCurrentStop(){

    return m_currentStop;
}

void Route::SetCurrentStop(Stop* curr){

    m_currentStop = curr;
}


void Route::ReverseRoute(){
    
    Stop* current = m_head;
    Stop* previous = nullptr;
    Stop* temp = nullptr;

    while(current != nullptr){
        temp = current -> GetNextStop();
        current -> SetNextStop(previous);
        previous = current;
        current = temp;
    }
    m_head = previous;


    

}

