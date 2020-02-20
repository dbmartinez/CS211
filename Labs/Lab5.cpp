// Lab 5

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Employee.h"
using namespace std;

// Function Prototype
void setSalary(Employee&);

// Driver Program
int main()
{
  Employee emp1;
  emp1.Print();

  Employee emp2("Unknown", 10, '?', 0);
  emp2.GetInfo();
  setSalary(emp2);
  emp2.Print();

  return 0;
}

// SetSalary Function
void setSalary(Employee& employ)
{
  if(employ.empPosition == 'E' && employ.yearOfExp < 2)
    {
      employ.salary = 50000;
    }

  else if(employ.empPosition == 'E' && employ.yearOfExp >= 2)
    {
      employ.salary = 55000;
    }

  else if(employ.empPosition == 'P' && employ.yearOfExp <= 4)
    {
      employ.salary = 60000;
    }

  else if(employ.empPosition == 'P' && employ.yearOfExp >= 4)
    {
      employ.salary = 65000;
    }
  
  else if(employ.empPosition == 'M')
    {
      employ.salary = 70000;
    }
  
  else if(employ.empPosition == 'D')
    {
      employ.salary = 80000; 
    }
  
  else
    {
      employ.salary = 0;
    }
}
