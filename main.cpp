#include "Controller.h"
#include "Board.h"
#include "GameAttributes.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char** argv) {
  //bool playing = true;
  cout << "File: " << argv[1] << endl;
  ifstream in(argv[1]);
  BattleShip::GameAttributes attributes = BattleShip::GameAttributes(in);
  BattleShip::Board board = BattleShip::Board(attributes.getNumRows(), attributes.getNumCols());

  return 0;
}
