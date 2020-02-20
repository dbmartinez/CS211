/***********************************************
* Write an object-oriented program to create a *
* dictionary.                                  *
*                                              *
* Input: The user will input a Transaction.txt *
* file with a list of commands and data.       *
*                                              *
* Output: Will display text files from S.txt,  *
* C.txt, H.txt, T.txt                          *
***********************************************/
// Date Written: 10/24/2019
#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
  Dictionary DictForCS211;
  DictForCS211.ProcessTransactionFile();
  return 0;
}
