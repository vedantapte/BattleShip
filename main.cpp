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

  return 0;
}
