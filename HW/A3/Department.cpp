// Department.cpp

#ifndef DEPARTMENT_CPP
#define DEPARTMENT_CPP
#include "Department.h"
#include <iostream>
#include <string>
using namespace std;

// Static Declaration
long Department::nextDepartId = 100;

Department::Department()
{
  id = nextDepartId;
  name = " ";
  location = " ";
  chairId = 0;
  nextDepartId++;
}

Department::Department(string deptName, string deptLoc, long deptChairId)
{
  id = nextDepartId;
  name = deptName;
  location = deptLoc;
  chairId = deptChairId;
  nextDepartId++;
}

Department::~Department()
{

}
#endif
