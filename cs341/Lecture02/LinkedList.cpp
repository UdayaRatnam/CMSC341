#include "LinkedList.h"
#include <cstdlib>
#include <iostream>

template <class T>
LinkedList<T>::LinkedList() {
  m_head = new ListNode<T>();
  m_tail = new ListNode<T>();
  m_head->m_prev = NULL;
  m_head->m_next = m_tail;
  m_tail->m_prev = m_head;
  m_tail->m_next = NULL;
}

template <class T>
LinkedList<T>::~LinkedList() {
  ListNode<T> *n = m_head;
  while (n != NULL) {
    ListNode<T> *tmp = n->m_next;
    delete n;
    n = tmp;
  }
}

template <class T>
void LinkedList<T>::add(const T &data) {
  ListNode<T> *n = new ListNode<T>(data, m_tail->m_prev, m_tail);
  m_tail->m_prev->m_next = n;
  m_tail->m_prev = n;
}

template <class T>
CircularLinkedList<T>::CircularLinkedList() {
  m_head = new ListNode<T>();
  m_head->m_prev = m_head;
  m_head->m_next = m_head;
}

template <class T>
CircularLinkedList<T>::~CircularLinkedList() {
  ListNode<T> *n = m_head;
  while (n != NULL) {
    ListNode<T> *tmp = n->m_next;
    delete n;
    n = tmp;
  }
}

template <class T>
void CircularLinkedList<T>::add(const T &data) {
  ListNode<T> *n = new ListNode<T>(data, m_head->m_prev, m_head);
  m_head->m_prev->m_next = n;
  m_head->m_prev = n;
}

template <class T>
ListIterator<T> LinkedList<T>::begin() const {
  ListNode<T> *n = m_head->m_next;
  return ListIterator<T>(n);
}

template <class T>
ListIterator<T> LinkedList<T>::end() {
  return ListIterator<T>(m_tail);
}

template <class T>
ListIterator<T> ListIterator<T>::operator++(int i) {
  m_curr = m_curr->m_next;
  return *this;
}

template <class T>
T &ListIterator<T>::operator*() {
  return m_curr->m_data;
}

template <class T>
bool ListIterator<T>::operator !=(const ListIterator<T> &that) {
  return (this->m_curr != that.m_curr);
}

template <class T>
ListIterator<T>::ListIterator(ListNode<T> *n) {
  m_curr = n;
}

template <class T>
void ListIterator<T>::insert(T data) {
  ListNode<T> *n = new ListNode<T>(data, m_curr, m_curr->m_next);
  m_curr->m_next->m_prev = n;
  m_curr->m_next = n;
}

template <class T>
void ListIterator<T>::erase() {
  ListNode<T> *n = m_curr;
  m_curr->m_prev->m_next = m_curr->m_next;
  m_curr->m_next->m_prev = m_curr->m_prev;
  m_curr = m_curr->m_next;
  delete n;
}


int main (int argc, char *argv[]) {
  LinkedList<int> l;
  for (int i=0; i<15; i++) {
    l.add(i);
  }

  for (ListIterator<int> i = l.begin();  *i < *l.end();i++) {
    std::cout<<(*i)<<std::endl;
    i.erase();
  }
  for (ListIterator<int> i = l.begin(); i != l.end(); i++) {
    std::cout<<(*i)<<std::endl;
  }
}
