#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <class T> class ListIterator;
template <class T> class LinkedList;

template <class T>
class ListNode {
  T m_data;
  ListNode<T> *m_prev, *m_next;
 public:
  ListNode (const T &data, ListNode *const prev, ListNode *const next) {
    m_data = data;
    m_prev = prev;
    m_next = next;
  };
  ListNode() {};
  friend class ListIterator<T>;
  friend class LinkedList<T>;
};

template <class T>
class LinkedList {
  ListNode<T> *m_head, *m_tail;
 public:
  LinkedList();
  ~LinkedList();
  void add(const T &data);
  ListIterator<T> begin() const;
  ListIterator<T> end();
};

template <class T>
class ListIterator {
  ListNode<T> *m_curr;
public:
  ListIterator<T> (ListNode<T> *n);
  ListIterator<T> operator++(int i);
  bool operator !=(const ListIterator<T> &that);
  T &operator*();
  void insert(T data);
  void erase();
};
  

template <class T>
class CircularLinkedList {
  ListNode<T> *m_head;
 public:
  CircularLinkedList();
  ~CircularLinkedList();
  void add(const T &data);
};

#endif
