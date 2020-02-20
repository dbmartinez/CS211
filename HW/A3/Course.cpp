// Author: Daniel Martinez
// Email: marti931@cougars.csusm.edu
// Date Written: 11/29/2019
// Due Date: 12/05/2019
// Course.cpp

#ifndef COURSE_CPP
#define COURSE_CPP
#include "Course.h"

//Static Declaration
long Course::nextCRN = 200;

Course::Course()
{
  CRN = nextCRN;
  maxAvailableSeats = 0;
  name = "unknown";
  departId = 0;
  assignedSeats = 0;
  isTaughtBy = 0;
  nextCRN++;
}

Course::Course(string cName, long cDepId, long cTaughtBy, int cMaxSeat)
{
  CRN = nextCRN;
  maxAvailableSeats = cMaxSeat;
  name = cName;
  departId = cDepId;
  assignedSeats = 0;
  isTaughtBy = cTaughtBy;
  nextCRN++;
}

Course::~Course()
{

}
#endif

/*
Course::Course()
{
  CRN = maxAvaliableSeats = departId = assignedSeats = isTaughtBy = 0;
  name = " ";
  CRN = nextCRN++;
}

Course::Course(string n, string l, long chair) 
{
 
  
}


void Course::print()
{



}
#endif*/

/*
#include "Course.h"

// Default constructor
Course::Course()
{
  courseNum = 0;
  courseName = " ";
}

// Constructor
Course::Course(long cNum, string cName)
{
  courseNum = cNum;
  courseName = cName;
}

void Course::print()
{
  cout << "\nCourse Number: " << courseNum;
  cout << "\nCourse Name:   " << courseName;
    
}
#endif
*/
