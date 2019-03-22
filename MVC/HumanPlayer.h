//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_HUMANPLAYER_H
#define BATTLESHIP_HUMANPLAYER_H
#include "Player.h"
#include "View.h"
#include "GameAttributes.h"
using namespace std;
namespace BattleShip {
class Move;

class HumanPlayer : public Player {
 public:
  HumanPlayer(const GameAttributes& gameAttributes, View& view); //done
  virtual std::unique_ptr<BattleShip::Move> getMove() override; 
  virtual void placeShips() override; //done
  virtual void initializeName() override; //done
 protected:
    string name;
};
}

#endif //BATTLESHIP_HUMANPLAYER_H
