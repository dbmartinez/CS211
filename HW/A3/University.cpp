// University.cpp

#ifndef UNIVERSITY_CPP
#define UNIVERSITY_CPP
#include "University.h"
#include <iomanip>
using namespace std;

bool University::failure = false;
bool University::success = true;

//----------------------------------------------------------------------------
University::University()
{

}
//----------------------------------------------------------------------------

University::~University()
{

}

/*
  - If the depChairId is 0, it means the chair is not known yet; otherwise, you need
    to check if the depChairId passed to this method is a valid existing faculty.
    print appropriate message and return failure if the chair is not valid

*/
bool University::CreateNewDepartment(string depName, string depLoc, long depChairId)
{
  if(depChairId != 0 && !chairExists(depChairId))
  {
    cout << "\nDepartment chair ID " << depChairId << " doesn't exist.\n";
    return(University::failure);
  }
  
  Department newDept(depName, depLoc, depChairId);
  Departments.push_back(newDept);

  return(University::success);
}
//----------------------------------------------------------------------------

bool University::RemoveADepartment(long depId)
{
  // OPTIONAL
}

/*
  - If the sMajor is 0, it means the student has not chosen a major; otherwise, you need
    to check if the sMajor passed to this method is a valid existing department name.
    print appropriate message and return failure if this is not the case

  - If the sAdvisorId is 0, it means the student has not chosen an advisor or does not need 
    an advisor; otherwise, you need to check if the sAdvisorId passed to this method 
    is a valid existing faculty id. Print appropriate message and return failure if this is not the case

*/
bool University::CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId)
{
  //check if major and advisor exist
  if(sMajor != " " && !majorExists(sMajor))
  {
    cout << "\nMajor " << sMajor << " is unknown.\n" << endl;
    return(University::failure);
  }

  if(sAdvisorId == 0 && !facultyExists(sAdvisorId))
  {
    cout << "\nAdvisor " << sAdvisorId << " is unknown.\n" << endl;
    return(University::failure);
  }

  Student newStudent(sName, sEmail, sAddress, sDateOfBirth, sGender, sYearOfStudy, sMajor, sAdvisorId);
  Students.push_back(newStudent);
  
  return(University::success);
}
//----------------------------------------------------------------------------

bool University::RemoveAStudent(long sStId)
{
  // OPTIONAL
}

/*
  - If the cTaughtBy is 0, it means no one is assigned to teach this course. 
    otherwise, you need to check if the cTaughtBy passed to this method is a 
    valid existing faculty. Print appropriate message and return failure if 
    this is not the case

  - you need to check if the cDepId passed to this method is a valid existing department. 
    Print appropriate message and return failure if this is not the case

*/
bool University::CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat)
{
  //check if faculty and department exist.
  if(cTaughtBy != 0 && !facultyExists(cTaughtBy))
  {
    cout << "\nFaculty " << cTaughtBy << " doesnt't exist.\n";
    return(University::failure);
  }

  if(!deptExists(cDepId))
  {
    cout << "\nDepartment " << cDepId << " doesn't exist.\n";
    return(University::failure);
  }

  Course newCourse(cName, cDepId, cTaughtBy, cMaxSeat);
  Courses.push_back(newCourse);
  
  return(University::success);
}
//----------------------------------------------------------------------------

bool University::RemoveACourse(long cCRN)
{
  // OPTIONAL
}


bool University::CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId)
{
  //check if department exists.
  if(!deptExists(fDepId))
  {
    cout << "Department " << fDepId << " doesn't exist.\n";
    return(University::failure);
  }

  Faculty newFaculty(fName, fEmail, fAddress, fDateOfBirth, fGender, fSalary, fYearOfExp, fDepId);
  Faculties.push_back(newFaculty);
  
  return(University::success);
}
//----------------------------------------------------------------------------

bool University::RemoveAFaculty(long fFactId)
{
  // OPTIONAL
}

/*
  - This routine lists all the courses (courseId and CourseName)
    that are currently being taught 
  - The facultyId passed to this method is a valid existing 
    faculty id. If this is not the case print appropriate message and return failure; 
    otherwise, return success
*/
bool University::ListCoursesTaughtByFaculty(long facultyId)
{
  //check if faculty exists.
  if(facultyId == 0 || !facultyExists(facultyId))
  {
    cout << "\nNo courses available for faculty " << facultyId << ".\n";
    return(University::failure);
  }

  for(int x = 0; x < Courses.size(); x++)
  {
    if(Courses[x].isTaughtBy == facultyId)
      cout << Courses[x].CRN << "\t" << Courses[x].name << endl;
  }

  return(University::success);
}

