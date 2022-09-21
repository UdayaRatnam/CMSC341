#include <iostream>

using namespace std;

class Node{


    public:
        int data;
        Node* next;

};

void printList(Node* num){

    while(num != NULL){
        cout<<num -> data<<endl;
        num = num -> next;
    }
}
int main(){

    Node* begin = NULL;
    int number;
    Node* previous = NULL;
    while(true){

        cout<<"Enter a number: "<<endl;
        cin >> number;

        if(number == -1){

            break;
        }
        else{
            Node* next = new Node();
            next -> data = number;
            next -> next = NULL;
            if(begin == NULL){
                begin = next;
            }
            else{
                previous -> next = next;
                
            }
            previous = next;
        }
        
    }

    previous = begin;

    printList(previous);
    
    
    
    
    

}