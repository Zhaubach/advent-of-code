#include "solution.h"

int PartA(fstream& file)
{
  string line;
  int deeper = 0;
  int previous = -1;

  file.clear();
  file.seekg(0);
  while (getline(file, line))
  {
    int depth = stoi(line);

    if (previous > -1 && depth > previous)
      deeper++;

    previous = depth;
  }

  return deeper;
}

int PartB(fstream& file)
{
  string line;
  int deeper = 0;
  int previous = 0;
  deque<int> window;

  file.clear();
  file.seekg(0);
  while (getline(file, line))
  {
    window.push_back(stoi(line));
    if (window.size() > 3)
    {
      window.pop_front();

      int depth = window[0] + window[1] + window[2];
      if (depth > previous)
        deeper++;

      previous = depth;
    }
  }

  return deeper;
}

int main()
{
  fstream file;
  file.open("./input.txt", ios::in);

  if (file.is_open())
  {
    cout << PartA(file) << "\n";
    cout << PartB(file) << "\n";

    file.close();
  }
}