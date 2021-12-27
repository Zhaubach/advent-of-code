#include "solution.h"

int PartA(fstream& file)
{
  string line;
  int count = 0;
  int bits[12] = {0,0,0,0,0,0,0,0,0,0,0,0};

  file.clear();
  file.seekg(0);
  while (getline(file, line))
  {
    count++;

    for (int i = 0; i < 12; i++)
      bits[i] += stoi(line.substr(i, 1));
  }

  count = count / 2;
  for (int i = 0; i < 12; i++)
  {
    if (bits[i] > count)
      bits[i] = 1;
    else
      bits[i] = 0;
  }

  int gamma = 0;
  int epsilon = 0;
  for (int i = 0; i < 12; i++)
  {
    gamma += bits[i] * pow(2, 11 - i);
    epsilon -= (bits[i] - 1) * pow(2, 11 - i);
  }

  return gamma * epsilon;
}

int PartB(fstream& file)
{
  string line;
  Node top(-1, nullptr);

  file.clear();
  file.seekg(0);
  while (getline(file, line))
  {
    Node* node = &top;
    for (int i = 0; i < 12; i++)
    {
      node = node->Insert(stoi(line.substr(i, 1)));
    }
  }

  Node* oxygen = &top;
  while (oxygen)
  {
    Node* o;
    if (oxygen->GetCommon() >= 0)
    {
      if (!(o = oxygen->Get(1)))
        o = oxygen->Get(0);
    }
    else
    {
      if (!(o = oxygen->Get(0)))
        o = oxygen->Get(1);
    }

    if (!o)
      break;

    oxygen = o;
  }

  int oCount = 0;
  int oValue = 0;
  while (oxygen->pParent)
  {
    oValue += oxygen->value * pow(2, oCount);
    oxygen = oxygen->pParent;
    oCount++;
  }

  Node* carbondioxide = &top;
  while (carbondioxide)
  {
    Node* c;
    if (carbondioxide->GetCommon() >= 0)
    {
      if (!(c = carbondioxide->Get(0)))
        c = carbondioxide->Get(1);
    }
    else
    {
      if (!(c = carbondioxide->Get(1)))
        c = carbondioxide->Get(0);
    }

    if (!c)
      break;

    carbondioxide = c;
  }

  int cCount = 0;
  int cValue = 0;
  while (carbondioxide->pParent)
  {
    cValue += carbondioxide->value * pow(2, cCount);
    carbondioxide = carbondioxide->pParent;
    cCount++;
  }

  return oValue * cValue;
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