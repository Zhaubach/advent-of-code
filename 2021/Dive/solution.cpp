#include "solution.h"

int PartA(fstream& file)
{
  string line;
  int depth = 0;
  int position = 0;

  file.clear();
  file.seekg(0);
  while (getline(file, line))
  {
    if (line.compare(0, 7, "forward") == 0)
    {
      position += stoi(line.substr(8,1));
    }
    else if (line.compare(0, 2, "up") == 0)
    {
      depth -= stoi(line.substr(3,1));
    }
    else if (line.compare(0, 4, "down") == 0)
    {
      depth += stoi(line.substr(5,1));
    }
  }

  return depth * position;
}

int PartB(fstream& file)
{
  string line;
  int aim = 0;
  int depth = 0;
  int position = 0;

  file.clear();
  file.seekg(0);
  while (getline(file, line))
  {
    if (line.compare(0, 7, "forward") == 0)
    {
      int value = stoi(line.substr(8,1));

      depth += aim * value;
      position += value;
    }
    else if (line.compare(0, 2, "up") == 0)
    {
      aim -= stoi(line.substr(3,1));
    }
    else if (line.compare(0, 4, "down") == 0)
    {
      aim += stoi(line.substr(5,1));
    }
  }

  return depth * position;
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