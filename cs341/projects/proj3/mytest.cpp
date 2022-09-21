// CMSC 341 - Spring 2021 - Project 3
// driver.cpp: sample driver for the RQueue class.

#include "rqueue.h"
#include <random>
const int ALPHASIZE = 26;
const int NAMESIZE = 3;

std::mt19937 rng;

using namespace std;
// Priority functions compute an integer priority for a student. Internal
// computations may be floating point, but must return an integer.
char alphabet[ALPHASIZE] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int priorityFn1(const Student &tudent);
int priorityFn2(const Student &student);
class Tester{
  public:
  void testBasicInsertion(RQueue& rqueue, int numNodes);
  bool testCopyConstructor(const RQueue& rqueue);
  bool testAssignmentOperator(const RQueue& rqueue);
  bool isIdentical(Node* heapOne, Node* heapTwo);
  bool isValidHeap(const RQueue& rqueue);
  bool isValidHelper(Node* node, prifn_t priFn);
  void measureInsertionTime(int numTrials ,int N);
  void measureExtractionTime(int numTrials ,int N);


};
int main() {
  
  std::random_device rd;
  rng.seed(rd());
  srand(time(NULL));
  Tester tester;
  
  
  //Testing Basic Insertion
  {
    cout<<"Testing Basic Insertion of 1 students"<<endl;
    RQueue queue1(priorityFn1);
    cout<<"Inserting 1 students"<<endl;
    tester.testBasicInsertion(queue1,1);
    queue1.dump();
    cout<<"Printing 1 students in Preorder"<<endl;
    queue1.printStudentQueue();
    cout<<endl;
  }
  cout<<endl;
  {
    cout<<"Testing Basic Insertion of 10 students"<<endl;
    RQueue queue1(priorityFn1);
    cout<<"Inserting 5 students"<<endl;
    tester.testBasicInsertion(queue1,5);
    queue1.dump();
    cout<<"Printing 5 students in Preorder"<<endl;
    queue1.printStudentQueue();
  }
  cout<<endl;
  {
    RQueue queue1(priorityFn1);
    cout<<"Inserting 10 students"<<endl;
    tester.testBasicInsertion(queue1,10);
    queue1.dump();
    cout<<"Printing 10 students in Preorder"<<endl;
    queue1.printStudentQueue();
    cout<<endl;
  }
  cout<<endl;
  {
    //testing copy constructor with many students
    RQueue queue1(priorityFn1);
    tester.testBasicInsertion(queue1,1000);
    cout << "Test case, Copy Constructor: same members, same size, different pointers (deep copy):" << endl;
    if(tester.testCopyConstructor(queue1))  cout<<"Copy Constructor Passed" <<endl;
    else  cout<<"Copy Constructor Failed"<<endl;
  }
  cout<<endl;
  {
    //testing copy constructor with negative students
    RQueue queue1(priorityFn1);
    tester.testBasicInsertion(queue1,-5);
    cout << "\nTest case, Copy Constructor: negative Students: " << endl;
    if(tester.testCopyConstructor(queue1))  cout<<"Copy Constructor Passed" <<endl;
    else  cout<<"Copy Constructor Failed"<<endl;
  }
  cout<<endl;
  {
    //testing copy constructor with 0 student
    RQueue queue1(priorityFn1);
    tester.testBasicInsertion(queue1,0);
    cout << "\nTest case, Copy Constructor: 0 Students: " << endl;
    if(tester.testCopyConstructor(queue1))  cout<<"Copy Constructor Passed" <<endl;
    else  cout<<"Copy Constructor Failed"<<endl;
  }
  cout<<endl;
  {
    //testing copy constructor with 1 students
    RQueue queue1(priorityFn1);
    tester.testBasicInsertion(queue1,1);
    cout << "\nTest case, Copy Constructor: 1 Students: "  << endl;
    if(tester.testCopyConstructor(queue1))  cout<<"Copy Constructor Passed" <<endl;
    else  cout<<"Copy Constructor Failed"<<endl;
  }
  cout<<endl;
  {
    //testing copy constructor with 5 students
    RQueue queue1(priorityFn1);
    tester.testBasicInsertion(queue1,5);
    cout << "\nTest case, Copy Constructor: 5 Students: "  << endl;
    if(tester.testCopyConstructor(queue1))  cout<<"Copy Constructor Passed" <<endl;
    else  cout<<"Copy Constructor Failed"<<endl;
  }
  cout<<endl;
  {
    //testing copy constructor with 10 students
    RQueue queue1(priorityFn1);
    tester.testBasicInsertion(queue1,10);
    cout << "\nTest case, Copy Constructor: 10 Students: "  << endl;
    if(tester.testCopyConstructor(queue1))  cout<<"Copy Constructor Passed" <<endl;
    else  cout<<"Copy Constructor Failed"<<endl;
  }
  cout<<endl;
  {
    //testing assignment operator with many students
    RQueue queue1(priorityFn1);
    tester.testBasicInsertion(queue1, 1000);
    cout<<"Test case, Assignment Operator: same size, same values, different pointer (deep copy):"<<endl;
    if(tester.testAssignmentOperator(queue1)) cout<<"Assignment Operator Passed"<<endl;
    else  cout<<"Assignment Operator Failed"<<endl;
  }
  cout<<endl;
  {
    //testing assignment operator with negative students
    RQueue queue1(priorityFn1);
    tester.testBasicInsertion(queue1,-5);
    cout << "\nTest case, Assignment Operator: negative Students: " << endl;
    if(tester.testAssignmentOperator(queue1)) cout<<"Assignment Operator Passed"<<endl;
    else  cout<<"Assignment Operator Failed"<<endl;
  }
  cout<<endl;
  {
    //testing assignment operator with 0 student
    RQueue queue1(priorityFn1);
    tester.testBasicInsertion(queue1,0);
    cout << "\nTest case, Assignment Operator: 0 Student: " << endl;
    if(tester.testAssignmentOperator(queue1)) cout<<"Assignment Operator Passed"<<endl;
    else  cout<<"Assignment Operator Failed"<<endl;
  }
  cout<<endl;
  {
    //testing assignment operator with 1 student
    RQueue queue1(priorityFn1);
    tester.testBasicInsertion(queue1,1);
    cout << "\nTest case, Assignment Operator: 1 Student: " << endl;
    if(tester.testAssignmentOperator(queue1)) cout<<"Assignment Operator Passed"<<endl;
    else  cout<<"Assignment Operator Failed"<<endl;
  }
  cout<<endl;
  {
    //testing assignment operator with 5 student
    RQueue queue1(priorityFn1);
    tester.testBasicInsertion(queue1,5);
    cout << "\nTest case, Assignment Operator: 5 Student: " << endl;
    if(tester.testAssignmentOperator(queue1)) cout<<"Assignment Operator Passed"<<endl;
    else  cout<<"Assignment Operator Failed"<<endl;
  }
  cout<<endl;
  {
    //testing assignment operator with 10 student
    RQueue queue1(priorityFn1);
    tester.testBasicInsertion(queue1,10);
    cout << "\nTest case, Assignment Operator: 10 Student: " << endl;
    if(tester.testAssignmentOperator(queue1)) cout<<"Assignment Operator Passed"<<endl;
    else  cout<<"Assignment Operator Failed"<<endl;
  }
  cout<<endl;
  {
    //Visual Test for building a heap with a priority function and some data points
    //The priority function will also change
    cout<<"VISUAL TESTS"<<endl;
    RQueue queue1(priorityFn1);
    tester.testBasicInsertion(queue1, 6);
    cout<<"Printing Heap using dump function"<<endl;
    queue1.dump();
    cout<<"Printing the heap in pre order"<<endl;
    queue1.printStudentQueue();
    queue1.setPriorityFn(priorityFn2);
    cout<<""<<endl;
    cout<<"Contents of queue1 after changing priority function to priorityFn2"<<endl;
    queue1.dump();
    queue1.printStudentQueue();
    cout<<""<<endl;
    cout<<"TESTING IF VALID HEAP"<<endl;
    if(tester.isValidHeap(queue1)){
      cout<<"IT IS A VALID HEAP"<<endl;
    }
    else{
      cout<<"VALID HEAP TEST FAILED"<<endl;
    }
    
   
  }


  
    

  {
    cout<<"TESTING IF MERGING WITH DIFFERENT PRIORITIES CATCHES AN ERROR"<<endl;
    RQueue queue1(priorityFn1);
    RQueue queue2(priorityFn2);
    tester.testBasicInsertion(queue1, 5);
    queue1.dump();
    tester.testBasicInsertion(queue2, 5);
    queue2.dump();
    try{
      queue1.mergeWithQueue(queue2);
    }
    catch(domain_error &e){
      cout<<"ERROR CAUGHT, CANNOT MERGE TWO QUEUES WITH DIFFERENT PRIORITIES"<<endl;

    }
   
    cout<<"TESTINF ERROR THROWN"<<endl;
  
  }
  
  RQueue queue1(priorityFn1);
  RQueue queue2(priorityFn1);
  
  
  // Create some test students and insert them into the queue
  //Student(string name, int priority, int year, int major, int group)
  Student student1("Sam",1,1,1,1);
  Student student2("Liz",5,1,2,0);
  Student student3("Nick",2,0,0,0);
  Student student4("Eva",4,3,2,1);

  queue1.insertStudent(student3);
  queue1.insertStudent(student1);
  queue1.insertStudent(student2);
  queue1.insertStudent(student4);
  
  std::cout << "\nqueue1 dump after inserting 4 students (Nick, Sam, Liz, Eva):" << std::endl;
  queue1.dump();
  
  Student student5("John",6,3,2,1);
  Student student6("Mia",3,0,0,0);

  queue2.insertStudent(student5);
  queue2.insertStudent(student6);

  std::cout << "\nqueue2 dump after inserting 2 students (John, Mia):" << std::endl;
  queue2.dump();

  queue1.mergeWithQueue(queue2);

  // Print the queue, change priority function, print again, change
  // again, print again.  Changing the priority function should cause
  // the heap to be rebuilt.

  std::cout << std::endl << "Contents of queue1 after merging with queue2:\n";
  queue1.printStudentQueue();
  std::cout << "\nDump queue1 after merging with queue2:\n";
  queue1.dump();
  
  queue1.setPriorityFn(priorityFn2);
  
  std::cout << std::endl << "Contents of queue1 after changing the priority function to priorityFn2:\n";
  queue1.printStudentQueue();
  std::cout << "\nDump queue1 after changing the priority function to priorityFn2:\n";
  queue1.dump();

  
  queue1.setPriorityFn(priorityFn1);
 
  std::cout << std::endl << "Contents of queue1 after changing the priority function back to priorityFn1:\n";
  queue1.printStudentQueue();
  std::cout << "\nDump queue1 after changing the priority function back to priorityFn1:\n";
  queue1.dump();

  // Remove and print students in priority order

  std::cout << "\nFinal queue1 in priority order:\n";
  while (queue1.numStudents() > 0) {
    Student student = queue1.getNextStudent();
    std::cout << "[" << priorityFn1(student) << "] " << student << std::endl;
  }

  cout<<"TESTING REMOVING FROM EMPTY QUEUE"<<endl;
  try{
    queue1.getNextStudent();
  }
  
  catch(domain_error &e){
    cout<<"ERROR CAUGHT, CANNOT REMOVE FROM EMPTY QUEUE"<<endl;
  }
  

  {
    //Measuring the efficiency of insertion functionality
    cout << "\nMeasuring the efficiency of insertion functionality:" << endl;
    int M = 5;//number of trials
    int N = 1000;//original input size
    tester.measureInsertionTime(M, N);
  }

  {
    //Measuring the effeciency of extraction functionality
    cout << "\nMeasuring the efficiency of extraction functionality:" << endl;
    int M = 5;//number of trials
    int N = 1000;//original input size
    tester.measureExtractionTime(M, N);

  }

  return 0;
}

