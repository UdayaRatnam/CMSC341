#ifndef _PUZZLE_H
#define _PUZZLE_H
#include <cstdlib>//used to generate random numbers
#include <ctime>//used to get the current time
#include <iostream>
using namespace std;
class Grader;//this class is for grading purposes, no need to do anything
class Tester;//this is your tester class, you add your test functions in this class
const int MAX = 27;
const char ALPHA[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',  
                          'o', 'p', 'q', 'r', 's', 't', 'u', 
                          'v', 'w', 'x', 'y', 'z', '#'};
class Puzzle{
    public:
    friend class Grader;
    friend class Tester;//Tester will have access to private members of Puzzle
    Puzzle(int size=0);//you need to  implement this function
    Puzzle(const Puzzle& rhs);//you need to  implement this function
  const Puzzle& operator=(const Puzzle& rhs){
    if (this->m_table == rhs.m_table) return rhs;
    delete [] m_table;
    m_table = new m_table[rhs.m_size];
    
  };//you need to  implement this function
    void dump();//This function is implemented for you
    ~Puzzle();
    private:
    void makeMem();//you need to  implement this function
    void fill();//This function is implemented for you
    void clear();//you need to  implement this function
    char ** m_table;//2d table to store chars
    int m_size;//used for both number of columns and number of rows

    // ***************************************************
    // Any private helper functions must be delared here!
    // ***************************************************
};
#endif

int main (int argc, char *argv[]) {
  Foo *foo = new Foo();
  Foo *bar = foo;
  *bar = *foo;
}

Foo &operator= (Foo &foo, Foo &bar) {
  if (&foo == &bar) return foo;
  delete 
} 
