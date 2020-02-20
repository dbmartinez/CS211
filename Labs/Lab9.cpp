//*******************************************************************************************
//CS 211 - Lab 9
//Complete the program Lab09(Program).cpp and implement the routines that are not implemented
//*******************************************************************************************
// Use the comments given in each routine to complete the following program
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Node;
typedef Node* NodePtr;

class LL;

class Node 
{
  friend class LL;

  private:
    int stId;
    string stName;
    string stEmail;
    int stAge;
    NodePtr nextStudent;
};

class LL
{
  private:
    NodePtr top;
    void destroy(NodePtr&);

  public:
    LL();
    LL(const LL& source);
    ~LL();
    void insertDataFromFile();
    void print();
    bool search(int);
    void insertAfterFirst(int id, string name, string email, int age);
    void insertBeforeFirst(int id, string name, string email, int age);
    void insertAfterLast(int id, string name, string email, int age);
    void insertBeforeLast(int id, string name, string email, int age);
    void remove(int);
    void copy(NodePtr top1, NodePtr& top2);
};

//--------------------------------------------
//--------------------------------------------
// the default constructor
LL::LL()
{
  top = NULL;
}

//--------------------------------------------
//--------------------------------------------
// the copy constructor
LL::LL(const LL& source)
{
  top = NULL;
  copy(source.top, top);
}

//--------------------------------------------
//--------------------------------------------
// the destructor
LL::~LL()
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
void LL::insertDataFromFile()
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
void LL::print()
{
  NodePtr curr = top;
  
  cout << "ID\tName\tEmail\t\tAge\n";
  cout << "----------------------------";
  cout << "-------\n";

  while(curr != NULL) 
  {
    cout << curr->stId << "\t";
    cout << curr->stName << "\t";
    cout << curr->stEmail << "\t";
    cout << curr->stAge << "\t" << endl;
    curr = curr->nextStudent;
  }

  cout << endl;
}
//--------------------------------------------
//--------------------------------------------
// search for a particular student id in the list
bool LL::search(int id)
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
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 10 --> 20 -->13 --> 4 --> 5 --> 6
void LL::insertAfterFirst(int id, string name, string email, int age)
{
  NodePtr p;
 
  //if(top != NULL)
    //{
    p = new Node;
    p->stId = id;
    p->stName = name;
    p->stEmail = email;
    p->stAge = age;
    p->nextStudent = top->nextStudent;
    top->nextStudent = p;
    // }

  //  else if(top == NULL)
  //{
  // insertAfterLast(id, name, email, age);
  //}
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list before the first node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 10 --> 1 --> 20 -->13 --> 4 --> 5 --> 6
void LL::insertBeforeFirst(int id, string name, string email, int age)
{
  NodePtr p = new Node;
  p->stId = id;
  p->stName = name;
  p->stEmail = email;
  p->stAge = age;
  p->nextStudent = top;
  top = p;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list after the last node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6 --> 10
void LL::insertAfterLast(int id, string name, string email, int age)
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
  }

  else
  {
    NodePtr temp;
    temp = top;

    while(temp->nextStudent != NULL)
    {
      temp = temp->nextStudent;
    }

    temp->nextStudent = p;
  }
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list before the last node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 10 --> 6
void LL::insertBeforeLast(int id, string name, string email, int age)
{
  NodePtr p = new Node;

  p->stId = id;
  p->stName = name;
  p->stEmail = email;
  p->stAge = age;

  if(top == NULL) 
  {
    top = p;
    top->nextStudent = NULL;
  }

  else 
  {
    NodePtr temp = top;
    //NodePtr prev = NULL;

    /*
    while(temp->nextStudent != NULL) 
    {      
      prev = temp;
      temp = temp->nextStudent;
    }

    prev->nextStudent = p;
    p->nextStudent = temp;
    }*/

    while(temp->nextStudent != NULL)
      {
	p = p->nextStudent;
      }
    
    
    p->nextStudent = temp->nextStudent;
    temp->nextStudent = p;
  }
}
//--------------------------------------------
//--------------------------------------------
// removes a node from the list based on the given student id 
void LL::remove(int id)
{
  NodePtr p;
  p = top;
  NodePtr q;

  if(search(id) == true)
  {
    if(top->stId == id)
    {
      q = top;
      top = top->nextStudent;
      delete q;
    }

    else
    {
      while(p->nextStudent->stId != id)
      {
        p = p->nextStudent;
      }

      q = p->nextStudent;
      p->nextStudent = q->nextStudent;
      delete q;
    }
  }

  else
  {
    cout << "\nThe id doesn't exist.\n";  
  }
}
//--------------------------------------------
//--------------------------------------------
// copies one list into another
void LL::copy(NodePtr atop, NodePtr& btop)
{
  NodePtr acurr, bcurr;
  
  destroy(btop);
  
  if(atop != NULL) 
  {
    btop = new Node;
    btop->stId = atop->stId;
    btop->stName = atop->stName;
    btop->stEmail = atop->stEmail;
    btop->stAge = atop->stAge;
    acurr = atop;
    bcurr = btop;

    while(acurr->nextStudent != NULL) 
    {
      bcurr->nextStudent = new Node;
      acurr = acurr->nextStudent;
      bcurr = bcurr->nextStudent;
      bcurr->stId = acurr->stId;
      bcurr->stName = acurr->stName;
      bcurr->stEmail = acurr->stEmail;
      bcurr->stAge = acurr->stAge;
    }

    bcurr->nextStudent = NULL;
  }
}       
//--------------------------------------------
// deallocate the nodes in a linked list
void LL::destroy(NodePtr& top) 
{
  NodePtr curr, temp;
  curr = top;
  
  while(curr != NULL)
  {
    temp = curr;
    curr = curr->nextStudent;
    delete temp;
  }

  top = NULL;
}

//--------------------------------------------
int main() 
{
  LL list1;
  list1.insertDataFromFile();
  list1.print();
  list1.insertAfterFirst(54321, "Jim", "jim@csusm.edu", 25);
  list1.print();
  list1.insertBeforeFirst(54123, "Joe", "joe@csusm.edu", 35);
  list1.print();
  list1.insertAfterLast(63421, "Adam", "adam@csusm.edu", 20);
  list1.print();
  list1.insertBeforeLast(66641, "Nancy", "nancy@csusm.edu", 27);
  list1.print();

  bool found = list1.search (12321);

  if(found)
  {
    cout << "\nThe record was found...\n" << endl;
  }

  else
  {
    cout << "\nThe record was not found...\n" << endl;
  }

  list1.remove(54321);
  list1.print();
   
  LL list2(list1);
  list2.print();
  
  return 0;
}

