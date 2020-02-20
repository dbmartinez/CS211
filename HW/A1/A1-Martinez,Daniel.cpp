/*******************************************************
* The purpose of this assignment is to encrypt/decrypt *
* of a text file. The first part will be encrypting a  * 
* text file using a rotation method in which a user    *
* chooses a key# to rotate and also decrypts it. Then  *
* using the same method but using a cyptogram method,  *
* in which a key(26 letters) are given to us to        *
* encrypt a message then decrypt it.                   *
* ----Output----                                       *
* ~encrypt Original.txt file to EncryptRot.txt         *
* ~decrypt Original.txt file to DecryptRot.txt         *
* ~encrypt Original.txt file to EncryptCrypto.txt      *
* ~decrypt Original.txt file to DecryptCrypto.txt      *
*******************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cctype>
#include <string>
using namespace std;

// Function Prototypes
int DriverProgram();
string getOriginalFileName();
vector<string> PlaceOriginalInVector(const string&);
vector<string> EncVecUsingRot(const vector<string>&);
int getRotNum();
string DoEncRot(string, int);
string lowerLetter(string);
vector<string> DecVecUsingRot(const vector<string>&);
string DoDecRot(string, int);
vector<string> EncVecUsingCrypto(const vector<string>&);
string getCryptoFile();
string DoEncCrypt(string, string);
vector<string> DecVecUsingCrypto(const vector<string>&);
string DoDecCrypt(string, string);

/*************************************************
* The int main function will create four vectors *   
* then will be passed into four more vectors     *
* later in the program.                          *   
* Will call the getOriginalFileName() function   *
* to open the Original.txt file from the user    *
* the string OriginalFile will hold the info.    *
* Will call the DriverProgram() to get the users *    
* choice and then using a switch statement to    *
* choose what the user selected and sending it   *
* to its proper function. It will continue to    *
* repeat until the user quits the program.       *
*************************************************/
// Date Written: 09/26/2019
int main()
{
  // Local variables
  string OriginalFile;
  int last;
  bool done = false;  
  vector<string> EncVecRot, DecVecRot, EncVecCrypto, DecVecCrypto;

  // Call the getOriginalFileName function
  OriginalFile = getOriginalFileName();
  
  cout << "\nThe name of the file is: " << OriginalFile << endl;
  vector<string> OriginalVector =  PlaceOriginalInVector(OriginalFile);
  last = OriginalVector.size() - 1;
  
  while(!done)
  {
    // Local variable
    int choice;
      
    // Call DriverProgram to get choice
    choice = DriverProgram();
    
    // Using switch statement from when the user chooses
    // Calling the function from the selection the user chooses 
    switch(choice)
    {
      case 1:
        cout << "\nEncrypt using Rot";
        cout << "\n-----------------";
	EncVecRot = EncVecUsingRot(OriginalVector);
	break;
	  
      case 2:
	cout << "\nDecrypt using Rot";
	cout << "\n-----------------";
	DecVecRot = DecVecUsingRot(EncVecRot);
	break;
	  
      case 3:
	cout << "\nEncrypt using Crypto";
	cout << "\n--------------------";
	EncVecCrypto = EncVecUsingCrypto(OriginalVector);
	break;
	  
      case 4:
	cout << "\nDecrypt using Crypto";
	cout << "\n--------------------";
	DecVecCrypto = DecVecUsingCrypto(EncVecCrypto);
	break;
	  
      default:
	cout << "\nProgram Terminated.\n" << endl;
	return 1;
	break;
    }    
  }

  return 0;
}

/******************************************* 
* The purpose of the function is to obtain *   
* the file Original.txt and to see if it   * 
* opens properly then returns it. string   *
* filename will be used to hold the name   *
* of the file Original.txt                 *
*******************************************/
// Date Written: 09/26/2019
string getOriginalFileName() 
{
  // Local variables
  string fileName;
  bool done = false;
  
  while(!done)
  {
    cout << "\nPlease enter name of the original file: ";
    cin >> fileName;
      
    ifstream inputFile;
    inputFile.open(fileName.data());
      
    if(inputFile.fail())
    {
      cout << "\nThe file name doesn't exist. Try again: " << endl;
    }
      
    else
    {
      done = true;
    }
  }
  
  return fileName;
}

