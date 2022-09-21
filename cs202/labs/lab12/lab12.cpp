/*****************************************
** File:    lab12.cpp
** Project: CMSC 202 Lab 12, Fall 2020
**
** This is the main driver file for lab 12. This will test your copy
** constructor, assignment operator, and destructor that you implemented for
** the Bookshelf class. You do not need to edit this file.
**
***********************************************/


#include "Bookshelf.h"

int main() {
  Bookshelf bookshelf1; //Constructor Called (overloaded constructor with default values)

  bookshelf1.Insert("A Darker Shade of Magic"); //Adds A Darker Shade of Magic to bookshelf1
  bookshelf1.Insert("Mistborn"); //Adds Mistborn to bookshelf1
  bookshelf1.Insert("The Princess Bride"); //Adds The Princess Bride to bookshelf1

  //Calls the overloaded << operator to output the Bookshelf List
  cout <<"bookshelf1: " << bookshelf1 << endl;

  cout << "bookshelf2 created using overloaded constructor" << endl;
  Bookshelf bookshelf2(4, "Science Fiction"); //Constructor called (uses overloaded constructor)

  bookshelf2.Insert("I, Robot"); //Adds I, Robot to bookshelf2
  bookshelf2.Insert("The War of the Worlds"); //Adds The War of the Worlds to bookshelf2
  cout << "bookshelf2: " << bookshelf2 << endl; //Calls overloaded << operator outputs List

  //Copy Constructor Called
  cout << "Copy Constructor called to create bookshelf3 (copying bookshelf1)" << endl;
  Bookshelf bookshelf3(bookshelf1);

  //Deletes entries from bookshelf3
  bookshelf3.DeleteLast();
  cout << "bookshelf3: " << bookshelf3 << endl; //Calls overloaded << operator outputs List
  
  //Overloaded Assignment Called
  cout << "Overloaded assignment invoked on bookshelf1 (copying bookshelf2)" << endl;
  bookshelf1 = bookshelf2; //Calls overloaded assignment on bookshelf1, setting it to bookshelf2
  bookshelf1.SetName("Favorites"); //Sets name of bookshelf1
  cout << "bookshelf1: " << bookshelf1 << endl; //Calls overloaded << operator outputs List
  
  cout << "==========================================" << endl;
  cout << "Final Lists:" <<endl;
  cout << "bookshelf1: " << bookshelf1 << endl;
  cout << "bookshelf2: " << bookshelf2 << endl;
  cout << "bookshelf3: " << bookshelf3 << endl;

}

