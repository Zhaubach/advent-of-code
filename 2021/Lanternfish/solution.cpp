#include "solution.h"

int PartA(fstream& file)
{
  string line;
  vector<Fish*> fishes;

  file.clear();
  file.seekg(0);
  while (getline(file, line, ','))
  {
    fishes.push_back(new Fish(stoi(line)));
  }

  // cout << "Initial State: ";
  // for (int i = 0; i < fishes.size(); i++)
  //   cout << fishes[i]->GetRemaining() << ",";
  // cout << "\n";

  int days = 80;
  for (int i = 0; i < days; i++)
  {
    int added = 0;
    for (Fish* pFish : fishes)
      if (pFish->Decrement())
        added++;

    for (int f = 0; f < added; f++)
      fishes.push_back(new Fish());

    // cout << "After " << i + 1 << " Days : ";
    // for (int i = 0; i < fishes.size(); i++)
    //   cout << fishes[i]->GetRemaining() << ",";
    // cout << "\n";
  }

  int count = fishes.size();
  for (Fish* pFish : fishes)
    delete pFish;

  return count;
}

unsigned long long PartB(fstream& file)
{
  int max = 9;
  string line;

  unsigned long long * pFishes = new unsigned long long[max];
  for (int i = 0; i < max; i++)
    pFishes[i] = 0;

  file.clear();
  file.seekg(0);
  while (getline(file, line, ','))
    pFishes[stoi(line)]++;

  int days = 256;
  for (int i = 0; i < days; i++)
  {
    unsigned long long * pF = new unsigned long long[max];
    for (int i = 0; i < max; i++)
      pF[i] = 0;

    pF[6] += pFishes[0];
    pF[8] += pFishes[0];

    for (int j = max - 1; j > 0; j--)
      pF[j - 1] += pFishes[j];

    delete[] pFishes;
    pFishes = pF;
  }

  unsigned long long count = 0;
  for (int i = 0; i < max; i++)
    count += pFishes[i];

  return count;
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