int priorityFn1(const Student&student) {
  //priority value is determined based on some criteria
  //priority value falls in the range [0-6]
  //the smaller value means the higher priority
  int priority = student.getYear() + student.getMajor() + student.getGroup();
  return priority;
}

int priorityFn2(const Student&student) {
  //priority is determined by an officer in registrar office
  //priority value falls in the range [0-6]
  //the smaller value means the higher priority
  return student.getPriority();
}

void Tester::testBasicInsertion(RQueue& queue, int numNodes){
  if(numNodes > 0){
    for(int i = 0; i < numNodes; i++){
      int priorityOne = (rng() % MAXPRIO) + 1;
      int majorOne = rng() % (SCI + 1);
      int yearOne = rng() % (YEAR1 + 1);
      int groupOne = rng() % (MAJORITY + 1);
      string randomStr = "";
      for(int i = 0; i < NAMESIZE;i++){ 
        randomStr += alphabet[rand() % ALPHASIZE];
      }
      Student students(randomStr,priorityOne,yearOne,majorOne,groupOne);
      queue.insertStudent(students);
      
    }
  }
  
}


bool Tester::testCopyConstructor(const RQueue& rqueue){
    RQueue copy(rqueue);
    if(copy._heap == nullptr && rqueue._heap == nullptr){
      return true;
    }
    if(copy.numStudents() == 0 && rqueue.numStudents() == 0){
      return true;
    }
    else if(copy.numStudents() == rqueue.numStudents()){
      return isIdentical(copy._heap, rqueue._heap);
    }
    else{
      return false;
    }
}


