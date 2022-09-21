#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

template <class T, int N> //T is the data type and N is the container's capacity
class Tqueue {
public:
  //Name: Tqueue - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a queue using dynamic array
  Tqueue(); //Default Constructor
  //Name: Copy Constructor
  //Precondition: Existing Tqueue
  //Postcondition: Copies an existing Tqueue
  Tqueue(const Tqueue<T,N>& x ); //Copy Constructor
  //Name: Destructor
  //Desc: Empties m_data
  //Precondition: Existing Tqueue
  //Postcondition: Destructs existing Tqueue
  ~Tqueue(); //Destructor
  //Name: Enqueue
  //Desc: Adds item to the back of queue (checks for capacity)
  //Precondition: Existing Tqueue
  //Postcondition: Size is incremented if successful and m_back increases
  void Enqueue(T data); //Adds item to queue (to back)
  //Name: Dequeue
  //Desc: Removes item from queue (from front)
  //      **Automatically moves all data to start at index 0 (using loop**
  //Precondition: Existing Tqueue
  //Postcondition: Size is decremented if successful.
  //               Data in m_front is removed and remaining data is move to the front.
  void Dequeue();
  //Name: Sort
  //Desc: Sorts the contents of the Tqueue (any algorithm you like)
  //Precondition: Existing Tqueue
  //Postcondition: Contents of Tqueue is sorted (low to high)
  void Sort();
  //Name: IsEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int IsEmpty(); //Returns 1 if queue is empty else 0
  //Name: IsFull
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is full else 0
  int IsFull(); //Returns 1 if queue is full else 0
  //Name: Size
  //Desc: Returns size of queue
  //Precondition: Existing Tqueue
  //Postcondition: Returns size of queue (difference between m_back and m_front)
  int Size();
  //Name: Overloaded assignment operator
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T,N>& operator=( Tqueue<T,N> y); //Overloaded assignment operator for queue
  //Name: At
  //Precondition: Existing Tqueue with index starting at 0
  //Postcondition: Returns object from Tqueue using At() 
  T& At(int x);//Returns data from queue at location
  //Name: DisplayAll()
  //Precondition: Existing Tqueue (not used in MediaPlayer)
  //Postcondition: Outputs all items in Tqueue (must be cout compatible -
  //               may require overloaded << in object)
  void DisplayAll();
private:
  T* m_data; //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue (for this project should always remain at 0)
  int m_back; //Back of the queue (will increase as the size increases)
};
//**** Add class definition below ****
template <class T, int N>
Tqueue<T,N>::Tqueue(){
  m_data = new T[N];
  m_front = m_back = 0;
}
template <class T, int N>
Tqueue<T,N>::Tqueue(const Tqueue<T,N>& x){

 
  m_front = x.m_front;
  m_back = x.m_back;
  if(x.m_data){
    m_data = new T[N];
    for(int i = 0; i < x.m_back; i++){
      m_data[i] = x.m_data[i];
    }
  
  }
  else{
    m_data = 0;
  }
     
}
template <class T, int N>
Tqueue<T, N>::~Tqueue(){


  delete [] m_data;
}


template <class T, int N>
void Tqueue<T,N>::Enqueue(T data){

  if(!(IsFull())){

    m_data[m_back] = data;
    m_back++;
  }
  else{

    cout<<"Queue is full"<<endl;
  }
  
}
template <class T, int N>
void Tqueue<T,N>::Dequeue(){

  if(m_front == m_back){

    cout<<"Queue is empty"<<endl;
  }
  else{

    for(int i = 0; i < m_back -1; i++){

      m_data[i] = m_data[i+1];

    }
    m_back--;
  }

}
template <class T, int N>
void Tqueue<T,N>::Sort(){
  if(m_front == m_back){
    cout<<"Queue is empty"<<endl;
  }
  else{
    int minimum;
    for(int i = 0; i < m_back-1; i++){
    minimum = i;
      for(int j = i+1; j < m_back; j++){
        if(m_data[minimum] > m_data[j]){
          minimum = j;
              
        }
      }
      if(i != minimum){
        T temp = m_data[minimum];
        m_data[minimum] = m_data[i];
        m_data[i] = temp;
          
          
      }
      
    }
   
  }
}

template <class T, int N>
int Tqueue<T,N>::IsEmpty(){

  if(m_front == m_back){
    return 1;
  }
  return 0;
}
template <class T, int N>
int Tqueue<T,N>::IsFull(){

  if(N == m_back){
    return 1;
  }
  return 0;
}
template <class T, int N>
int Tqueue<T,N>::Size(){

  return m_back - m_front;
}
template <class T, int N>
Tqueue<T,N>& Tqueue<T,N>::operator= (Tqueue<T,N> y){
 
  if(this == &y){
    return *this;
    
  }
  delete [] m_data;
  m_back = y.m_back;
  if(y.m_data){
    m_data = new T[N];
    for(int i = 0; i < m_back;i++){
      m_data[i] = y.m_data[i];
    }
  }
  else{
    m_data = 0;
  }
  return *this;
}

template <class T, int N>
T& Tqueue<T,N>::At(int x){

  return m_data[x];
}
template <class T,int N>
ostream& operator<<(ostream& os, const T& d){

  return os << d;
  return os;
}
template <class T, int N>
void Tqueue<T,N>::DisplayAll(){

  for(int i = 0; i < m_back; i++){
    cout << m_data[i] <<endl;
  }
  
}










#endif
