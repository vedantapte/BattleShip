//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_STANDARDVIEW_H
#define BATTLESHIP_STANDARDVIEW_H
#include <iostream>
#include <utility>
#include "PlayerConfiguration.h"
#include "View.h"

namespace BattleShip  {
class StandardView : public View{
 public:
  StandardView();
  StandardView(std::istream& in, std::ostream& out); //done
  virtual PlayerConfiguration getPlayerConfiguration() override; //done
  //virtual std::string getPlayerName(int i) override;
  //virtual ShipPlacement getShipPlacement(const Player& player, char shipChar, int shipLen) override;
  //virtual void updateShipPlacementView(const Player& player) override;
  //virtual std::pair<int, int> getFiringCoordinate(const BattleShip::Player& attacker) override;
  //virtual void showWinner(const Player& winner) override;
  //virtual void showResultOfAttack(const BattleShip::Player& attacker,
    //                                const BattleShip::AttackResult& attackResult) override;

  virtual void showPlayersBoard(const Player& player) override; //done
  virtual void showPlacementBoard(const Player& player) override; //done
 protected:
  void printBoard(const std::vector<std::string>& board); //done
  void printBoardAsVisible(const Board& board); //done
  void printBoardAsObscured(const Board& board); //done
 public:
  //virtual int getAiChoice() override;
 protected:

  //void clearInput();

  std::istream& in;
  std::ostream& out;
};
}

#endif //BATTLESHIP_STANDARDVIEW_H
