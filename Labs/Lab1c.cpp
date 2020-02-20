// lab 3

#include <iostream>
#include <fstream>
using namespace std;

//Global Variable
const int SIZE = 5;

//Function prototypes
void fillArr(double[]);
void reverse(double[], double[]);
void printArr(double[], double[]);
double betweenArr(double[]);
int divByFive(double[]);
void divByThree(double[]);
double averageOfArr(double[]);
double minimumOfArr(double[]);
bool searchKey(double[], double);

// Main Function
int main()
{
  // Local Variables
  int div5;
  char again;
  double betArr, ave, low, key;
  double arr1[SIZE];
  double arr2[SIZE];

  //Function calls 
  fillArr(arr1);
  reverse(arr1, arr2);
  printArr(arr1, arr2);

  betArr = betweenArr(arr1);
  cout << "\nNumber(s) " << betArr << " is between 80 & 100.\n";

  div5 = divByFive(arr1);
  cout << "\nNumber(s) divisible by five is " << div5 << ".\n";

  divByThree(arr1);

  ave = averageOfArr(arr1);
  cout << "\nThe average is " << ave << ".\n";

  low =  minimumOfArr(arr1);
  cout << "\nThe lowest number is " << low << ".\n";
    
  do
  {
    //User input
    cout << "\nEnter in key: ";
    cin >> key;
    
    if(searchKey(arr1, key))
    {
      cout << "\nNumber " << key << " is in the array.\n";
    }  
  
    else
    {
      cout << "\nNumber " << key << " is not in the array.\n";
    }   

    cout << "\nWould you like to repeat? ";
    cin >> again;
    
  } while(again == 'Y' || again == 'y');
  
  cout << endl;

  return 0;
}

// Function fill the array from file
void fillArr(double arr1[])
{
  ifstream inputFile;

  inputFile.open("data2.txt");

  // Check to see if file opens
  if(inputFile.fail())
    {
      cout << "\nError opening file...";
    }

  else
    {
      //Read numbers from file into array
      for(int count = 0; count < SIZE; count++)
	{
	  inputFile >> arr1[count];
	}
    }
  
  inputFile.close();
}

// Reverse function
void reverse(double arr1[], double arr2[])
{
  //Local variable
  int end = SIZE - 1;
  int temp;
    
  //Copy array into arr2
  for(int index = 0; index < SIZE; index++)
    {
      arr2[index] = arr1[index];
    }

  //Reverse array
  for(int start = 0; start < end; start++, end--)
    {
      temp = arr2[start];
      arr2[start] = arr2[end];
      arr2[end] = temp;
    }
}

// Function print the arrays
void printArr(double arr1[], double arr2[])
{
  //Local variable
  double ave;

  cout << "\nThe array contains the values:\n";

  //Use for loop to display arr1
  for(int index = 0; index < SIZE; index++)
    {
      cout << arr1[index] << "\t";
    }

  cout << endl;
  cout << "\nThe array in reverse contains:\n";

  //Use loop to display arr2
  for(int index = 0; index < SIZE; index++)
    {
      cout << arr2[index] << "\t";
    }

  cout << endl;
}

// Function to see if between 80 & 100
double betweenArr(double nums3[])
{
  //Find values that are between 80 & 100
  for(int index = 0; index < SIZE; index++)
    {
      if(nums3[index] >= 80 && nums3[index] <= 100)
	{
	  return nums3[index];
	}
    }
}

// Function divisible by 5
int divByFive(double arr1[])
{
  int count = 0;

  //Check to see if array is divisible by five
  //Use modulus to find the remainder/ should be zero
  for(int index = 0; index < SIZE; index++)
    {
      if(static_cast<int>(arr1[index]) % 5 == 0)
	{
	  count++;
	}
    }

  return count;
}

// Function divisible by 3
void divByThree(double arr1[])
{
  cout << "\nNumber(s) divisible by three(by index) is ";

  //Check to see if array is divisible by three
  for(int count = 0; count < SIZE; count++)
    {
      if(static_cast<int>(arr1[count]) % 3 == 0)
	{
	  cout << count << " ";
	}
    }
  
  cout << endl;
}

// Average function
double averageOfArr(double arr1[])
{
  //Find average of array
  double average;
  double total = 0;

  for(int count = 0; count < SIZE; count++)
    {
      total += arr1[count];
    }

  average = total / SIZE;
  return average;
}

// Minimum function
double minimumOfArr(double arr1[])
{
  //Find the minimum of the array
  double lowest;

  lowest = arr1[0];
  for(int count = 1; count < SIZE; count++)
    {
      if(arr1[count] < lowest)
	{
	  lowest = arr1[count];
	}
    }

  return lowest;
}

// Searchkey function
bool searchKey(double arr1[], double key)
{
  //Return true/false(use boolean)
  for(int count = 0; count < SIZE; count++)
    {  
      if(arr1[count] == key)
	{
	  return true;
	}     
    }

  return false;
}
