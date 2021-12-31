#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Point
{
  int m_x;
  int m_y;

  Point(int x = -1, int y = -1)
  {
    m_x = x;
    m_y = y;
  }
};

struct Line
{
  Point m_start;
  Point m_end;

  Line(Point start, Point end)
  {
    m_start = start;
    m_end = end;
  }

  bool IsVertical()
  {
    return m_start.m_x == m_end.m_x;
  }

  bool IsHorizontal()
  {
    return m_start.m_y == m_end.m_y;
  }
};

static const int m_size = 1000;
static int m_grid[m_size][m_size] = {0};

Point CreatePoint(string coords);

int PartA(fstream&);
int PartB(fstream&);
int main();