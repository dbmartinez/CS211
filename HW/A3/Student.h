// Author: Daniel Martinez
// Email: marti931@cougars.csusm.edu
// Date Written: 11/29/2019
// Due Date: 12/05/2019
// Student.h

#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include "Course.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student:public Person
{
  friend class University;

 protected:
  long id;
  int yearOfStudy;
  string major;
  long advisorId;
  vector<Course> coursesTaken;
  static long nextStId;
 
 public:
  Student();
  Student(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId);
  ~Student();
};
#endif



/*
class Student
{
 protected:
  long StuId;
  string name;
  string email;
  string address;
  string dateOfBirth;
  string gender;
  int yearOfStudy;
  string major;
  long advisorId;
  vector<Course> coursesTaken;
  static long nextStId;  // initialize it to 500
 
 public:
  Student();
  Student(string n, string e, string a, string d, string g, int y, string m, long adv_Id);
  void print();
};
#endif
*/


/*
class Student
{
 private:
  string StNo;
  Course Course1;
  Course Course2;
  Course Course3;
  Course Course4;
  Course Course5;
  
 public:
  Student();
  Student(string sN, long cNum1, string cName1, long cNum2, string cName2, long cNum3, string cName3, long cNum4, string cName4, long cNum5, string cName5);

};
#endif
*/