/*************************************************************** 
* This vector function will pass the Original.txt file that is *
* stored in OriginalFile by reference and also constant so it  *
* cannot be changed. It will also store it in another vector   *
* called Vec.                                                  * 
****************************************************************/
// Date Written: 09/26/2019
vector<string> PlaceOriginalInVector(const string& OriginalFile)
{
  // Local variables
  string word;
  vector<string> Vec;
  
  ifstream inputFile;
  inputFile.open(OriginalFile.data());
  
  while(inputFile >> word)
  {
    Vec.push_back(word);
  }
  
  return Vec;
}

/*****************************************************
* Driver Program is the routine that will display    *
* the menu to the user in which the user will pick   *
* a choice from the menu. If the user doesn't choose *
* between 1-5 then it will repeat till the user      *
* chooses correctly.                                 *
*****************************************************/
// Date Written: 09/26/2019
int DriverProgram()
{
  // Local variables
  int choice;
  char repeat;
  bool done = false;

  while(!done)
  {
    cout << "\n\t--------------";
    cout << "\n\tMenu Selection";
    cout << "\n\t--------------";
      
    cout << "\n1: Encrypt using Rot method";
    cout << "\n2: Decrypt using Rot method";
    cout << "\n3: Encrypt using Crypto method";
    cout << "\n4: Decrypt using Crypto method";
    cout << "\n5: Quit Program";

    cout << "\n\nEnter Choice: ";
    cin >> choice;
      
    // If user enters wrong choice from menu
    if(choice >= 1 || choice <= 5)
    {
      done = true;
    }

    else
    {
      cout << "\nTry a number between 1 and 5 as shown above\n";
    }
  } 
  
  return choice;
}

/**********************************************************************
* This function will pass OriginalVector which holds the Original.txt *
* which is still constant so it doesn't change. Variables EncWord     *
* will hold encrypted message and will send it to new file. The vari- *
* able Rot will hold the key from when the user entered.              *
* Call the DoEncRot function and send in the Original.txt and key     *
* to that function to be encrypted and use vector to push back info-  *
* rmation and send it to "EncryptRot.txt"                             *
**********************************************************************/
// Date Written: 09/26/2019
vector<string> EncVecUsingRot(const vector<string>& OriginalVector)
{
  // Local variables
  string EncWord;
  int Rot;
  ofstream outputFile;
  outputFile.open("EncryptRot.txt");
  
  // Call getRotNum function
  Rot = getRotNum();
  
  cout << "\nEncrypt Vector using Rot.\n";
  vector<string> EncVec;

  // Send info to the outputFile("EncryptRot.txt")
  for(int index = 0; index < OriginalVector.size(); index++)
  {
    EncWord = DoEncRot(OriginalVector[index], Rot);
    EncVec.push_back(EncWord);
    outputFile << EncWord << " ";
  }
  
  return EncVec;
}

/********************************************** 
* The function getRotNum will be called to    * 
* obtain a key from the user to set up the    *
* rotation of the letters in the Original.txt *                                                            
* file also using a while loop to make sure   *
* the user correctly chooses between 1-25.    * 
**********************************************/
// Date Written: 09/26/2019
int getRotNum()
{
  // Local variable
  int Rot;
  
  // Check boundary
  while(Rot < 1 || Rot > 25)
  {
    cout << "\nEnter Encryption key(1-25): ";
    cin >> Rot; 
  }
  
  return Rot;
}

