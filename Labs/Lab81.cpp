#include <iostream>
using namespace std;

// Function prototype
int gcd(int, int);

// Driver Program
int main()
{
  int a, b, result;

  // User input
  cout << "\nEnter in two numbers:\n";
  cin >> a >> b;
  
  // Call gcd function
  result = gcd(a, b);

  cout << "\nThe numbers " << a << " and " << b;
  cout << " greatest common divisor is: " << result;
  cout << endl << endl;

  return 0;
}

// Function gcd
int gcd(int x, int y)
{
  int result = 0;
  
  // Base
  if((x % y) == 0)
  {
    result = y;
  }

  // Recursive
  else
  {
    result = gcd(y, x % y);
  }

  return result;
}
