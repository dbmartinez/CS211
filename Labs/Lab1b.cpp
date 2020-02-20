// Lab2 

#include <iostream>
#include <fstream>
using namespace std;

int CalculateMax(int, int, int, int, int);
int CalculateMin(int, int, int, int, int);
int CalculateAvg(int, int, int, int, int);

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
      max = CalculateMax(a1, a2, a3, a4, max);
      min = CalculateMin(a1, a2, a3, a4, min);
      average = CalculateAvg(a1, a2, a3, a4, average);
	  
      cout << stdId <<"\t"<< a1 <<"\t"<< a2 <<"\t"<< a3 <<"\t"<< a4;
      cout << "\t" << min << "\t" << max << "\t" << average << endl;
    }
      
    inputFile.close();
  }
  
  return 0;
}

int CalculateMax(int b1, int b2, int b3, int b4, int max)
{
  // max
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
  }
  
  return max;
}

int CalculateMin(int b1, int b2, int b3, int b4, int min)
{
  // min
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
  }

  return min;
}

int CalculateAvg(int b1, int b2, int b3, int b4, int avg)
{
  avg = (b1 + b2 + b3 + b4) / 4;
  return avg;
}
