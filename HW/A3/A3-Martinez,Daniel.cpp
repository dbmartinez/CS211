// Author: Daniel Martinez
// Email: marti931@cougars.csusm.edu
// Date Written: 11/29/2019
// Due Date: 12/05/2019
// main cpp file

/*
  Write a program that implements a small university.
  The university has the following components: 
  Department, Student, Faculty, and Course.  
*/
#include "University.h"
using namespace std;

int main() 
{
  University csusm;
  csusm.ProcessTransactionFile("TransactionFile.txt");
}

