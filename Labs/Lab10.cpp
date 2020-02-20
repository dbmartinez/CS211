//******************************************************************************************** 
// CS 211 - Lab 10        
// Complete the program Lab10(Program).cpp and implement the routines that are not implemented
//******************************************************************************************** 
// Use the comments given in each routine to complete the following program
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Node;
typedef Node* NodePtr;

class CircularDLL;
class Node
{
  friend class CircularDLL;

  protected:
    int stId, stAge;
    string stName, stEmail;
    NodePtr nextStudent;
    NodePtr prevStudent;
};

class CircularDLL
{
  protected:
    NodePtr top;
    void destroy(NodePtr&);

  public:
    CircularDLL();
    CircularDLL(const CircularDLL& source);
    ~CircularDLL();
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
CircularDLL::CircularDLL()
{
  top = NULL;
}

//--------------------------------------------
//--------------------------------------------
// the copy constructor
CircularDLL::CircularDLL(const CircularDLL& source)
{
  top = NULL;
  copy(source.top, top);
}

//--------------------------------------------
//--------------------------------------------
// the destructor
CircularDLL::~CircularDLL()
{
  destroy(top);
}

//--------------------------------------------
//--------------------------------------------
// Read a transaction file and insert the data into it
// after reading a set of data you can call any of the
// insert functions to insert the node into the linked list
/* use the following data to test your program
   76543 Mary  mary@csusm.edu  19
   98765 Kathy kathy@csusm.edu 30
   16438 Flora flora@csusm.edu 25
   43260 Peter peter@csusm.edu 29
   87590 kim   kim@csusm.edu   31*/
void CircularDLL::insertDataFromFile()
{
  ifstream inputFile;
  string name;
  string email;
  int id;
  int age;

  inputFile.open("transaction5.txt");

  if(!inputFile)
  {
    cout << "\nError opening file...\n";
  }

  else
  {
    while(inputFile >> id >> name >> email >> age)
    {
      insertAfterLast(id, name, email, age);
    }
  }
}

//--------------------------------------------        
//--------------------------------------------
// print the linked list
void CircularDLL::print()
{
  NodePtr p = top;

  if(top == NULL)
    {
      cout << "\nNothing to print\n";
    }

  else
    {
      cout << "\nID\tName\tEmail\tAge\n"; 
      cout << "------------------------------\n";
  
      do
	{
	  cout << p->stId;
	  cout << "\t" << p->stName;
	  cout << "\t" << p->stEmail;
	  cout << "\t" << p->stAge << endl;
	  p = p->nextStudent;

	}while(p != top);
    }

  cout << endl;
}

//--------------------------------------------         
//--------------------------------------------
// search for a particular student id in the list
bool CircularDLL::search(int id)
{
  NodePtr p = top;

  if(top == NULL)
  {
    return false;
  }

  while(p != top)
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
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is1)
// after inserting 10, we should get: 
// list constains 1 <--> 10 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)         
void CircularDLL::insertAfterFirst(int id, string name, string email, int age)
{
  if(top == NULL)
  {
    insertBeforeFirst(id, name, email, age);
    return;
  }

  if(top->nextStudent == top)
  {
    insertAfterLast(id, name, email, age);
    return;
  }

  NodePtr p = new Node;
  p->stId = id;
  p->stName = name;
  p->stEmail = email;
  p->stAge = age;

  p->nextStudent = top->nextStudent;
  top->nextStudent = p;
  p->prevStudent = top;
  NodePtr k;
  k = p->nextStudent;
  k->prevStudent = p;
}

//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list before the first node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get       
// list constains 10 <--> 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 10)
void CircularDLL::insertBeforeFirst(int id, string name, string email, int age)
{
  if(search(id))
  {
    cout << "The id: " << id << " already exists" << endl;
    return;
  }

  NodePtr p = new Node;
  p->stId = id;
  p->stName = name;
  p->stEmail = email;
  p->stAge = age;

  if(top == NULL)
  {
    top = p;
    top->prevStudent = top;
    top->nextStudent = top;
    return;
  }

  p->nextStudent = top;
  top->prevStudent = p;

  NodePtr q = top;
  while(q->nextStudent != top)
  {
    q = q->nextStudent;
  }

  q->nextStudent = p;
  p->prevStudent = q;
  top = p;
}

//--------------------------------------------
//--------------------------------------------                                    
// creates a node and insert the node on the bottom of the
// linked list after the last node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:       
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> 10 <-->(links to the first node which is 1)
void CircularDLL::insertAfterLast(int id, string name, string email, int age)
{
  if(search(id))
  {
    cout << "The id: " << id << " already exists" << endl;
    return;
  }

  NodePtr p = new Node;
  p->stId = id;
  p->stName = name;
  p->stEmail = email;
  p->stAge = age;

  if(top == NULL)
  {
    top = p;
    top->prevStudent = top;
    top->nextStudent = top;
    return;
  }

  NodePtr q = top;

  while(q->nextStudent != top)
  {
    q = q->nextStudent;
  }

  q->nextStudent = p;
  p->prevStudent = q;
  p->nextStudent = top;
  top->prevStudent = p;
}

//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list before the last node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:       
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 10 <--> 6 <--> (links to the first node which is 1)
void CircularDLL::insertBeforeLast(int id, string name, string email, int age)
{
  if(search(id) == true)
  {
    return;
  }

  if(top == NULL)
  {
    insertBeforeFirst(id, name, email, age);
    return;
  }

  if(top->nextStudent == top)
  {
    insertBeforeFirst(id, name, email, age);
    return;
  }

  NodePtr p = new Node;
  p->stId = id;
  p->stName = name;
  p->stEmail = email;
  p->stAge = age;

  NodePtr q = top;

  while(q->nextStudent->nextStudent != top)
  {
    q = q->nextStudent;
  }

  NodePtr k = q->nextStudent;
  q->nextStudent = p;
  p->nextStudent = k;
  k->prevStudent = p;
  p->prevStudent = q;

  return;
}

//--------------------------------------------
//--------------------------------------------         
// removes a node from the list based on the given student id 
void CircularDLL::remove(int id)
{
  NodePtr p;
  NodePtr q;
  q = top;
  p = top;

  if(top == NULL)
    {
      cout << "\nNothing to print\n";
    }

  while(q->nextStudent != top)
    {
      if(q->stId == id)
	{
	  p->nextStudent = q->nextStudent;
	  p->prevStudent = q->prevStudent;
	  delete q;
	}

      p = q;
      q = q->nextStudent;
    }
}

//--------------------------------------------
//--------------------------------------------
// copies one list into another
void CircularDLL::copy(NodePtr atop, NodePtr& btop)
{
  NodePtr acurr, bcurr, ccurr;

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
    ccurr = btop;

    while(acurr->nextStudent != atop)
    {
      bcurr->nextStudent = new Node;
      acurr = acurr->nextStudent;
      bcurr = bcurr->nextStudent;

      bcurr->stId = acurr->stId;
      bcurr->stName = acurr->stName;
      bcurr->stEmail = acurr->stEmail;
      bcurr->stAge = acurr->stAge;
      bcurr->prevStudent = ccurr;
      ccurr = bcurr;
    }  

    bcurr->nextStudent = top;
  }
}

//----------------------------------------
// deallocate the nodes in a linked list
void CircularDLL::destroy(NodePtr& top)
{
  NodePtr p = top;
  NodePtr q = top;

  while(p != top)
  {
    p = p->nextStudent;
    delete q;
    q = p;
  }

  top = NULL;
}

//-----------------------------------------
int main()
{
  CircularDLL list1;
  list1.insertDataFromFile();

  list1.print();
  list1.insertAfterFirst(54321, "Jim", "jim@csusm.edu", 25);
  list1.insertBeforeFirst(54123, "Joe", "joe@csusm.edu", 35);
  list1.insertAfterLast(63421, "Adam", "adam@csusm.edu", 20);
  list1.insertBeforeLast(66641, "Nancy", "nancy@csusm.edu", 27);
  list1.print();
  bool found = list1.search(12321);

  if(found)
  {
    cout << "\nThe record was found...\n";
  }

  else
  {
    cout << "\nThe record was not found...\n\n";
  }

  list1.remove(54321);
  list1.print();

  CircularDLL list2(list1);
  list2.print();

  return 0;
}
