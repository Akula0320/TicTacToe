#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

// Printing the board
void printBoard(vector<vector<char>>& board)
{
  for(int i = 0; i < 3; ++i)
  {
    for(int j = 0; j < 3; ++j)
    {
      cout<<board[i][j];
      if(j < 2)
        cout<<"  |";
    }
    cout<<"\n";
    if(i < 2)
      cout<<"---|---|---\n";
  }
  cout<<endl;
}

// game over or not function
bool isGameOver(vector<vector<char>>& board, char player)
{
    // checking row col wtr player
  for(int i = 0; i < 3; ++i)
  {
    if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
      return true;
    if(board[0][i] == player && board[1][i] == player && board[2][i] == player)
      return true;
  }
  // checking diagnolly
  if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
    return true;
  if(board[0][2] == player && board[1][1] == player && board[2][0] == player)
    return true;
  return false;
}
// board full or not
bool isBoardFull(const vector<vector<char>>& board)
{
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      if(board[i][j] == ' ')
        return false;
    }
  }
  return true;
}
// for players 
struct Player{
  string name_;
  char coin_;

  bool operator==(const Player& other) const {
    return (name_ == other.name_) && (coin_ == other.coin_);
  }
};


// Driver code
int main()
{
  vector<vector<char>> board(3, vector<char>(3, ' '));
  Player player1, player2;
  cout<<"---------------------------Welome to Tic-Tac-Toe------------------------------------ \n";
  cout<<"Please enter Player 1 Details(Name CointType) : \n";
  cin>>player1.name_>>player1.coin_;
  cout<<"Please enter Player2 Details(Name CointType) : \n";
  cin>>player2.name_>>player2.coin_;
  Player current_player = player1;


  while(true)
  {
    printBoard(board);
    int row, col;
    cout<<"Player "<<current_player.name_<<" Please make your move(row , col): \n";
    cin >> row >> col;

    // Checking move is valid or not
    if(row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') 
    {
      cout<<"Invalid Move \n";
      continue;
    }

    // record move
    board[row][col] = current_player.coin_;

    // checking game is over 
    if(isGameOver(board, current_player.coin_))
    {
      printBoard(board);
      if(isGameOver(board, player1.coin_))
        cout<<player1.name_<<" win the game \n";
      else if(isGameOver(board, player2.coin_))
        cout<<player2.name_<<" win the game \n";
      else
        cout<<"Game Drawn \n";
      break;
    }
    if(isBoardFull(board)){
      printBoard(board);
      cout<<"Match Drawn \n";
      break;
    }
    // changeing the player turn  
    current_player = (current_player == player1) ? player2 : player1;
  }
  return 0;
}