/************************************************ 
* The function DoEncRot will pass string word   *
* which holds the Original.txt file and int Rot * 
* which holds the key the user inputed. This    *
* function will do the encryption also sending  *
* the string to lowerLetter to lowercase it.    *
************************************************/
// Date Written: 09/27/2019
string DoEncRot(string word, int Rot)
{
  // Local variables
  int EncIndex;
  string EncWord;
 
  // Call lowerLetter function & set it to EncWord
  word = lowerLetter(word);
  EncWord = word;
  
  // Encryption of data using Rot method
  for(int index = 0; index < EncWord.size(); index++)
  {
    if(EncWord[index] >= 'a' && EncWord[index] <= 'z')
    {
      EncIndex = EncWord[index];
      EncIndex += Rot;
	  
      if(EncIndex > 'z')
      {
        EncIndex -= 26;
      }
	  
      EncWord[index] = EncIndex;
    }
  }
  
  return EncWord;
}

/********************************************** 
* The function lowerLetter will only turn     * 
* uppercase letters to lowercase letters so   *
* uppercase letter can be encrypted. This     * 
* function will be used throughout the        *
* program. Use for loop to go through each    *
* index and lowercase it by using the tolower *
* function.                                   * 
**********************************************/
// Date Written: 09/27/2019
string lowerLetter(string word)
{
  for(int index = 0; index < word.size(); index++)
  {
    word[index] = tolower(word[index]);
  }

  return word;
}

/**********************************************************************
* This function will pass OriginalVector which holds the Original.txt *
* which is still constant so it doesn't change. Variables DecWord     *
* will hold encrypted message and will send it to new file. The vari- *
* able Rot will hold the key from when the user entered.              *
* Call the DoDecRot function and send in the Original.txt and key     *
* to that function to be encrypted and use vector to push back info-  *
* rmation and send it to "DecryptRot.txt"                             *
**********************************************************************/
// Date Written: 09/30/2019
vector<string> DecVecUsingRot(const vector<string>& OriginalVector)
{
  // Local variables
  int Rot;
  string DecWord;
  ofstream outputFile;
  outputFile.open("DecryptRot.txt");
  
  // Call getRotNum function
  Rot = getRotNum();
  
  cout << "\nDecrypt Vector using Rot.\n";
  vector<string> DecVec;
  
  // Send info to the outputFile("DecryptRot.txt")  
  for(int index = 0; index < OriginalVector.size(); index++)
  {
    DecWord = DoDecRot(OriginalVector[index], Rot);
    DecVec.push_back(DecWord);
    outputFile << DecWord << " ";
  }
  
  return DecVec;
}

/********************************************** 
* The function DoDecRot will decrypt the      *
* encrypted file and to rotate back to its    *
* original text with a key. The function will *
* pass string word which holds the enrypted   *
* text and int Rot which holds the key the    *
* user inputed.                               *
**********************************************/
// Date Written: 10/01/2019
string DoDecRot(string word, int Rot)
{
  // Local variable
  int DecIndex;
  string DecWord;
  DecWord = word;
  
  // Decrypting the data using Rot method
  for(int index = 0; index < DecWord.size(); index++)
  {
    if(DecWord[index] >= 'a' && DecWord[index] <= 'z')
    {
      DecIndex = DecWord[index];
      DecIndex -= Rot;
	  
      if(DecIndex < 'a')
      {
        DecIndex += 26;
      }
	  
      DecWord[index] = DecIndex;
    }
  }
  
  return DecWord;
}

/**********************************************************************
* This function will pass OriginalVector which holds the Original.txt *
* which is still constant so it doesn't change. Variables EncWord     *
* will hold the  message and will send it to new file. The variable   *
* EncWordCrypt will hold the key from CryptoKey.                      *
* Call the DoEncCrypt function and send in the Original.txt and key   *
* to that function to be encrypted and use vector to push back info-  *
* rmation and send it to "EncryptCrypto.txt"                          *
**********************************************************************/
// Date Written: 10/03/2019
vector<string> EncVecUsingCrypto(const vector<string>& OriginalVector)
{
  // Local Variables
  string EncWord;
  string EncWordCrypt;
  ofstream outputFile;
  outputFile.open("EncryptCrypto.txt");
  
  // Call getCryptoFile
  EncWordCrypt = getCryptoFile();

  cout << "\nEncrypt Vector using crypto." << endl;
  vector<string> EncVecCrypt;

  // Send info to the outputFile("EncryptCrypto.txt")
  for(int index = 0; index < OriginalVector.size(); index++)
  {
    EncWord = DoEncCrypt(OriginalVector[index], EncWordCrypt);
    EncVecCrypt.push_back(EncWord);
    outputFile << EncWord << " ";
  }

  return EncVecCrypt;
}

