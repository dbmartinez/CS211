// Author: Daniel Martinez
// Email: marti931@cougars.csusm.edu
// Date Written: 11/29/2019
// Due Date: 12/05/2019  
// Person.h

#ifndef PERSON_H
#define PERSON_H
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Person
{
 protected:
  string name;
  string email;
  string address;
  string dateOfBirth;
  string gender;

 public:
  Person();
  Person(string pName, string pEmail, string pAddress, string pDateOfBirth, string pGender);
  ~Person();
};
#endif



/*
class Person
{
 private:
  long SSN;
  string Fname;
  string Lname;
  int Age;
  char Gender;
  //  Student s1;

 public:
  Person();
  Person(long id, string Fn, string Ln, int a, char g);
  void print();
  
  void setSSN(long);
  void setFname(string);
  void setLname(string);
  void setAge(int);
  void setGender(char);
  long getSSN();
  string getFname();
  string getLname();
  int getAge();
  char getGender();
  
};
#endif
*/
