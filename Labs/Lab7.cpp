// Lab7 

#include "CompSciProfessor.h"
#include "AdjunctProf.h"
#include "TenureTrackProf.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
  AdjunctProf AP("Adam Smith", "asmith@csusm.edu", 12345, ' ', 0, 0);
  AP.AdjunctProf::setDegree('M');
  AP.AdjunctProf::setNoOfTA(2);
  AP.AdjunctProf::setNoOfCourses(1);
  AP.AdjunctProf::findSalary();
  AP.AdjunctProf::print();
  
  TenureTrackProf TTP("Jim Anderson", "janderson@csusm.edu", 54321, ' ', 0);
  TTP.TenureTrackProf::setRank('S');
  TTP.TenureTrackProf::setYearOfExp(8);  
  TTP.TenureTrackProf::findSalary();
  TTP.TenureTrackProf::print();  
  
  return 0;
}