/*
  - This routine lists all the courses (courseId and CourseName) 
    that currently taken by a particular student
  - The studentId passed to this method is a valid existing 
    student id. Then prints appropriate message and return failure; 
    otherwise, return success
*/
bool University::ListCoursesTakenByStudent(long studentId)
{
  //check if student exists.
  if(studentId == 0 || !studentExists(studentId))
  {
    cout << "\nStudent " << studentId << " not found.\n";
    return(University::failure);
  }

  for(int x = 0; x < Students.size(); x++)
  {
    if(Students[x].id == studentId)
    {
      for(int y = 0; y < Students[x].coursesTaken.size(); y++)
      {
	cout << Students[x].coursesTaken[y].CRN << "\t" << Students[x].coursesTaken[y].name;
	cout << endl;
      }
    }
  }
 
  return(University::success);
}

/*
  - This routine lists all the faculties (facultyId, facultyName) in a particular 
    department
  - The departId passed to this method is a valid existing department id. 
    If this is not the case print appropriate message and return failure; 
    otherwise, return success
*/
bool University::ListFacultiesInDepartment(long departId)
{
   //check if department exists.
  if(!deptExists(departId))
  {
    cout << "\nDepartment " << departId << " not found.\n";
    return(University::failure);
  }
  
  for(int x = 0; x < Faculties.size(); x++)
  {
    if(Faculties[x].departId == departId)
      cout << Faculties[x].id << "\t" << Faculties[x].name << endl;
  }

  return(University::success);
}

/*
  - This routine lists all the students (studentId and studentName) of a particular 
    faculty
  - The facultyId passed to this method is a valid existing faculty id. 
    If this is not the case print appropriate message and return failure; otherwise, 
    return success	  
*/
bool University::ListStudentsOfAFaculty(long facultyId)
{
  //check if faculty exists.
  if(!facultyExists(facultyId))
  {
    cout << "\nFaculty " << facultyId << " not found.\n";
    return(University::failure);
  }

  //check the courses of each student for facultyId.
  for(int x = 0; x < Students.size(); x++)
  {
    for(int y = 0; y < Students[x].coursesTaken.size(); y++)
    {
      if(Students[x].coursesTaken[y].isTaughtBy == facultyId)
	cout << Students[x].id << "\t" << Students[x].name << endl;
    }
  }

  return(University::success);
}

/*
  - This routine lists all the courses offered by a particular department
  - The departId passed to this method is a valid existing department id.
    If this is not the case print appropriate message and return failure; otherwise, 
    return success
*/
bool University::ListCoursesOfADepartment(long departId)
{
  //check if department exists.
  if(!deptExists(departId))
  {
    cout << "\nDepartment " << departId << " not found.\n";
    return(University::failure);
  }

  for(int x = 0; x < Courses.size(); x++)
  {
    if(Courses[x].departId == departId)
      cout << Courses[x].CRN << "\t" <<  Courses[x].name << endl;
  }

  return(University::success);
}

/*
  - This routine adds a course for a student
  - When you add a course for a student, you need to ensure that there is enough seat in that class
    Increment the number of assigned seats if you could enroll the student for this course
  - make sure that the courseId and stId passed to this method are both valid 
    If this is not the case print appropriate message and return failure; otherwise, 
    return success
*/
bool University::AddACourseForAStudent(long courseId, long stId)
{
  //check if course and student exist.
  if(!courseExists(courseId))
  {
    cout << "\nCourse " << courseId << " not found.\n";
    return(University::failure);
  }

  if(!studentExists(stId))
  {
    cout << "\nStudent " << stId << " not found.\n";
    return(University::failure);
  }

  //check through list of all courses.
  for(int x = 0; x < Courses.size(); x++)
  {
    if(Courses[x].CRN == courseId)
    {
      //check if course is full.
      if(Courses[x].assignedSeats < Courses[x].maxAvailableSeats)
      {
	for(int y = 0; y < Students.size(); y++)
	{
	  if(Students[y].id == stId)
	    Students[y].coursesTaken.push_back(Courses[x]);

	  Courses[x].assignedSeats++;
	  return(University::success);
	}
      }
    }
  }
}

