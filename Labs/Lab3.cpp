// Lab 3

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/*
class Person;
class Course;
class Student;
class StudentProfile;
*/

class Person
{
  public:
    long SSN;
    string Fname;
    string Lname;
    int age;
    char gender;
};

class Course
{
public:
  long CourseNum;
  string CourseName;
};

class Student
{
public:
  string StNo;

  Course Course1;
  Course Course2;
  Course Course3;
  Course Course4;
  Course Course5;
};

class StudentProfile
{
public:
  Person PersonalInfo;
  Student StdInfo;
};

// Main function
int main()
{ 
  ifstream inputFile;
  inputFile.open("transaction2.txt");

  vector<StudentProfile> StCollection;

  if(inputFile.fail())
    {
      cout << "\nFile cannot be opened\n";
    }

  else
    {
      StudentProfile temp;

      while(inputFile >> temp.PersonalInfo.SSN)
	{
	  // Input all information from file
	  inputFile >> temp.PersonalInfo.Fname;
	  inputFile >> temp.PersonalInfo.Lname;
	  inputFile >> temp.PersonalInfo.age;
	  inputFile >> temp.PersonalInfo.gender;
	  inputFile >> temp.StdInfo.StNo;
	  inputFile >> temp.StdInfo.Course1.CourseNum;
	  inputFile >> temp.StdInfo.Course1.CourseName;
	  inputFile >> temp.StdInfo.Course2.CourseNum;
          inputFile >> temp.StdInfo.Course2.CourseName;
	  inputFile >> temp.StdInfo.Course3.CourseNum;
          inputFile >> temp.StdInfo.Course3.CourseName;
	  inputFile >> temp.StdInfo.Course4.CourseNum;
          inputFile >> temp.StdInfo.Course4.CourseName;
	  inputFile >> temp.StdInfo.Course5.CourseNum;
          inputFile >> temp.StdInfo.Course5.CourseName;

	  // Push back info
	  StCollection.push_back(temp);
        }
        
      // Dipslay info in a loop
      for(int index = 0; index < StCollection.size(); index++)
        {
	  //Title                       
	  cout << "\nStudent " << index + 1 << " Information";
	  cout << "\n---------------------";

	  // Student info
	  cout << "\nSocial Security Number: ";
	  cout << StCollection[index].PersonalInfo.SSN;
	  cout << "\nFirst Name: ";
	  cout << StCollection[index].PersonalInfo.Fname;
	  cout << "\nLast Name: ";
	  cout << StCollection[index].PersonalInfo.Lname;
	  cout << "\nAge: ";
	  cout << StCollection[index].PersonalInfo.age;
	  cout << "\nGender: ";
	  cout << StCollection[index].PersonalInfo.gender;
	  cout << "\nStudent Number: ";
	  cout << StCollection[index].StdInfo.StNo;

	  // Courses
	  cout << "\n\nCourse Information";
	  cout << "\n------------------";
	  cout << "\nCourse Number: ";
	  cout << StCollection[index].StdInfo.Course1.CourseNum;
	  cout << "\nCourse Name:   ";
	  cout << StCollection[index].StdInfo.Course1.CourseName;
	  cout << "\n\nCourse Number: ";
	  cout << StCollection[index].StdInfo.Course2.CourseNum;
	  cout << "\nCourse Name:   ";
	  cout << StCollection[index].StdInfo.Course2.CourseName;
	  cout << "\n\nCourse Number: ";
	  cout << StCollection[index].StdInfo.Course3.CourseNum;
	  cout << "\nCourse Name:   ";
	  cout << StCollection[index].StdInfo.Course3.CourseName;
	  cout << "\n\nCourse Number: ";
	  cout << StCollection[index].StdInfo.Course4.CourseNum;
	  cout << "\nCourse Name:   ";
	  cout << StCollection[index].StdInfo.Course4.CourseName;
	  cout << "\n\nCourse Number: ";
	  cout << StCollection[index].StdInfo.Course5.CourseNum;
	  cout << "\nCourse Name:   ";
	  cout << StCollection[index].StdInfo.Course5.CourseName;
	  cout << endl;
        }

      //cout << StCollection.size();
      cout << endl;
    }

  inputFile.close();
  
  return 0;
}
