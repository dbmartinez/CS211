// Student.cpp

#ifndef STUDENT_CPP
#define STUDENT_CPP
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

long Student::nextStId = 500;  // initialize it to 500

Student::Student():Person()
{
  id = nextStId;
  yearOfStudy = 0;
  major = "none";
  advisorId = 0;
  nextStId++;
}

Student::Student(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId):Person(sName, sEmail, sAddress, sDateOfBirth, sGender)
{
  id = nextStId;
  yearOfStudy = sYearOfStudy;
  major = sMajor;
  advisorId = sAdvisorId;
  nextStId++;
}

Student::~Student()
{

}
#endif

/*
//-----------------
Student::Student()
{
  StuId = nextStId++;
  name = email = address = dateOfBirth = major = gender = " ";
  int yearOfStudy = 0;
  long advisorId = 0;
}


//-----------------
Student::Student(string n, string e, string a, string d, string g, int y, string m, long advId)
{
  StuId = nextStId++;
  name = n;
  email = e;
  address = a;
  dateOfBirth = d;
  gender = g;
  yearOfStudy = y;
  major = m;
  advisorId = advId;
}


//-----------------
void Student::print()
{
  cout << "StuId: \t" << StuId << endl;
  cout << "name: \t" << name << endl;
  cout << "email: \t" << email << endl;
  cout << "address: \t" << address << endl;
  cout << "dateOfBirth: \t" << dateOfBirth << endl;
  cout << "gender: \t" << gender << endl;
  cout << "yearOfStudy:\t" << yearOfStudy << endl;
  cout << "major: \t" << major << endl;
  cout << "advisorId: \t" << advisorId << endl;

}
#endif
*/





/*
#include "Course.h"
#include "Student.h"

#include <iostream>
#include <string>
using namespace std;

// Default constructor
Student::Student()
{
  StNo = " ";
  Course c1;
  Course1 = c1;
  Course c2;
  Course2 = c2;
  Course c3;
  Course3 = c3;
  Course c4;
  Course4 = c4;
  Course c5;
  Course5 = c5;
}

// Constructor
Student::Student(string sN, long cNum1, string cName1, long cNum2, string cName2, long cNum3, string cName3, long cNum4, string cName4, long cNum5, string cName5)
{
  StNo = sN;
  Course c1(cNum1, cName1);
  Course1 = c1;
  Course c2(cNum2, cName2);
  Course2 = c2;
  Course c3(cNum3, cName3);
  Course3 = c3;
  Course c4(cNum4, cName4);
  Course4 = c4;
  Course c5(cNum5, cName5);
  Course5 = c5;
}

void Student::print()
{
  cout << "\nStudent Number: " << StNo;

  cout << "\n\nCourse Information";
  cout << "\n------------------";

  Course1.print();
  Course2.print();
  Course3.print();
  Course4.print();
  Course5.print();
  cout << endl << endl;
}
#endif
*/