/*
  - This routine drops a course for a student
*/
bool University::DropACourseForAStudent(long courseId, long stId)
{
  //check if course and student exist.
  if(!courseExists(courseId))
  {
    cout << "\nCourse " << courseId << " not found.\n";
    return(University::failure);
  }

  if(!studentExists(stId))
  {
    cout << "\nStudent " << stId << " not found.\n";
    return(University::failure);
  }

  //check through list of all students.
  for(int x = 0; x < Students.size(); x++)
  {
    if(Students[x].id == stId)
    {
      //check each student's list of courses.
      for(int y = 0; y < Students[x].coursesTaken.size(); y++)
      {
	if(Students[x].coursesTaken[y].CRN == courseId)
	{
	  Students[x].coursesTaken.erase(Students[x].coursesTaken.begin() + y);
	  
	  for(int z = 0; z < Courses.size(); z++)
	  {
	    if(Courses[z].CRN == courseId)
	      Courses[z].assignedSeats--;
	  }
	}
      }
    }
  }

  return(University::success);
}

/*
  - This routine assigns a chair to a department
  - it sure that the facultyId and departId passed to this method are both valid 
    If this is not the case print appropriate message and return failure; otherwise, 
    return success
*/

bool University::AssignDepartmentChair(long facultyId, long departId)
{
  //check if facutly and department exist
  if(!facultyExists(facultyId))
  {
    cout << "\nFaculty " << facultyId << " not found.\n";
    return(University::failure);
  }

  if(!deptExists(departId))
  {
    cout << "\nDepartment " << departId << " not found.\n";
    return(University::failure);
  }

  for(int x = 0; x < Departments.size(); x++)
  {
    if(Departments[x].id == departId)
      Departments[x].chairId = facultyId;
  }

  return(University::success);
}

/*
  - This routine assigns a course to an instructor to teach
  - and that the courseId, facultyId passed to this method are both valid.
    If this is not the case print appropriate message and return failure; otherwise, 
    return success
*/
bool University::AssignInstructorToCourse(long facultyId, long courseId)
{
  //check if faculty and course exist.
  if(!facultyExists(facultyId))
  {
    cout << "\nFaculty " << facultyId << " not found.\n";
    return(University::failure);
  }

  if(!courseExists(courseId))
  {
    cout << "\nCourse " << courseId << " not found.\n";
    return(University::failure);
  }

  for(int x = 0; x < Courses.size(); x++)
  {
    if(Courses[x].CRN == courseId)
      Courses[x].isTaughtBy = facultyId;
  }
}

/*
  - This method lists the departments id's and names
*/
bool University::ListDepartments()
{
  for(int x = 0; x < Departments.size(); x++)
  {
    cout << left << setw(16) << Departments[x].id; 
    cout << Departments[x].name << endl;
  }
}

/*
  - This method lists the students id's and names
*/
bool University::ListStudents()
{
  for(int x = 0; x < Students.size(); x++)
  {
    cout << left << setw(8) << Students[x].id;
    cout << Students[x].name << endl;
  }
}

/*
  - This method lists the courses id's and names
*/
bool University::ListCourses()
{
  for(int x = 0; x < Courses.size(); x++)
    cout << Courses[x].CRN << "\t" << Courses[x].name << endl;
}

/*
  - This method lists the faculties id's and names
*/
bool University::ListFaculties()
{
  for(int x = 0; x < Faculties.size(); x++)
  {
    cout << left << setw(8) << Faculties[x].id;
    cout << Faculties[x].name << endl;
  }
}

