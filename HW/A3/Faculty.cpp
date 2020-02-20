// Author: Daniel Martinez
// Email: marti931@cougars.csusm.edu
// Date Written: 11/29/2019
// Due Date: 12/05/2019  
// Faculty.cpp

#ifndef FACULTY_CPP
#define FACULTY_CPP
#include "Faculty.h"
#include <iostream>
#include <string>
using namespace std;

// Static Declaration
long Faculty::nextFacultyId = 600;

Faculty::Faculty()
{
  id = nextFacultyId;
  salary = 0;
  yearOfExp = 0;
  departId = 0;
  nextFacultyId++;
}

Faculty::Faculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId):Person(fName, fEmail, fAddress, fDateOfBirth, fGender)
{
  id = nextFacultyId;
  salary = fSalary;
  yearOfExp = fYearOfExp;
  departId = fDepId;
  nextFacultyId++;
}

Faculty::~Faculty()
{

}
#endif
