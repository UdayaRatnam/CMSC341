/*****************************************
** File:    Bookshelf.cpp
** Project: CMSC 202 Lab 12, Fall 2020
**
** This is the cpp file for the Bookshelf class in Lab 12. You will need to
** implement the Copy constructor, overloaded assignment operator, and
** the destructor in this file.
**
***********************************************/

#include "Bookshelf.h"

//Overloaded constructor
Bookshelf::Bookshelf(int cap, string name) {
  cout << "Bookshelf Constructor: Capacity=" << cap << " Name=" << name << endl;
  m_capacity = cap;
  m_used = 0;
  m_shelfName = name;
  m_books = new string[cap];
}

//Implement Copy Constructor Here
Bookshelf::Bookshelf(const Bookshelf &source){

  m_capacity = source.m_capacity;
  m_shelfName = source.m_shelfName;
  m_used = source.m_used;
  m_books = source.m_books;
}

//Implement Overloaded Assignment Operator Here
Bookshelf& Bookshelf::operator= (const Bookshelf& source){
  m_capacity = source.m_capacity;
  m_used = source.m_used;
  m_shelfName = source.m_shelfName;
  m_books = source.m_books;
  return *this;
}


//Implement Destructor Here
Bookshelf::~Bookshelf(){

  cout<<"Inside Destructor"<<endl;
  cout<<"removing object"<<endl;
}


//Inserts a new subject into the subject array
void Bookshelf::Insert(const string& itemName) {
  if(m_used == m_capacity) {
    cout << "The bookshelf is full. Cannot add any more books." << endl;
  }
  else  {
    m_books[m_used] = itemName;
    m_used++;
    cout << "Book:" << itemName << " added to the bookshelf." << endl;
  }
}

//Deletes the last subject in the subject array
void Bookshelf::DeleteLast() {
  if (m_used == 0) {
    cout << "The bookshelf is Empty!" << endl;
  }
  else{
    m_used--;
    cout << "Book:" << m_books[m_used] << " removed from the bookshelf." << endl;
    m_books[m_used] = "";
  }
}

//Sets the name of the bookshelf
void Bookshelf::SetName(const string& name){
  m_shelfName = name;
}

//Overloaded << Operator
ostream& operator <<(ostream& os, const Bookshelf& fm) {
  os << "m_capacity: " << fm.m_capacity << endl;
  os << "m_used: " << fm.m_used << endl;

  os << fm.m_shelfName << " has the following books:" << endl << " | ";
  for(int i=0; i<fm.m_used; i++) {
    os << fm.m_books[i] + " | ";
  }
  return os << endl;
}
