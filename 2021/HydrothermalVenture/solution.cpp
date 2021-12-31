#include "solution.h"

Point CreatePoint(string coords)
{
  try
  {
    size_t separator = coords.find(",");
    string x = coords.substr(0, separator);
    string y = coords.substr(separator + 1, coords.length());

    return Point(stoi(x), stoi(y));
  }
  catch(const std::exception& e)
  {
    return Point();
  }
}

int PartA(fstream& file)
{
  string line;

  file.clear();
  file.seekg(0);
  while (getline(file, line))
  {
    size_t separator = line.find("->");

    string sString = line.substr(0, separator - 1);
    string eString = line.substr(separator + 3, line.length());

    Point sPoint = CreatePoint(sString);
    Point ePoint = CreatePoint(eString);
    Line l(sPoint, ePoint);

    if (l.IsVertical())
    {
      for (int i = min(sPoint.m_y, ePoint.m_y); i <= max(sPoint.m_y, ePoint.m_y); i++)
        m_grid[i][sPoint.m_x]++;
    }
    else if (l.IsHorizontal())
    {
      for (int i = min(sPoint.m_x, ePoint.m_x); i <= max(sPoint.m_x, ePoint.m_x); i++)
        m_grid[sPoint.m_y][i]++;
    }
  }

  int overlaps = 0;
  for (int i = 0; i < m_size; i++)
    for (int j = 0; j < m_size; j++)
      if (m_grid[i][j] > 1)
        overlaps++;

  return overlaps;
}

int PartB(fstream& file)
{
  string line;

  file.clear();
  file.seekg(0);
  while (getline(file, line))
  {
    size_t separator = line.find("->");

    string sString = line.substr(0, separator - 1);
    string eString = line.substr(separator + 3, line.length());

    Point sPoint = CreatePoint(sString);
    Point ePoint = CreatePoint(eString);
    Line l(sPoint, ePoint);

    if (!(l.IsVertical() || l.IsHorizontal()))
    {
      int x = sPoint.m_x;
      int y = sPoint.m_y;

      while (x != ePoint.m_x && y != ePoint.m_y)
      {
        m_grid[y][x]++;
        x = sPoint.m_x < ePoint.m_x ? x + 1 : x - 1;
        y = sPoint.m_y < ePoint.m_y ? y + 1 : y - 1;
      }

      m_grid[y][x]++;
    }
  }

  int overlaps = 0;
  for (int i = 0; i < m_size; i++)
    for (int j = 0; j < m_size; j++)
      if (m_grid[i][j] > 1)
        overlaps++;

  return overlaps;
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