/*
  - open the transaction file and process it one by one
  - If the file could not be opened, print appropriate message and return failure;
    otherwise, return success
*/
bool University::ProcessTransactionFile(string fileName)
{
  ifstream inputFile;
  string command, fName, fEmail, fAddress, fDateOfBirth, fGender, sName, sEmail, sAddress, sDateOfBirth, sGender, depName, depLoc, sMajor, cName;
  long depChair, fSalary, fDepId, departId, sAdvisorId, facId, cDeptId, cTaughtBy, sId, cId;
  int fYearOfExp, sYearOfStudy, cMaxSeats;

  inputFile.open(fileName.data());
  
  if(!inputFile)
  {
    cout << "\nCannot open file...\n";
    return(University::failure);
  }
  
  cout << endl;

  while(inputFile >> command)
  {
    if(command == "CreateNewDepartment")
    {
      inputFile >> depName >> depLoc >> depChair;
      cout << "Creating department: " << depName << endl;
      CreateNewDepartment(depName, depLoc, depChair);
    }

    else if(command == "ListDepartments")
    {
      cout << "Current Departments:\n";
      cout << "--------------------\n";
      cout << "Course Number\tCourse Name\n";
      cout << "------------------------------\n";
      ListDepartments();
      cout << endl;
    }

    else if(command == "CreateNewFaculty")
    {
      inputFile >> fName >> fEmail >> fAddress >> fDateOfBirth >> fGender >> fSalary >> fYearOfExp >> fDepId;
      CreateNewFaculty(fName, fEmail, fAddress, fDateOfBirth, fGender, fSalary, fYearOfExp, fDepId);
    }

    else if(command == "ListFaculties")
    {
      cout << "\nCurrent Faculty:\n";
      cout << "----------------\n";
      cout << "ID\tName\n";
      cout << "--------------------------\n";
      ListFaculties();
      cout << endl;
    }

    else if(command == "ListFacultiesInDepartment")
    {
      inputFile >> departId;
      cout << "Faculty in Department " << departId << ".\n";
      ListFacultiesInDepartment(departId);
      cout << endl;
    }

    else if(command == "CreateNewStudent")
    {
      inputFile >> sName >> sEmail >> sAddress >> sDateOfBirth >> sGender >> sYearOfStudy >> sMajor >> sAdvisorId;
      CreateNewStudent(sName, sEmail, sAddress, sDateOfBirth, sGender, sYearOfStudy, sMajor, sAdvisorId);
    }

    else if(command == "ListStudents")
    {
      cout << "Current Students:\n";
      cout << "-----------------\n";
      cout << "ID\tName\n";
      cout << "--------------------------\n";
      ListStudents();
      cout << endl;
    }

    else if(command == "ListStudentsOfAFaculty")
    {
      inputFile >> facId;
      cout << "\nCurrent Students of Faculty " << facId << ":\n";
      ListStudentsOfAFaculty(facId);
      cout << endl;
    }

    else if(command == "CreateNewCourse")
    {
      inputFile >> cName >> cDeptId >> cTaughtBy >> cMaxSeats;
      CreateNewCourse(cName, cDeptId, cTaughtBy, cMaxSeats);
    }

    else if(command == "ListCourses")
    {
      cout << "\nCurrent Courses";
      cout << "\n---------------\n";
      ListCourses();
      cout << endl;
    }

    else if(command == "ListCoursesTaughtByFaculty")
    {
      inputFile >> facId;
      cout << "Courses Taught by Faculty " << facId << ":\n";
      ListCoursesTaughtByFaculty(facId);
      cout << endl;
    }

    else if(command == "ListCoursesOfADepartment")
    {
      inputFile >> departId;
      cout << "\nCurrent Courses in Department " << departId << ":\n";
      ListCoursesOfADepartment(departId);
    }

    else if(command == "AddACourseForAStudent")
    {
      inputFile >> cId >> sId;
      AddACourseForAStudent(cId, sId);
    }

    else if(command == "ListCoursesTakenByStudent")
    {
      inputFile >> sId;
      cout << "\nCurrent Courses for Student " << sId << ":\n";
      ListCoursesTakenByStudent(sId);
    }

    else if(command == "DropACourseForAStudent")
    {
      inputFile >> cId >> sId;
      DropACourseForAStudent(cId, sId);
    }

    else if(command == "AssignDepartmentChair")
    {
      inputFile >> facId >> departId;
      AssignDepartmentChair(facId, departId);
    }

    else if(command == "AssignInstructorToCourse")
    {
      inputFile >> facId >> cId;
      AssignInstructorToCourse(facId, cId);
    }
  }
}

bool University::chairExists(long depChairId)
{
  for(int x = 0; x < Faculties.size(); x++)
  {
    if(Faculties[x].id == depChairId)
      return(University::success);
  }

  return(University::failure);
}

bool University::majorExists(string sMajor)
{
  for(int x = 0; x < Departments.size(); x++)
  {
    if(Departments[x].name == sMajor)
      return(University::success);
  }

  return(University::failure);
}

bool University::facultyExists(long fFacId)
{
  for(int x = 0; x < Faculties.size(); x++)
  {
    if(Faculties[x].id == fFacId)
      return(University::success);
  }
  return(University::failure);
}

bool University::deptExists(long depId)
{
  for(int x = 0; x < Departments.size(); x++)
  {
    if(Departments[x].id == depId)
      return(University::success);
  }

  return(University::failure);
}

bool University::studentExists(long sId)
{
  for(int x = 0; x < Students.size(); x++)
  {
    if(Students[x].id == sId)
      return(University::success);
  }

  return(University::failure);
}

bool University::courseExists(long cId)
{
  for(int x = 0; x < Courses.size(); x++)
  {
    if(Courses[x].CRN == cId)
      return(University::success);
  }

  return(University::failure);
}
#endif
