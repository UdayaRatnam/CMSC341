#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
using namespace std;


struct Node{

    int data;
    Node* m_next;
}



class LinkedList{

    public:
        LinkedList();
        void AddBegin(int num);
        void AddEnd(int num);
        void Insert(int location, int num);
        void Display();

    private:
        Node* m_head;
        Node* m_tail;
        int m_size;

}


#endif