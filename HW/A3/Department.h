// Author: Daniel Martinez
// Email: marti931@cougars.csusm.edu
// Date Written: 11/29/2019
// Due Date: 12/05/2019  
// Department.h

#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Department
{
  friend class University;
 
 protected:
  long id;
  string name;
  string location;
  long chairId;
  static long nextDepartId;

 public:
  Department();
  Department(string deptName, string deptLoc, long deptChairId);
  ~Department();
};
#endif