bool Tester::testAssignmentOperator(const RQueue& rqueue){
  RQueue test(rqueue.getPriorityFn());
  test = rqueue;
  test = test;
  if(test.numStudents() == 0 && rqueue.numStudents() == 0){
    return true;
  }
  else if(test.numStudents() == rqueue.numStudents()){
    return isIdentical(test._heap, rqueue._heap);
  }
  else{
    return false;
  }
}


bool Tester::isIdentical(Node* heapOne, Node* heapTwo){

  if(heapOne == nullptr && heapTwo == nullptr){
    return true;
  }
  if(heapOne != nullptr && heapTwo != nullptr){
    return (heapOne->getStudent().getGroup() == heapTwo->getStudent().getGroup() && 
    heapOne->getStudent().getMajor() == heapTwo->getStudent().getMajor() && 
    heapOne->getStudent().getName() == heapTwo->getStudent().getName() && 
    heapOne->getStudent().getPriority() == heapTwo->getStudent().getPriority() &&
    heapOne->getStudent().getYear() == heapTwo->getStudent().getYear() && 
    heapOne != heapTwo && isIdentical(heapOne->_left,heapTwo->_left) && isIdentical(heapOne->_right,heapTwo->_right)); 
  }

  return false;
}

bool Tester::isValidHeap(const RQueue& rqueue){
  

  return isValidHelper(rqueue._heap, rqueue.getPriorityFn());
  
}

