//******************************************************************************************
/*
  1)Tree::Tree( );
  2)int Tree::FindMinLen(TreeStructPtr Root);
  3)void Tree::PrintPreOrderTreeWithStack(TreeStructPtr Root);
  4) 
  5)You are required to implement the rest. 
  6) 
  7)Doing this lab and understanding the routines will certainly help you in the final exam.
*/
//******************************************************************************************
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class TreeStruct;
class Tree;
class Stack;
class Queue;

typedef TreeStruct* TreeStructPtr;
typedef Tree* TreePtr;

class Stack
{
private:
  vector<TreeStructPtr> s;

public:
  void push(TreeStructPtr ptr) 
  {
    s.insert(s.begin(), ptr);
  }

  TreeStructPtr pop()
  {
    TreeStructPtr ptr = s[0];
    s.erase(s.begin());
    return ptr;
  }

  bool empty()
  {
    return(s.size() == 0);
  }
};

class Queue
{
private:
  vector<TreeStructPtr> q;

public:
  void push(TreeStructPtr ptr)
  {
    q.push_back(ptr);
  }
  
  TreeStructPtr pop()
  {
    TreeStructPtr ptr = q[0];
    q.erase(q.begin());
    return ptr;
  }
  
  bool empty()
  {
    return(q.size() == 0);
  }
};

class TreeStruct
{
public:
  int Number;
  TreeStructPtr Left;
  TreeStructPtr Right;
};

class Tree
{
public:

  TreeStructPtr TreeRoot;

  Tree();
  // ~Tree();
  void InsertIntoTree(TreeStructPtr& Root, int num); 
  int  FindMaxLen(TreeStructPtr Root); 
  int  FindMinLen(TreeStructPtr Root); 
  int  CountNodes(TreeStructPtr Root);
  void Copy(TreeStructPtr Root1, TreeStructPtr& Root2); //copies one tree into another
  bool Search(TreeStructPtr Root, int n);
  void PrintInOrderTree(TreeStructPtr Root);
  void PrintPreOrderTree(TreeStructPtr Root);
  void PrintPostOrderTree(TreeStructPtr Root); 
  void PrintPreOrderTreeWithStack(TreeStructPtr Root);
  void PrintBreadthFirstWithQueue(TreeStructPtr Root);
  //  bool Destroy(TreeStructPtr& Root);
};

//----------------------------------------------------------------
// tree constructor
Tree::Tree()
{
  TreeRoot = NULL;
}

/*
Tree::~Tree()
{
  Destroy();
  }*/

/*---------------------------------------------------------------
bool Tree::Destroy(TreeStructPtr& Root)
{
  if(Root == NULL)
    return true;

  if((Root->Left == NULL) && (Root->Right == NULL))
  {
    delete Root;
    Root = NULL;
    return true;
  }

  Destroy(Root->Left);
  Destroy(Root->Right);

  delete Root;
  Root = NULL;
  return true;

}
*/
//----------------------------------------------------------------
void Copy(TreeStructPtr Root1, TreeStructPtr& Root2) //copies one tree into another
{ 
  if(Root1 == NULL)
  {
    Root2 = NULL;
    return;
  }

  Root2 = new TreeStruct;
  Root2->Number = Root1->Number;

  Copy(Root1->Left, Root2->Left); 
  Copy(Root1->Right, Root2->Right);
}

//----------------------------------------------------------------
// Inserting into the tree using recursion
void Tree::InsertIntoTree(TreeStructPtr& Root, int x)
{ 
  if(Root == NULL)
  {
    Root = new TreeStruct;
    Root->Number = x;
    Root->Left = Root->Right = NULL;
    return;
  }

  if(x < Root->Number)
    return(InsertIntoTree(Root->Left, x));

  else
    return(InsertIntoTree(Root->Right, x));
}

//----------------------------------------------------------------
int Tree::FindMaxLen(TreeStructPtr Root)
{
  if(Root == NULL)
    return 0;

  int A = FindMaxLen(Root->Left);
  int B = FindMaxLen(Root->Right);

  if(A > B)
    return(A + 1);

  else
    return(B + 1);
}
//----------------------------------------------------------------
int Tree::FindMinLen(TreeStructPtr Root)
{
  if(Root == NULL)
    return 0;

  else if(Root->Right == NULL)
    return(1 + FindMinLen(Root->Left));

  else if(Root->Left == NULL)
    return(1 + FindMinLen(Root->Right));

  else
  {
    int CountLeft =  1 + FindMinLen(Root->Left);
    int CountRight = 1 + FindMinLen(Root->Right);

    if(CountLeft < CountRight)
      return(CountLeft);

    else
      return(CountRight);
  }
}
//----------------------------------------------------------------

int Tree::CountNodes(TreeStructPtr Root)
{
  if(Root == NULL)
    return 0;

  int x = CountNodes(Root->Left);
  int y = CountNodes(Root->Right);

  return(1 + x + y);
}
//----------------------------------------------------------------
bool Tree::Search(TreeStructPtr Root, int n)
{
  if(Root == NULL)
    return false;

  if(Root->Number == n)
     return true;

  if(Root->Number > n)
    return(Search(Root->Left, n));
  
  else
    return(Search(Root->Right, n));
}

//----------------------------------------------------------------
void Tree::PrintInOrderTree(TreeStructPtr Root)
{
  if(Root == NULL)
    return;

  PrintInOrderTree(Root->Left);
  cout << Root->Number << "-->";
  PrintInOrderTree(Root->Right);
}

