// Lab 6

#include <iostream>
#include <fstream>
#include <string>
#include "TheMatrix.h"
using namespace std;

class TheMatrix;

// Function Prototype Section
ifstream& operator>> (ifstream& is, TheMatrix& myMatrix);
ostream& operator<< (ostream& is, const TheMatrix& myMatrix);
TheMatrix operator+ (const TheMatrix& M1, const TheMatrix& M2);
TheMatrix operator- (const TheMatrix& M1, const TheMatrix& M2);
TheMatrix operator* (const TheMatrix& M1, const TheMatrix& M2);
TheMatrix operator/ (const TheMatrix& M1, const TheMatrix& M2);
// End of prototype section

int main()
{
  TheMatrix A, B, AddAB, MulAB, SubAB, DivAB;
  ifstream fin1, fin2;

  fin1 >> A;  // This code calls the function operator>> to grab information from a file and place it into Matrix A  
  fin2 >> B;  // This code calls the function operator>> to grab information from a file and place it into Matrix B  
  
  // call a function to operator+  to add Matrix A and B together and place the result into Matrix AddAB
  // call a function to operator-  to subtract Matrix A from Matrix B  and place the result into Matrix SubAB
  // call a function to operator*  to multiply Matrix A and B together and place the result into Matrix MulAB
  // call a function to operator+  to divide Matrix A by matrix B and place the result into Matrix DivAB
  AddAB = A + B;
  SubAB = A - B;
  MulAB = A * B;
  DivAB = A / B;
  
  // call the function operator<< to print matrix A
  cout << "\nfile1 contains";
  cout << "\n--------------";
  cout << A << endl;

  // call the function operator<< to print matrix B
  cout << "\nfile2 contains";
  cout << "\n--------------";
  cout << B << endl;

  // call the function operator<< to print matrix AddAB
  cout << "\nAddition Matrix";
  cout << "\n---------------";
  cout << AddAB << endl;

  // call the function operator<< to print matrix SubAB
  cout << "\nSubtraction Matrix";
  cout << "\n------------------";
  cout<< SubAB << endl;

  // call the function operator<< to print matrix MulAB
  cout << "\nMultiplication Matrix";
  cout << "\n---------------------";
  cout << MulAB << endl;

  // call the function operator<< to print matrix DivAB
  cout << "\nDivision Matrix";
  cout << "\n---------------";
  cout << DivAB << endl << endl;

  return 0;
}
