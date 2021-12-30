#include "solution.h"

void Board::Insert(int row, string values)
{
  string value;
  stringstream data(values);

  int column = 0;
  while (getline(data, value, ' '))
  {
    try { m_values[row][column++] = stoi(value); }
    catch (...) {}
  }
}

bool Board::Mark(int value)
{
  for (int i = 0; i < m_size; i++)
    for (int j = 0; j < m_size; j++)
      if (m_values[i][j] == value)
        m_marked[i][j] = 0;

  if (hasWon)
    return false;

  return hasWon = Test();
}

bool Board::Test()
{
  // for (int i = 0; i < m_size; i++)
  // {
  //   int row = 0;
  //   int column = 0;

  //   for (int j = 0; j < m_size; j++)
  //   {
  //     row += m_marked[i][j];
  //     column += m_marked[j][i];
  //   }

  //   if (row == 0 || column == 0)
  //     return true;
  // }

  // Rows
  if ((m_marked[0][0] + m_marked[0][1] + m_marked[0][2] + m_marked[0][3] + m_marked[0][4]) == 0)
    return true;

  if ((m_marked[1][0] + m_marked[1][1] + m_marked[1][2] + m_marked[1][3] + m_marked[1][4]) == 0)
    return true;

  if ((m_marked[2][0] + m_marked[2][1] + m_marked[2][2] + m_marked[2][3] + m_marked[2][4]) == 0)
    return true;

  if ((m_marked[3][0] + m_marked[3][1] + m_marked[3][2] + m_marked[3][3] + m_marked[3][4]) == 0)
    return true;

  if ((m_marked[4][0] + m_marked[4][1] + m_marked[4][2] + m_marked[4][3] + m_marked[4][4]) == 0)
    return true;


  // Columns
  if ((m_marked[0][0] + m_marked[1][0] + m_marked[2][0] + m_marked[3][0] + m_marked[4][0]) == 0)
    return true;

  if ((m_marked[0][1] + m_marked[1][1] + m_marked[2][1] + m_marked[3][1] + m_marked[4][1]) == 0)
    return true;

  if ((m_marked[0][2] + m_marked[1][2] + m_marked[2][2] + m_marked[3][2] + m_marked[4][2]) == 0)
    return true;

  if ((m_marked[0][3] + m_marked[1][3] + m_marked[2][3] + m_marked[3][3] + m_marked[4][3]) == 0)
    return true;

  if ((m_marked[0][4] + m_marked[1][4] + m_marked[2][4] + m_marked[3][4] + m_marked[4][4]) == 0)
    return true;


  // Diagonals
  if ((m_marked[0][0] + m_marked[1][1] + m_marked[2][2] + m_marked[3][3] + m_marked[4][4]) == 0)
    return true;

  if ((m_marked[4][0] + m_marked[3][1] + m_marked[2][2] + m_marked[1][3] + m_marked[0][4]) == 0)
    return true;

  return false;
}

int Board::Score()
{
  int score = 0;
  for (int i = 0; i < m_size; i++)
    for (int j = 0; j < m_size; j++)
      score += m_values[i][j] * m_marked[i][j];

  return score;
}


int PartA(fstream& b, fstream& n)
{
  string line;
  vector<Board*> boards;

  int row = 0;
  Board* board = new Board();

  b.clear();
  b.seekg(0);
  while (getline(b, line))
  {
    if (line == "")
      continue;

    board->Insert(row, line);

    if (++row == 5)
    {
      boards.push_back(board);
      board = new Board();
      row = 0;
    }
  }

  int score = -1;

  n.clear();
  n.seekg(0);
  while (getline(n, line, ','))
  {
    int number = stoi(line);
    for (int i = 0; i < boards.size(); i++)
    {
      if (boards[i]->Mark(number))
      {
        score = number * boards[i]->Score();
        break;
      }
    }

    if (score > -1)
      break;
  }

  for (int i = 0; i < boards.size(); i++)
    delete boards[i];

  return score;
}

int PartB(fstream& b, fstream& n)
{
  int row = 0;
  string line;
  vector<Board*> boards;

  Board* board = new Board();

  b.clear();
  b.seekg(0);
  while (getline(b, line))
  {
    if (line == "")
      continue;

    board->Insert(row, line);

    if (++row == 5)
    {
      boards.push_back(board);
      board = new Board();
      row = 0;
    }
  }

  int number = 0;
  int winners = 0;

  n.clear();
  n.seekg(0);
  while (getline(n, line, ','))
  {
    number = stoi(line);

    for (int i = 0; i < boards.size(); i++)
    {
      if (boards[i]->Mark(number))
      {
        if (++winners == boards.size())
        {
          board = boards[i];
          break;
        }
      }
    }

    if (winners == boards.size())
      break;
  }

  int score = number * board->Score();

  return score;
}

int main()
{
  fstream boards, numbers;
  boards.open("./boards.txt", ios::in);
  numbers.open("./numbers.txt", ios::in);

  if (boards.is_open() && numbers.is_open())
  {
    cout << PartA(boards, numbers) << "\n";
    cout << PartB(boards, numbers) << "\n";

    boards.close();
    numbers.close();
  }
}