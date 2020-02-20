// Lab 8 program 2

#include <iostream>
using namespace std;

// Function prototype
int IsFib(int);
bool checkFib(int);

// Driver program
int main()
{
  int num, result;

  cout << "\nEnter a number(enter a negative number to quit): ";
  cin >> num;

  if(num == -1)
  {
    cout << "\n(*Thanks – Have a good Day*)\n";
  }
  
  while(num > 0)
  {
    // Call function checkFib
    result = checkFib(num);
  
    if(result == true)
    {
      cout << "\nYes, you got it, " << num;
      cout << " is a Fibonacci number.";
      cout << endl << endl;
    }

    else if(result == false)
    {
      cout << "\n!!!!!Sorry " << num;
      cout << " is not a Fibonacci number.";
      cout << endl << endl;
    }

    cout << "\nEnter a number(enter a negative number to quit): ";
    cin >> num;      

    if(num == -1)
    {
      cout << "\n(*Thanks – Have a good Day*)\n";
    }
  }

  return 0;
}

// Recursive IsFib function
int IsFib(int x)
{
  if(x <= 1)
  {
    return x;
  }

  else
  {
    return(IsFib(x - 1) + IsFib(x - 2));    
  }
}

// Function checkFib
bool checkFib(int y)
{
  for(int i = 0; true; i++)
  {
    if(IsFib(i) == y)
    {
      return true;
    }

    else if(IsFib(i) > y)
    {
      return false;
    }
  }
}
