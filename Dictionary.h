
/**************************************
* The Dictionary.h file will hold all *
* the data members. Dictionary.cpp    *
* will have access to these data      *
* members and their attributes.       *
**************************************/
// Date Written: 10/24/2019
#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Dictionary
{
 private:
  const int maxWordsInDict;
  const int maxWordsPerFile;
  int totalWordsInDict;
  int numOfWordsInFile[26];
  static bool failure;
  static bool success;
  
 public:
  Dictionary();
  ~Dictionary();
  Dictionary(int dictMaxWords, int fileMaxWords);
  bool AddAWord(string word);
  bool DeleteAWord(string word);
  bool SearchForWord(string word);
  bool PrintAFileInDict(string filename);
  bool SpellChecking(string fileName);
  bool InsertWordsIntoDict(string fileName);
  void ProcessTransactionFile();
  string ToLower(string word);
  string ToUpper(string word);
};
#endif
