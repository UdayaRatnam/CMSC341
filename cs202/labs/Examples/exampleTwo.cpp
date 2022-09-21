#include <iostream>
using namespace std;

struct Node{


    public:
        int data;
        Node* m_next;

};
/**
class LinkedList(){

    public:
        LinkedList();
        void InsertBegin(int num);
        void Display();
    private:
        Node* m_head;
        Node* m_tail;
        int m_size;
};


LinkedList::LinkedList(){
    m_head = NULL;
    m_tail = NULL;
    m_size = 0;

}

void LinkedList::InsertBegin(int num){
    Node* temp = new Node();
    temp -> m_next = m_head;
    m_head =  temp;
    temp -> data = num;
    m_size++;

}

void LinkedList::Display(){

    Node* temp = m_head;
    for(int i = 0; i < m_size; i++){

        cout<<temp -> data<<"->";
        temp = temp -> m_next;

    }
    cout<<"End of Linked List"<<endl;

}

*/






int main(){


    Node* begin = NULL;
    Node* previous = NULL;
    Node* current = NULL;
    int number;
    int nodeCounter = 0;
    int input;

    while(true){


        cout<<"Enter a number: "<<endl;
        cin >> number;

        if(number == -1){

            break;
        }
        else{

            Node* current = new Node();
            nodeCounter++;
            current -> data = number;
            current -> m_next = NULL;
            if(begin == NULL){
                begin = current;
            }
            else{
                previous -> m_next = current;

            }
            previous = current;
        }
    }


    previous = begin;
    cout<<"Number of Nodes: " <<nodeCounter<<endl;
    
    cout<<"Enter a number to insert"<<endl;
    cin >> input;
    
    
    current = begin;
    while(current != NULL){
        
        if(input >= current -> data && input < current -> m_next -> data ){
           Node* temp = new Node();
           temp -> data = input;
           temp -> m_next = current -> m_next;
           current -> m_next = temp;
           current = temp;

        }
        current = current -> m_next;
    }

    current = begin;
    while(current != NULL){

        cout<<current -> data<<endl;
        current = current -> m_next;
    }

}