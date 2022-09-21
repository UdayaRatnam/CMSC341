/*****************************************
** File:    Bookshelf.h
** Project: CMSC 202 Lab 12, Fall 2020
**
** This is the header file for the Bookshelf class in Lab 12.
**
***********************************************/

#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include <iostream>
#include <string>
using namespace std;

static const int MAX_NO_OF_ITEM = 5;

class Bookshelf {
public:
  //Overloaded Constructor
  //**Notice** this constructor has a name and capacity with default values, therefore,
  //a default constructor is not required (and it will cause a ambiguity error)
  Bookshelf(int capacity = MAX_NO_OF_ITEM, string name = "My Bookshelf");

  //Copy Constructor
  Bookshelf(const Bookshelf& source);

  //Overloaded Assignment Operator
  Bookshelf& operator=(const Bookshelf& source);

  //Destructor
  ~Bookshelf();

  //Inserts a book into the bookshelf
  void Insert(const string& book);

  //Removes the last book from the bookshelf
  void DeleteLast();

  //Sets the name of the Bookshelf
  void SetName(const string& name);

  //Friend Function that is an overloaded << operator
  friend ostream& operator<<(ostream& os, const Bookshelf& fm); //Overloaded << Operator

private:
  int m_capacity; //Max capacity of the bookshelf
  int m_used; //Current used capacity of bookshelf
  string m_shelfName; //String name of the bookshelf
  string* m_books; //Array of names of books in bookshelf
};

#endif // BOOKSHELF_H
