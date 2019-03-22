#include "Controller.h"
#include "Board.h"
#include "GameAttributes.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "StandardView.h"
using namespace std;
int main(int argc, char** argv) {
  //bool playing = true;
  cout << "File: " << argv[1] << endl; //comment out
  ifstream in(argv[1]);
  BattleShip::GameAttributes attributes = BattleShip::GameAttributes(in);
  BattleShip::Board board = BattleShip::Board(attributes.getNumRows(), attributes.getNumCols());
  //BattleShip::StandardView view = BattleShip::StandardView();
  //view.getPlayerConfiguration();
  //just for testing if the baord can print;
  cout << "  ";
  for(int i = 0; i < board[i].size(); i++)
  {
    cout << i << " ";
  }
  cout << endl;
  for(int r = 0; r < board.size(); r++)
  {
    cout << r << " ";
    for(int c = 0; c < board[c].size(); c++)
    {
      cout <<  board[r][c] << " ";
    }
    cout << endl;
  }
  //------------------------------------


  return 0;
}
