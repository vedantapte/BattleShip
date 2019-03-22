//
// Created by mfbut on 3/10/2019.
//

#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H
#include <string>
#include <vector>
#include "ShipPlacement.h"
#include "Cell.h"

namespace BattleShip {
class Board {
 public:
  Board(int numRows, int numCols, char blankChar); //done
  Board(int numRows, int numCols); //done
  bool canPlaceShipAt(const ShipPlacement& shipPlacement) const; //done

  int getNumRows() const; //done
  int getNumCols() const; //done

  std::vector<std::string> getHiddenVersion() const; //done
  std::vector<std::string> getVisibleVersion() const; //done

  void AddShip(char shipChar, const ShipPlacement& shipPlacement); //done
  bool inBounds(int row, int col) const; //done

  Cell& at(int i, int j); //done
  const Cell& at(int i, int j) const; //done

  std::vector<std::vector<Cell>> boardState;

 protected:
  bool inBounds(const ShipPlacement& shipPlacement) const; //done

  bool between(int value, int low, int high) const; //done
  bool spacesAreEmpty(const ShipPlacement& shipPlacement) const; //done


  //members

  int numRows;
  int numCols;
  const char blankChar;
  char ShipChar;
};
}

#endif //BATTLESHIP_BOARD_H
