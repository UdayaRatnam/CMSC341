#include "Stop.cpp"
#include <iostream>

using namespace std;
void printList(Stop*);

int main(){



    Stop* ptr1 = new Stop("stop 1", 1);
    Stop* ptr2 = new Stop("stop 2", 2);
    Stop* ptr3 = new Stop("stop 3", 3);
    Stop* ptr4 = new Stop("stop 4", 4);

    
    ptr1 -> SetNextStop(ptr2);
    ptr2 -> SetNextStop(ptr3);
    ptr3->SetNextStop(ptr4);
    ptr4 -> SetNextStop(NULL);
    printList(ptr1);
    /*
    Stop* current = ptr1;                                 // a, b, c, d ; a -> b -> c -> d;   d -> c -> b -> a 
    Stop* temp = nullptr;
    Stop* reverse_stops = nullptr;
    Stop* stops[4];
    
    int i = 0;
    while(current != NULL){
        stops[i++] = current;
        current = current -> GetNextStop();
    }

    for (i=3; i>0; i--) {
        temp = stops[i] -> GetNextStop();
        stops[i] -> SetNextStop(stops[i-1]);

    }
    stops[3] -> SetNextStop(nullptr);
    cout<< " END OF Revers" <<endl;
    
    printList(stops[0]);
    */
   Stop* current = ptr1;
   Stop* prev = nullptr;
   Stop* temp = nullptr;

   while(current != nullptr){

       temp = current -> GetNextStop();
       current -> SetNextStop(prev);
       prev = current;
       current = temp;

   }
   ptr1 = prev;

   printList(ptr1);


}

void printList(Stop* begin){

    Stop* temp = NULL;
    temp = begin;

    while(temp != NULL){

        cout<<temp -> GetNumber()<<endl;
        temp = temp -> GetNextStop();
    }


}