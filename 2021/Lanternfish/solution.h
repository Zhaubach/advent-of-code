#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Fish
{
  public:
    Fish()
    {
      m_timer = 8;
    }

    Fish(int timer)
    {
      m_timer = timer;
    }

    bool Decrement()
    {
      if (m_timer > 0)
      {
        m_timer--;
        return false;
      }
      else
      {
        m_timer = 6;
        return true;
      }
    }

    int GetRemaining()
    {
      return m_timer;
    }

  private:
    int m_timer;
};


int PartA(fstream&);
unsigned long long PartB(fstream&);
int main();