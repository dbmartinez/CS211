//********************************************************************************************
// CS 211 - Lab 12
// Complete the program Lab12(Program).cpp and implement the routines that are not implemented
//********************************************************************************************
/* Use the comments given in each routine to complete the following program */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

class Node;
typedef Node* NodePtr;

class DLL;
class Node 
{
  friend class DLL;
private:
  int stId;
  string stName;
  string stEmail;
  int stAge;
  NodePtr nextStudent;
  NodePtr prev;
};

class DLL
{
private:
  NodePtr top;
  void destroy (NodePtr&);

public:
  DLL();
  DLL(const DLL& source);
  ~DLL();
  void insertDataFromFile();
  void print ();
  bool search (int);
  void insertAfterFirst (int id, string name, string email, int age);
  void insertBeforeFirst (int id, string name, string email, int age);
  void insertAfterLast (int id, string name, string email, int age);
  void insertBeforeLast (int id, string name, string email, int age);
  void remove (int);
  void copy (NodePtr top1, NodePtr& top2);
};
//--------------------------------------------
//--------------------------------------------
// the default constructor
DLL::DLL()
{
  top = NULL;
}
//--------------------------------------------
//--------------------------------------------
// the copy constructor
DLL::DLL(const DLL& source)
{
  top = NULL;
  copy(source.top, top);
}

//--------------------------------------------
//--------------------------------------------
// the destructor
DLL::~DLL()
{
  destroy(top);
}

//--------------------------------------------
//--------------------------------------------
// Read a transaction file and insert the data into it
// after reading a set of data you can call any of the 
// insert functions to insert the node into the linked list 
/* use the following data to test your program
   76543Marymary@csusm.edu19
   98765Kathykathy@csusm.edu30
   16438Floraflora@csusm.edu25
   43260Peterpeter@csusm.edu29
   87590kimkim@csusm.edu31
*/
void DLL::insertDataFromFile()
{
  int id;
  string name;
  string email;
  int age;
  ifstream inputFile;
  inputFile.open("transaction5.txt");

  if(!inputFile)
    {
      cout << "\nThe input file doesn't exist\n";
      exit(0);
    }

  while(inputFile >> id >> name >> email >> age)
    {
      insertAfterLast(id, name, email, age);
    }
}
//--------------------------------------------
//--------------------------------------------
// print the linked list
void DLL::print()
{
  NodePtr curr = top;
  NodePtr curr2 = top->prev;

  cout << "ID\tName\tEmail\t\tAge\n";
  cout << "----------------------------";
  cout << "-------\n";

  while(curr == NULL)
    {
      cout << curr->stId << "\t";
      cout << curr->stName << "\t";
      cout << curr->stEmail << "\t";
      cout << curr->stAge << "\t" << endl;
      curr = curr->prev;
    }

    cout << endl;
}
//--------------------------------------------
//--------------------------------------------
// search for a particular student id in the list
bool DLL::search(int id)
{
  NodePtr p = top;

  while(p != NULL)
    {
      if(p->stId == id)
	{
	  return true;
	}

      p = p->nextStudent;
    }

    return false;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list but after the first node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 1 <--> 10 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)

void DLL::insertAfterFirst(int id, string name, string email, int age)
{
  NodePtr p = new Node;
  NodePtr curr = top->nextStudent;
  p->stId = id;
  p->stName = name;
  p->stEmail = email;
  p->stAge = age;
  p->nextStudent = curr;
  p->prev = top;
  top->nextStudent = p;
  curr->prev = p;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list before the first node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 10 <--> 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 10)
void DLL::insertBeforeFirst(int id, string name, string email, int age)
{
  NodePtr p = new Node;
  NodePtr curr = top->nextStudent;
  p->stId = id;
  p->stName = name;
  p->stEmail = email;
  p->stAge = age;
  p->nextStudent = top;
  p->prev = NULL;
  curr->prev = p;
  top = p;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list after the last node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> 10 <-->(links to the first node which is 1)

void DLL::insertAfterLast(int id, string name, string email, int age)
{
  NodePtr p = new Node;
  p->stId = id;
  p->stName = name;
  p->stEmail = email;
  p->stAge = age;
  p->nextStudent = NULL;
  
  if(top == NULL)
    {
      top = p;
      
      return;
    }
  
  NodePtr temp = top;

  while(temp->nextStudent != NULL)
    {
      temp = temp->nextStudent;
    }

  temp->nextStudent = p;
  p->prev = temp;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list before the last node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 10 <--> 6 <--> (links to the first node which is 1)

void DLL::insertBeforeLast(int id, string name, string email, int age)
{
  NodePtr p = new Node;
  NodePtr temp = top;
  p->stId = id;
  p->stName = name;
  p->stEmail = email;
  p->stAge = age;
  p->nextStudent = top->nextStudent;

  if(top == NULL)
    {
      top = p;

      return;
    }

  while(temp->nextStudent != NULL)
    {
      temp = temp->nextStudent;
    }

  temp->nextStudent = p;
  p->prev = temp;
}
//--------------------------------------------
//--------------------------------------------
// removes a node from the list based on the given student id 
void DLL::remove(int id)
{

}
//--------------------------------------------
//--------------------------------------------
// copies one list into another
void DLL::copy(NodePtr atop, NodePtr& btop)
{

}       
//--------------------------------------------
// deallocate the nodes in a linked list
void DLL::destroy(NodePtr& top) 
{

}

//--------------------------------------------

int main () 
{
  DLL list1;
  list1.insertDataFromFile();
  list1.print();
  list1.insertAfterFirst (54321, "Jim", "jim@csusm.edu", 25);
  list1.print();
  list1.insertBeforeFirst (54123, "Joe", "joe@csusm.edu", 35);
  list1.print();
  list1.insertAfterLast (63421, "Adam", "adam@csusm.edu", 20);
  list1.print();
  list1.insertBeforeLast (66641, "Nancy", "nancy@csusm.edu", 27);
  //list1.print();
  bool  found = list1.search (12321);
  if (found)
    cout << "the record was found" << endl;
  else
    cout << "the record was not found" << endl;
  list1.remove (54321);
  list1.print();
   
  DLL list2(list1);
  //list2.print();
  return 0;
}
//--------------------------------------------
