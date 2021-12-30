#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Board
{
  public:
    static const int m_size = 5;

    void Insert(int row, string values);
    bool Mark(int value);
    bool Test();
    int Score();

  private:
    bool hasWon = false;
    int m_values[m_size][m_size];
    int m_marked[m_size][m_size] = 
    { 
      { 1, 1, 1, 1, 1 }, 
      { 1, 1, 1, 1, 1 }, 
      { 1, 1, 1, 1, 1 }, 
      { 1, 1, 1, 1, 1 }, 
      { 1, 1, 1, 1, 1 }
    };
};

int PartA(fstream&, fstream&);
int PartB(fstream&, fstream&);
int main();