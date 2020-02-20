/********************************************
* Dictionary.cpp will implement the members *
* and attributes into its approraite member * 
* functions.                                *
********************************************/
// Date Written: 10/24/2019
#ifndef DICTIONARY_CPP 
#define DICTIONARY_CPP
#include "Dictionary.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
using namespace std;

// Static declaration
bool Dictionary::failure = false;
bool Dictionary::success = true;

/**************************************************
* The default constructor sets the following      *
* values to the folllowing attributes. Use a for  *
* loop to open/close A.txt to Z.txt files. Set    *
* maxWordsInDict to 10000 and maxWordsPerFile to  *
* 10.                                             *
**************************************************/
// Date Written: 10/24/2019
Dictionary::Dictionary():maxWordsInDict(10000), maxWordsPerFile(100)
{
  totalWordsInDict = 0;

  for(int index = 0; index < 25; index++)
  {
    numOfWordsInFile[index] = 0;
  }
 
}

/******************************************************
* The default constructor sets the following values   *  
* to the folllowing attributes. Use a for loop to     *  
* open/close A.txt to Z.txt files. Set maxWrodsInDict *
* maxWordsInDict to dictMaxWords and maxWordsPerFile  *
* to fileMaxWords.                                    *
******************************************************/
// Date Written: 10/24/2019
Dictionary::Dictionary(int dictMaxWords, int fileMaxWords):maxWordsInDict(dictMaxWords), maxWordsPerFile(fileMaxWords)
{
  totalWordsInDict = 0;

  for (int index = 0; index < 25; index++)
  {
    numOfWordsInFile[index] = 0; 
  }

}

/*************************************
* The destructor will decrement the  *
* attribute totalWordsInDict by one. *
*************************************/
// Date Written: 10/24/2019
Dictionary::~Dictionary()
{
  totalWordsInDict--;
}

/***********************************************
* This routine opens the appropriate file, and *
* tries to add the word that is passed to this *
* function into that file.                     *
***********************************************/
// Date Written: 10/25/2019
bool Dictionary::AddAWord(string word)
{
  // local variables
  ofstream outputFile;
  int filenumber;
  string fileName = "#.txt";
  
  //Call the function to search the word.
  bool found = SearchForWord(word);

  if(found == 1)
  {
    return (Dictionary::failure);
  }

  fileName[0] = toupper(word[0]);
  outputFile.open(fileName.data(), ios::app);

  if(!outputFile)
  {
    return(Dictionary::failure);
  }

  //Update the number of words.
  filenumber = fileName[0] - 65;

  if(numOfWordsInFile[filenumber] < maxWordsInDict)
  {
    numOfWordsInFile[filenumber]++;
  }

  outputFile << word << endl;

  outputFile.close();
  return(Dictionary::success);
} 

/************************************************
* This routine opens the appropriate file where * 
* the word that you are looking for might be    *
* kept. Then it places all the words into a     *
* vector and looks for the word in the vector.  *
* If the word is in the vector, it should be    *
* deleted and then the modified vector should   *
* be inserted back into the appropriate file.   *
************************************************/
// Date Written: 10/27/2019
bool Dictionary::DeleteAWord(string word)
{
  // local variables
  ifstream inputFile;
  ofstream outputFile;
  int filenumber;
  string temp;
  string fileName = "#.txt";
  vector<string> words;

  //Call the function to search the word.
  bool found = SearchForWord(word);

  //Return false if the word is not found.
  if(found == 1)
  {
    return(Dictionary::failure);
  }

  fileName[0] = toupper(word[0]);
  inputFile.open(fileName.data());

  if(!inputFile)
  {
    return(Dictionary::failure);
  }

  //Decrement the number of words.
  filenumber = fileName[0] - 65;

  numOfWordsInFile[filenumber]--;

  while(inputFile >> temp)
  {
    if(!inputFile.eof())
    {
      //Add the word in the vector if it not
      // the word to be deleted
      if(temp != word)
      {
        words.push_back(temp);
      }
    }
  }

  inputFile.close();
  outputFile.open(fileName.data());

  //Start the loop to write the modified data in the file.
  for(int index = 0;index < words.size(); index++)
  {
    outputFile << words.at(index) << endl;
  }

  outputFile.close();
  return(Dictionary::success);
}

/******************************************
* This routine opens the appropriate file * 
* where the word that you are looking for *
* might be kept. 
*
****************************************/
// Date Written: 10/28/2019
bool Dictionary::SearchForWord(string word)
{
  // local variables
  ifstream inputFile; 
  string temp;
  string fileName = "#.txt";
  
  fileName[0] = toupper(word[0]);

  inputFile.open(fileName.data());

  if(!inputFile)
  {
    cout << "\nCannot open file..." << endl;
    return(Dictionary::failure);
  }

  else
  {
    while(inputFile >> temp)
    {
      if(temp == word)
      {
        return(Dictionary::success);
      } 
    }
  }

  return(Dictionary::failure);
}