/********************************************* 
* This function getCryptoFile will open the  *
* file CryptoKey and sends it to a string    *
* variable called crypt and to also check to *
* see if the file exists and then returns    *
* crypt.                                     *  
*********************************************/
// Date Written: 10/04/2019
string getCryptoFile()
{
  // Local variables
  string crypt;
  ifstream inputFile;
  inputFile.open("CryptoKey.txt");

  if(inputFile.fail())
  {
    cout << "\nThe file name doesn't exist. Try again: " << endl;
  }
  
  else
  {
    inputFile >> crypt;
  }  

  return crypt;
}

/********************************************** 
* This function will pass the Original.txt to * 
* string word and Cryptokey to string crypt   *
* and will do the encryption of the Original- * 
* .txt                                        *
**********************************************/
// Date Written: 10/04/2019
string DoEncCrypt(string word, string crypt)
{
  // Local variables
  int encIndex;
  string key;
  key = crypt;
  string encWord;

  // Call lowerLettter function 
  word = lowerLetter(word);
  encWord = word;
  
  // Encrypting data using CryptoKey method
  for(int index = 0; index < encWord.size(); index++)
  { 
    if(encWord[index] >= 'a' && encWord[index] <= 'z')
    {
      encIndex = encWord[index] - 'a';
      encWord[index] = key[encIndex];
    }
  }

  return encWord;
}

/**********************************************************************
* This function will pass OriginalVector which holds the Original.txt *
* which is still constant so it doesn't change. Variables DecWord     *
* will hold decrypted message and will send it to new file. The vari- *
* able DecWordCrypt will hold the key from CryptoKey.                 *
* Call the DoDecCrypt function and send in the Original.txt and key   *
* to that function to be decrypted and use vector to push back info-  *
* rmation and send it to "DecryptCrypto.txt"                          *
**********************************************************************/
// Date Written: 10/06/2019
vector<string> DecVecUsingCrypto(const vector<string>& OriginalVector)
{
  // Local variables
  string DecWord;
  string DecWordCrypt;
  ofstream outputFile;
  outputFile.open("DecryptCrypto.txt");
  
  // Call getCryptoFile
  DecWordCrypt = getCryptoFile();

  cout << "\nDecrypt Vector using crypto.\n";
  vector<string> DecVecCrypt;

  // Send info to the outputFile("DecryptCrypto.txt")
  for(int index = 0; index < OriginalVector.size(); index++)
  {
    DecWord = DoDecCrypt(OriginalVector[index], DecWordCrypt);
    DecVecCrypt.push_back(DecWord);
    outputFile << DecWord << " ";
  }
	      
  return DecVecCrypt;
}

/************************************************
* This function will pass the encrypted message *
* to string word and the key to string crypt,   *
* then decrypt the message back to it original  *     
* text which is Original.txt                    *
************************************************/
// Date Written: 10/06/2019
string DoDecCrypt(string word, string crypt)
{
  // Local Variables
  int decIndex;
  char letter;
  string key;
  key = crypt;
  string decWord;
  decWord = word;
  
  // Decrypting data using Cryptokey method
  for(int index = 0; index < decWord.size(); index++)
  {
    if(decWord[index] >= 'a' && decWord[index] <= 'z')
    {
      letter = decWord[index];

      for(int Index = 0; Index < key.size(); Index++)
      {
        if(key[Index] == letter)
        {
	  decIndex = Index;
	  break;
        }
      }

      decWord[index] = 'a' + decIndex;
    }
  }

  return decWord;
}
