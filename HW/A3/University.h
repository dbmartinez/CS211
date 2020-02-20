// Author: Daniel Martinez
// Email: marti931@cougars.csusm.edu
// Date Written: 12/01/2019 - 12/02/2019
// Due Date: 12/05/2019 
// University.h

#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Department.h"
#include "Student.h"
#include "Course.h"
#include "Faculty.h"
using namespace std;

class University
{
 protected:
  vector<Department> Departments;
  vector<Student> Students;
  vector<Course> Courses;
  vector<Faculty> Faculties;
  static bool failure;
  static bool success;

 public:
  University();
  ~University();
  bool CreateNewDepartment(string depName, string depLoc, long depChairId);
  bool RemoveADepartment(long depId);
  bool CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId);
  bool RemoveAStudent(long sStId);
  bool CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat);
  bool RemoveACourse(long cCRN); 
  bool CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId);
  bool RemoveAFaculty(long fFactId);
  bool ListCoursesTaughtByFaculty(long facultyId);
  bool ListCoursesTakenByStudent(long studentId);
  bool ListFacultiesInDepartment (long departId);
  bool ListStudentsOfAFaculty(long facultyId);
  bool ListCoursesOfADepartment(long departId);
  bool AddACourseForAStudent(long courseId, long stId);
  bool DropACourseForAStudent(long courseId, long stId);
  bool AssignDepartmentChair(long facultyId, long departId);
  bool AssignInstructorToCourse (long facultyId, long courseId);

  bool ListDepartments();
  bool ListStudents();
  bool ListCourses();
  bool ListFaculties();
  
  bool ProcessTransactionFile(string fileName);

  bool chairExists(long depChairId);
  bool majorExists(string sMajor);
  bool facultyExists(long fFacId);
  bool deptExists(long depId);
  bool studentExists(long sId);
  bool courseExists(long cId);
};
#endif