//----------------------------------------------------------------
void Tree::PrintPreOrderTree(TreeStructPtr Root)
{
  if(Root == NULL)
    return;

   cout << Root->Number << "-->";
   PrintPreOrderTree(Root->Left);
   PrintPreOrderTree(Root->Right);
}

//----------------------------------------------------------------
void Tree::PrintPostOrderTree(TreeStructPtr Root)
{
  if(Root == NULL)
    return;

  PrintPostOrderTree(Root->Left);
  PrintPostOrderTree(Root->Right);
  cout << Root->Number << "-->";
}

//----------------------------------------------------------------
void Tree::PrintPreOrderTreeWithStack(TreeStructPtr Root)
{
  Stack stk;
  TreeStructPtr p = Root;

  if(p != NULL)
  {
    stk.push(p);
     
    while(!stk.empty())
    {
      p = stk.pop();
      cout << p->Number << "-->";
	 
      if(p->Right != NULL)
	stk.push(p->Right);
	
      if(p->Left != NULL)
	stk.push(p->Left);
    }
  }
}
//----------------------------------------------------------------
void Tree::PrintBreadthFirstWithQueue(TreeStructPtr Root)
{
  Queue Q;
  TreeStructPtr p = Root;

  if(p != NULL)
  {
    Q.push(p);

    while(!Q.empty())
    {
      p = Q.pop();

      cout << p->Number << "-->";
      
      if(p->Left != NULL)
        Q.push(p->Left);

      if(p->Right != NULL)
	Q.push(p->Right);
    }
  }
}

int main()
{
  Tree t;
  t.InsertIntoTree(t.TreeRoot, 15);
  t.InsertIntoTree(t.TreeRoot, 20);
  t.InsertIntoTree(t.TreeRoot, 10);
  t.InsertIntoTree(t.TreeRoot, 8);
  t.InsertIntoTree(t.TreeRoot, 9);
  t.InsertIntoTree(t.TreeRoot, 17);
  t.InsertIntoTree(t.TreeRoot, 21);
  t.InsertIntoTree(t.TreeRoot, 22);
  t.InsertIntoTree(t.TreeRoot, 23);
  t.InsertIntoTree(t.TreeRoot, 24);
  t.InsertIntoTree(t.TreeRoot, 25);
  t.InsertIntoTree(t.TreeRoot, 26);
  t.InsertIntoTree(t.TreeRoot, 11);

  cout << "\nPrinting Pre Order " << endl;
  t.PrintPreOrderTree(t.TreeRoot);
  cout << "\n-----------------------------------------------" << endl;
  getchar();

  cout << "Printing Post Order " << endl;
  t.PrintPostOrderTree(t.TreeRoot);
  cout << "\n-----------------------------------------------" << endl;
  getchar();

  cout << "Printing In Order " << endl;
  t.PrintInOrderTree(t.TreeRoot);
  cout << "\n-----------------------------------------------" << endl;
  getchar();

  cout << boolalpha << endl << endl;
  cout << "\nSearching 30: " << t.Search(t.TreeRoot, 30) << endl;
  cout << "\nSearching 8: " << t.Search(t.TreeRoot, 8) << endl;
  cout << "\nSearching 10: " << t.Search(t.TreeRoot, 10) << endl;
  cout << "-------------------------------------------" << endl;
  getchar();

  cout << "Printing Pre Order with Stack " << endl;
  t.PrintPreOrderTreeWithStack(t.TreeRoot);
  cout << "\n-----------------------------------------------" << endl;
  getchar();

  cout << "Printing level by level BreathFirst Traversal " << endl;
  t.PrintBreadthFirstWithQueue(t.TreeRoot);
  cout << "\n-----------------------------------------------" << endl;
  getchar();

  cout << endl;

  int MaxLen = t.FindMaxLen(t.TreeRoot);
  int MinLen = t.FindMinLen(t.TreeRoot);
  int TotalNodes = t.CountNodes(t.TreeRoot);
  cout << "Max is " << MaxLen << endl;
  cout << "Min is " << MinLen << endl;
  cout << "Num of Nodes is " << TotalNodes << endl;
  cout << "-----------------------------------------------" << endl;
  getchar();

  Tree t2;
  Copy(t.TreeRoot, t2.TreeRoot);
  cout << "Printing In Order the copy of the tree" << endl;
  t2.PrintInOrderTree(t2.TreeRoot);
  cout << "\n-----------------------------------------------" << endl;
}
//----------------------------------------------------------------

/* Your output should look like the foolowing 

Printing Pre Order
15-->10-->8-->9-->11-->20-->17-->21-->22-->23-->24-->25-->26-->
-----------------------------------------------

Printing Post Order
9-->8-->11-->10-->17-->26-->25-->24-->23-->22-->21-->20-->15-->
-----------------------------------------------

Printing In Order
8-->9-->10-->11-->15-->17-->20-->21-->22-->23-->24-->25-->26-->
-----------------------------------------------




Searching 30: false

Searching 8: true

Searching 10: true
-------------------------------------------

Printing Pre Order with Stack
15-->10-->8-->9-->11-->20-->17-->21-->22-->23-->24-->25-->26-->
-----------------------------------------------

Printing level by level BreathFirst Traversal
15-->10-->20-->8-->11-->17-->21-->9-->22-->23-->24-->25-->26-->
-----------------------------------------------


Max is 8
Min is 3
Num of Nodes is 13
-----------------------------------------------

Printing In Order the copy of the tree
8-->9-->10-->11-->15-->17-->20-->21-->22-->23-->24-->25-->26-->
-----------------------------------------------
Press any key to continue
*/
