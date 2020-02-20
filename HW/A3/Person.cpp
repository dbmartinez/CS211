// Author: Daniel Martinez
// Email: marti931@cougars.csusm.edu
// Date Written: 11/29/2019      
// Due Date: 12/05/2019 
// Person.cpp

#ifndef PERSON_CPP
#define PERSON_CPP
#include "Person.h"

Person::Person()
{
  name = "";
  email = "";
  address = "";
  dateOfBirth = "";
  gender = "";
}

Person::Person(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender)
{
  name = fName;
  email = fEmail;
  address = fAddress;
  dateOfBirth = fDateOfBirth;
  gender = fGender;
}

Person::~Person()
{

}
#endif


/*
// Default constructor
Person::Person()
{
  SSN = Age = 0;
  Fname = Lname = " ";
  Gender = ' ';
}

// Constructor
Person::Person(long id, string Fn, string Ln, int a, char g)
{
  SSN = id;
  Fname = Fn;
  Lname = Ln;
  Age = a;
  Gender = g;
}

void Person::print()
{
  cout << "\nStudent Information";
  cout << "\n--------------------";

  cout << "\nSocial Security Number: " << SSN;
  cout << "\nFirst Name: " << Fname;
  cout << "\nLast Name: " << Lname;
  cout << "\nAge: " << Age;
  cout << "\nGender: " << Gender;
}
*/

/* Set functions(mutator methods)
void Person::setSSN(long id)
{
  SSN = id;
}

void Person::setFname(string Fn)
{
  Fname = Fn;
}

void Person::setLname(string Ln)
{
  Lname = Ln;
}

void Person::setAge(int a)
{
  Age = a;
}

void Person::setGender(char g)
{
  Gender = g;
}

// Get functions(accessor methods)
long Person::getSSN()
{
  return SSN;
}

string Person::getFname()
{
  return Fname;
}

string Person::getLname()
{
  return Lname;
}

int Person::getAge()
{
  return Age;
}

char Person::getGender()
{
  return Gender;
}*/
