#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

struct Node
{
  int value;
  int lCount;
  int rCount;
  Node* pLeft;
  Node* pRight;
  Node* pParent;

  Node(int val, Node* parent)
  {
    value = val;
    pParent = parent;

    lCount = 0;
    rCount = 0;
    pLeft = nullptr;
    pRight = nullptr;
  }

  ~Node()
  {
    if (pLeft)
      delete pLeft;

    if (pRight)
      delete pRight;
  }

  int GetCommon()
  {
    if (lCount > rCount)
      return -1;
    if (lCount < rCount)
      return 1;

    return 0;
  }

  Node* Get(int val)
  {
    if (val == 0 && pLeft)
      return pLeft;
    else if (val == 1 && pRight)
      return pRight;

    return nullptr;
  }

  Node* Insert(int val)
  {
    if (val == 0)
    {
      if (!pLeft)
        pLeft = new Node(val, this);

      lCount++;
      return pLeft;
    }
    else if (val == 1)
    {
      if (!pRight)
        pRight = new Node(val, this);

      rCount++;
      return pRight;
    }

    return nullptr;
  }
};

int PartA(fstream&);
int PartB(fstream&);
int main();