bool Tester::isValidHelper(Node* node, prifn_t priFn){
  

  if(node == nullptr){
    return true;
  }

  if(node->_left != nullptr && priFn(node->getStudent()) > priFn(node->_left->getStudent())){
    return false;
  }
  if(node->_right != nullptr && priFn(node->getStudent()) > priFn(node->_right->getStudent())){
    return false;
  }

  if(!isValidHelper(node->_left, priFn) || !isValidHelper(node->_right, priFn)){
    return false;
  }
  return true;
 

}



void Tester::measureInsertionTime(int numTrials, int N){
    //Measuring the efficiency of insertion algorithm with system clock ticks
    //Clock ticks are units of time of a constant but system-specific length, as those returned by function clock().
    //Dividing a count of clock ticks by CLOCKS_PER_SEC yields the number of seconds.
    const int a = 2;//scaling factor for input size
    double T = 0.0;//to store running times
  
    
    RQueue test(priorityFn1);
    clock_t start, stop;//stores the clock ticks while running the program
    for (int k=0;k < numTrials ;k++){

      start = clock();
      this->testBasicInsertion(test, N);
     
      stop = clock();
      
      for(int i = 0; i < N;i++){
        test.getNextStudent();
      }
      
      T = stop - start;//number of clock ticks the algorithm took
      cout << "Inserting " << N << " members took " << T << " clock ticks ("<< T/CLOCKS_PER_SEC << " seconds)!" << endl;
      
      N = N * a;//increase the input size by the scaling factor
        
        
    }

    
}

void Tester::measureExtractionTime(int numTrials ,int N){

  //Measuring the efficiency of extraction algorithm with system clock ticks
  //Clock ticks are units of time of a constant but system-specific length, as those returned by function clock().
  //Dividing a count of clock ticks by CLOCKS_PER_SEC yields the number of seconds.
  const int a = 2;//scaling factor for input size
  double T = 0.0;//to store running times
  
    
  RQueue test(priorityFn1);
  clock_t start, stop;//stores the clock ticks while running the program
  for (int k=0;k < numTrials ;k++){

   
    this->testBasicInsertion(test, N);
   
    start = clock();
    for(int i = 0; i < N;i++){
      test.getNextStudent();
    }
    stop = clock();
    T = stop - start;//number of clock ticks the algorithm took
    cout << "Extracting " << N << " members took " << T << " clock ticks ("<< T/CLOCKS_PER_SEC << " seconds)!" << endl;
    N = N * a;//increase the input size by the scaling factor
        
        
    }

}



