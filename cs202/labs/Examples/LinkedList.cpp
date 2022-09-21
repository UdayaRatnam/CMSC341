#include "LinkedList.h"

LinkedList::LinkedList(){

    m_head = NULL;
    m_tail = NULL;
    m_size = 0;
}


void LinkedList:: AddBegin(int num){
    Node* temp = new Node();
    if(m_head == NULL){
        m_head = temp;
        m_tail = temp;
        m_size = 1;
        temp -> data = num;
        temp -> m_next = NULL;
    }
    else{
        temp -> m_next = head;
        m_head = temp;
        temp -> data = num;
        m_size++;
    }

}


void LinkedList::AddEnd(int num){
    Node* temp = new Node();
    if(m_head == NULL){
        m_head = temp;
        m_tail = temp;
        m_size = 1;
        temp -> data = num;
        temp -> m_next = NULL;
    }
    else{
        temp -> m_next = tail;
        m_tail = temp;
        temp -> data = num;
        m_size++;

    }
}