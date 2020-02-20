// Course.h

#ifndef COURSE_H
#define COURSE_H
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Course{
  friend class University;
 
 private:
  long CRN;
  int maxAvailableSeats;
  string name;
  long departId;
  long assignedSeats;
  long isTaughtBy;
  static long nextCRN;
 
 public:
  Course();
  Course(string cName, long cDepId, long cTaughtBy, int cMaxSeat);
  ~Course();
};
#endif


/*
class Course
{
 protected:
  long CRN;
  int maxAvaliableSeats;
  string name;
  long departId;
  long assignedSeats;
  long isTaughtBy;
  static long nextCRN; // initialize it to 200

 public:
  Course();
  Course(string n, string l, long chair);
  void print();
};
#endif
*/


/*
class Course
{
 private:
  long courseNum;
  string courseName;

 public:
  Course();
  Course(long cNum, string cName);

  void print();
};
#endif
*/
