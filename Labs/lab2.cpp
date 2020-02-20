// Lab 2

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
  ifstream inputFile;
  inputFile.open("transaction.txt");

  if(inputFile.fail())
    {
      cout << "\nError opening file...\n";
    }

  else
    {
      vector<string> Vec;
      string command, temp;
      int num;
      
      while(inputFile >> command)
	{
	  if(command == "Add")
	    {
	      inputFile >> temp >> num;

	      if(num >= 0 && num <= Vec.size())
		{
		  Vec.insert(Vec.begin() + num, temp);
		}

	      else
		{
                  cout << "\nCannot add index " << num << ".\n\n";
		}
     	    }
	  
	  else if(command == "Remove")
	    {
	      inputFile >> num;
	      
	      if(num >= 0 && num < Vec.size())
		{
		  Vec.erase(Vec.begin() + num);
		}

	      else
		{
		  cout << "\nCannot remove index " << num << ".\n\n";
		}
	    }
	  
          else if(command == "Print")
	    {
	      for(int index = 0; index < Vec.size(); index++)
		{
		  cout << Vec[index] << " ";
		}
	      
	      cout << endl;
	    }
	}      
    }

  inputFile.close();

  return 0;
}
