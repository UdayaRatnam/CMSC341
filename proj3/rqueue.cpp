// CMSC 341 - Spring 2021 - Project 3
// RQueue: 

#include "rqueue.h"
using namespace std;
using std::cout;
using std::endl;
using std::domain_error;

RQueue::RQueue(prifn_t priFn)
{
  /************************
   * To be implemented
   * *********************/
  _heap = nullptr;
  _size = 0;
  priority = priFn;  
  
}
void RQueue::deleteTree(Node* node){
  if(node){
    deleteTree(node->_left);
    deleteTree(node->_right);
    delete node;     
  }
}
RQueue::~RQueue()
{
  /************************
   * To be implemented
   * *********************/
  clear();
}

RQueue::RQueue(const RQueue& rhs)
{

  /************************
   * To be implemented
   * *********************/
  
  if(rhs._heap == nullptr){
    this->_heap = nullptr;
  }
  else{
    this->priority = rhs.getPriorityFn();
    this->_size = rhs._size;
    recursiveCopy(rhs._heap, this->_heap);
  }
}

void RQueue::recursiveCopy(Node* srcNode, Node*& copyNode){

  if(srcNode == nullptr){
    copyNode = nullptr;
  }
  else{
    
    copyNode = new Node(srcNode->getStudent());
    
    recursiveCopy(srcNode->_left, copyNode->_left);
    recursiveCopy(srcNode->_right,copyNode->_right);
  }
}

RQueue& RQueue::operator=(const RQueue& rhs)
{
  /************************
   * To be implemented
   * *********************/
  if(this != &rhs){
    this->clear();
    this->_size = rhs._size;
    this->priority = rhs.priority;
    
    recursiveCopy(rhs._heap, this->_heap);
  }
  return *this;
}

void RQueue::insertStudent(const Student& input) {
  /************************
   * To be implemented
   * *********************/
  Node* new_node = new Node(input);

  this->_heap = merge(_heap, new_node);
  
  _size++;
}

Student RQueue::getNextStudent() {
  /************************
   * To be implemented
   * *********************/
  if(this->_heap == nullptr){
    throw std::domain_error("CANNOT REMOVE FROM EMPTY QUEUE");
  }
  Student student = this->_heap->getStudent();
  Node* lastNode = this->_heap;
  this->_heap = merge(lastNode->_left, lastNode->_right);
  delete lastNode;
  this->_size--;
  return student;
}


void RQueue::mergeWithQueue(RQueue& rhs) {
  /************************
   * To be implemented
   * *********************/
  
  if(this->getPriorityFn() != rhs.getPriorityFn()){
    throw std::domain_error("CANNOT MERGE WITH DIFFERENT PRIORITIES");
  }
  if(this != &rhs){
    
    this->_heap = merge(this->_heap, rhs._heap);
    
    
    
    this->_size = this->_size + rhs._size;
  }
  else{
    return;
  }
  
  rhs._heap = nullptr;
}

Node* RQueue::merge(Node* heapOne, Node* heapTwo){
  
  if(heapOne == nullptr){
    return heapTwo;
  }
  if(heapTwo == nullptr){
    return heapOne;
  }
  if(priority(heapOne->_student) >= priority(heapTwo->_student)){
    
   swap(heapOne, heapTwo);
  }
  
  swap(heapOne->_left,heapOne->_right);
  heapOne->_left = merge(heapTwo,heapOne->_left);
  
  
  return heapOne;
  
  
 
}

void RQueue::clear() {
  /************************
   * To be implemented
   * *********************/
  deleteTree(_heap);
}
int RQueue::numStudents() const
{
  /************************
   * To be implemented
   * *********************/
  return this->_size;
}
void RQueue::printStudentPreorder(Node* node) const{
  if(node == nullptr){
    return;
  }
  cout<<"["<<priority(node->getStudent())<<"] "<<node->getStudent()<<endl;
  printStudentPreorder(node->_left);
  printStudentPreorder(node->_right);
}
void RQueue::printStudentQueue() const {
  /************************
   * To be implemented
   * *********************/
  //cout<<"prints student queue"<<endl;
  printStudentPreorder(_heap);
  
}

prifn_t RQueue::getPriorityFn() const {
  /************************
   * To be implemented
   * *********************/
  return this->priority;
}

void RQueue::setPriorityFn(prifn_t priFn) {
  /************************
   * To be implemented
   * *********************/
  //cout<<"SIZE: "<<_size<<endl;
  
  
  this->priority = priFn;
 
  

  
 int size = this->_size;
 Student array[size];

 for(int i = 0 ;i < size;i++){
   array[i] = this->getNextStudent();
 }

 for(int i = 0; i < size;i++){
   this->insertStudent(array[i]);
 }
  
  
}


// for debugging
void RQueue::dump() const
{
  if (_size == 0) {
    cout << "Empty skew heap.\n" ;
  } else {
    dump(_heap);
    cout << endl;
  }
}

// for debugging
void RQueue::dump(Node *pos) const {
  if ( pos != nullptr ) {
    cout << "(";
    dump(pos->_left);
    cout << priority(pos->_student) << ":" << pos->_student.getName();
    dump(pos->_right);
    cout << ")";
  }
}

// overloaded insertion operator for Student class
ostream& operator<<(ostream& sout, const Student& student) {
  sout << "Student: " << student.getName() << ", priority: " << student.getPriority()
       << ", year: " << student.getYear() << ", major: " << student.getMajorStr() 
       << ", group: " << student.getGroupStr();
  return sout;
}

// overloaded insertion operator for Node class
ostream& operator<<(ostream& sout, const Node& node) {
  sout << node.getStudent();
  return sout;
}