// Lab 4

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Course.h"
#include "StudentProfile.h"
using namespace std;

void getStudents(vector<StudentProfile>& StCollection);

int main()
{
  vector<StudentProfile> StCollection;

  getStudents(StCollection);

  return 0;
}

// Get info from file
void getStudents(vector<StudentProfile>& StCollection)
{
  int a;
  long id, cNum1, cNum2, cNum3, cNum4, cNum5;
  string Fn, Ln, sN, cName1, cName2, cName3, cName4, cName5;
  char g;
  ifstream inputFile;
  inputFile.open("transaction2.txt");

  if(inputFile.fail())
    {
      cout << "\nError opening file...\n";
    }

  else
    {
      while(inputFile >> id)
        {
	  inputFile >> Fn >> Ln >> a >> g >> sN >> cNum1 >> cName1;
	  inputFile >> cNum2 >> cName2 >> cNum3 >> cName3;
	  inputFile >> cNum4 >> cName4 >> cNum5 >> cName5;
 
	  StudentProfile temp(id, Fn, Ln, a, g, sN, cNum1, cName1, cNum2, cName2, cNum3, cName3, cNum4, cName4, cNum5, cName5);
          StCollection.push_back(temp);

	  temp.print();
        }

      // Print
      //Person p1;
      //StCollection.print();

      //Student s3;
      //s3.print();

      //Course c3;
      //c3.print();

    }

  inputFile.close();
}
