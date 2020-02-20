// Lab 1

#include <iostream>
#include <fstream>
using namespace std;

int ProcessRow(int, int, int, int, int&, int&, int&);

int main()
{
  ifstream inputFile;
  int stdId, a1, a2, a3, a4;
  int min, max, average;
  
  inputFile.open("data.txt");
  
  if(inputFile.fail())
    {
      cout << "\nError opening file...";
    }
  
  else
    {
      cout << "Std-Id\tA1\tA2\tA3\tA4\tMin\tMax\tAverage\n";
      cout << "---------------------------------------------";
      cout << "------------------\n";
      
      for(int count = 1; count <= 3; count++)
	{
	  inputFile >> stdId >> a1 >> a2 >> a3 >> a4;
	  ProcessRow(a1, a2, a3, a4, min, max, average);
	  
	  cout << stdId <<"\t"<< a1 <<"\t"<< a2 <<"\t"<< a3 <<"\t"<< a4;
	  cout << "\t" << min << "\t" << max << "\t" << average << endl;
	}
      
      inputFile.close();
    }
  
  return 0;
}

int ProcessRow(int b1, int b2, int b3, int b4, int &min, int &max, int &average)
{
  /* min
  if(b1 <= b2 && b1 <= b3 && b1 <= b4) 
    {
      min = b1;
    }
  
  else if(b2 <= b1 && b2 <= b3 && b2 <= b4)
    {
      min = b2;
    }
  
  else if(b3 <= b1 && b3 <= b2 && b3 <= b4)
    {
      min = b3;
    }
  
  else
    {
      min = b4;
      }*/

  /* max
  if(b1 >= b2 && b1 >= b3 && b1 >= b4) 
    {
      max = b1;
    }
  
  else if(b2 >= b1 && b2 >= b3 && b2 >= b4)
    {
      max = b2;
    }
  
  else if(b3 >= b1 && b3 >= b2 && b3 >= b4)
    {
      max = b3;
    }
  
  else 
    {
      max = b4;
    }*/

  min = max = b1;
  //min = max = b2;
  //min = max = b3;
  //min = max = b4;

  if(b1 < min)
    {
      min = b1;
    }

  if(b2 < min)
    {
      min = b2;
    }
  
  if(b3 < min)
    {
      min = b3;
    }

  if(b4 < min)
    {
      min = b4;
    }

  if(b1 > max)
    {
      max = b1;
    }

  if(b1 > max)
    {
      max = b1;
    }

  if(b2 > max)
    {
      max = b2;
    }

  if(b3 > max)
    {
      max = b3;
    }

  if(b4 > max)
    {
      max = b4;
    }
  
  average = (b1 + b2 + b3 + b4) / 4;
}
