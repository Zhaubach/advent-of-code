#include "solution.h"

int PartA(fstream& file)
{
  int min = INT_MAX;
  int max = INT_MIN;
  vector<int> values;

  string line;
  file.clear();
  file.seekg(0);
  while (getline(file, line, ','))
  {
    int value = stoi(line);
    values.push_back(value);

    if (value < min)
      min = value;

    if (value > max)
      max = value;
  }

  int delta = max - min + 1;
  int* pValues = new int[delta]();
  for (int value : values)
    pValues[value - min]++;

  int distance = INT_MAX;
  for (int i = min; i < max; i++)
  {
    int d = 0;
    for (int p = 0; p < delta; p++)
      d += abs(p - i) * pValues[p];

    if (d < distance)
      distance = d;
  }

  delete[] pValues;
  return distance;
}

int PartB(fstream& file)
{
  int min = INT_MAX;
  int max = INT_MIN;
  vector<int> values;

  string line;
  file.clear();
  file.seekg(0);
  while (getline(file, line, ','))
  {
    int value = stoi(line);
    values.push_back(value);

    if (value < min)
      min = value;

    if (value > max)
      max = value;
  }

  int delta = max - min + 1;
  int* pValues = new int[delta]();
  for (int value : values)
    pValues[value - min]++;

  int distance = INT_MAX;
  for (int i = min; i < max; i++)
  {
    int d = 0;
    for (int p = 0; p < delta; p++)
    {
      int cost = 0;
      for (int f = 1; f <= abs(p - i); f++)
        cost += f;

      d += cost * pValues[p];
    }

    if (d < distance)
      distance = d;
  }

  delete[] pValues;
  return distance;
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