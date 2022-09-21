/**************
 * File: lab5.cpp
 * The user creates this file to demonstrate use of a course.
 *************/

#include <iostream>
#include "Course.h"
using namespace std;

int main() {
  //**Student Requirement**
  //Part 1: Create 2 courses by instantiating them
  Course courseOne;
  Course courseTwo;


  //**Student Requirement**
  //Part 2: Set their values for course name, section number, and enrolled students.
  //For course one
  courseOne.setCourseName("CMSC 201");
  courseOne.setSectionNum(1738);
  courseOne.setEnrolledStudents(0);
  //For course two
  courseTwo.setCourseName("CMSC 202");
  courseTwo.setSectionNum(42069);
  courseTwo.setEnrolledStudents(41);



  //**Student Requirement**
  //Part 3: Output their information:  Name, section, and enrolled students
  cout << "Data of course1:\n";
  cout <<"Course Name: "<<courseOne.getCourseName()<<endl;
  cout <<"Section: "<<courseOne.getSectionNum()<<endl;
  cout <<"Enrolled Students: "<<courseOne.getEnrolledStudents()<<endl;
  cout << "Data of course2:\n";
  cout <<"Course Name: "<<courseTwo.getCourseName()<<endl;
  cout <<"Section: "<<courseTwo.getSectionNum()<<endl;
  cout <<"Enrolled Students: "<<courseTwo.getEnrolledStudents()<<endl;
  

  //**Student Requirement**
  //Part 4: Call a custom function: Check if courses are large or not
  courseOne.checkLarge();
  courseTwo.checkLarge();



  //**Student Requirement**
  //Part 5: Update data members with custom function: Drop a student from each course
  //Display updated enrolled students
  if (courseOne.dropStudent() == true){
    cout<<"Student successfully dropped the course"<<endl;

  }
  else{
    cout<<"The course is already empty!"<<endl;
  }

  

cout <<"Course Name: "<<courseOne.getCourseName()<<endl;
cout <<"Enrolled Students: "<<courseOne.getEnrolledStudents()<<endl;
cout <<"Course Name: "<<courseTwo.getCourseName()<<endl;
cout <<"Enrolled Students: "<<courseTwo.getEnrolledStudents()<<endl;

  
return 0;
}
