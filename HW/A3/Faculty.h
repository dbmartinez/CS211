// Faculty.h

#ifndef FACULTY_H
#define FACULTY_H
#include <string>
#include <vector>
#include <iostream>
#include "Person.h"
using namespace std;

class Faculty:public Person 
{
  friend class University;

 protected:
  long id;
  float salary;
  int yearOfExp;
  int departId;
  static long nextFacultyId;
 
 public:
  Faculty();
  Faculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId);
  ~Faculty();
};
#endif