/****************************************
* This routine opens the file fileName, * 
* read the words one by one and print   *
* them on the screen.                   *
****************************************/
// Date Written: 10/30/2019
bool Dictionary::PrintAFileInDict(string filename)
{
  // local variables
  ifstream inputFile;
  string word;
  int count = 0;

  inputFile.open(filename.data());

  if(!inputFile)
  {
    cout << "\nCannot open file..." << endl; 
    return(Dictionary::failure);
  }

  else
  {
    cout << "\nThe file " << filename;
    cout << " contains the following words";
    cout << "\n-----------------------------";
    cout << "--------------\n";

    while(inputFile >> word)
    {
      count++;
      cout << word << " ";
      
      if(count % 5 == 0)
      {
	cout << endl;
      }
    }

    cout << endl;
    inputFile.close();
    return(Dictionary::success);
  }
}

/**********************************************
* SpellChecking function will open the string *
* fileName then reads the words one by one    *
* and insert them into the dictionary fileNa- *
* me will open a file called inputFile and w- *
* ill insert them into string word. Also dis- *
* play misspelled words.                      * 
**********************************************/
// Date Written: 10/28/2019
bool Dictionary::SpellChecking(string fileName)
{
  // local variables
  ifstream inputFile;
  string word;
  bool found;

  inputFile.open(fileName.data());

  if(!inputFile)
  {
    cout << "\nCannot find file..." << endl;
    return(Dictionary::failure);
  }

  else
  {
    cout << "\nMisspelled Words";
    cout << "\n----------------\n";


    while(inputFile >> word)
    {
      found = SearchForWord(word);

      if(found == failure)
      {
	cout << word << endl;
      }
    } 

    inputFile.close();
    return(Dictionary::success);
  }
}

/*******************************************************
* InsertWordsIntoDict function will open the fileName  *
* then reads the words one by one and insert them into *
* the dictionary fileName will open a file called inp- * 
* utFile and will insert to string word.               *
*******************************************************/
// Date Written: 10/30/2019
bool Dictionary::InsertWordsIntoDict(string fileName)
{
  // local variables
  ifstream inputFile;
  bool found;
  string word;

  inputFile.open(fileName.data());

  if(!inputFile)
  {
    cout << "\nCannot open file..." << endl;

    return(Dictionary::failure);
  }

  // loop to add the words
  while(inputFile >> word)
  {
    found = AddAWord(word);
  }

  inputFile.close();
  return(Dictionary::success);
}

/***************************************************
* The ProcessTransactionFile function will ask the *
* user to open the Transaction.txt file, The first *
* information is a command telling the programmer  *
* what to do. The second information is the data   *
* associated with the command.                     *
***************************************************/
// Date Written: 10/25/2019
void Dictionary::ProcessTransactionFile()
{
  // local variables
  ifstream inputFile;
  string fileName, command, word;

  cout << "\nOpen Transaction.txt file: ";
  cin >> fileName;

  inputFile.open(fileName.data());

  if(!inputFile)
  {
    cout << "\nTransaction.txt cannot be opened..." << endl;
  }
  
  else
  {
    while(inputFile >> command >> word)
    {      
      if(command == "AddW")
      {
        AddAWord(word);
      }

      else if(command == "DeleteW")
      {
	DeleteAWord(word);
      }

      else if(command == "SearchW")
      {
        SearchForWord(word);
      }

      else if(command == "PrintF")
      {
	PrintAFileInDict(word);
      }

      else if(command == "SpellCheck")
      {
	SpellChecking(word);
      }

      else if(command == "InsertF")
      {
       InsertWordsIntoDict(word);
      }

      else
      {
	cout << "\nInvalid command " << command << endl;
      }
    }
  }

  inputFile.close();
}

/**********************************
* to set all letters to lowercase *
**********************************/
string Dictionary::ToLower(string word)
{
  string theWord = word;

  for(int index = 0; index < word.size(); index++)
  {
    theWord[index] = tolower(word[index]);
  }

  return theWord;
}

/**********************************                                                                                                                                                 * to set all letters to uppercase *      
**********************************/
string Dictionary::ToUpper(string word)
{
  string theWord = word;

  for(int index = 0; index < word.size(); index++)
  {
    theWord[index] = toupper(word[index]);
  }

  return theWord;
}
#endif



