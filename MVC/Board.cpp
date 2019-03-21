//
// Created by mfbut on 3/10/2019.
//

#include "Board.h"                                                                                                                                      

BattleShip::Board::Board(int numRows, int numCols, char blankChar): numRows(numRows), numCols(numCols), blankChar(blankChar) {

}

BattleShip::Board::Board(int numRows, int numCols): numRows(numRows), numCols(numCols), blankChar('*') {

}

bool BattleShip::Board::canPlaceShipAt(const ShipPlacement& shipPlacement) const {
    if (inBounds(shipPlacement) && spacesAreEmpty(shipPlacement)) {
        return true;
    } 

    else {
        return false;
    }

}

int BattleShip::Board::getNumRows() const {
    return numRows;
}

int BattleShip::Board::getNumCols() const {
    return numCols;
}


std::vector<std::string> BattleShip::Board::getHiddenVersion() const {
    std::vector<std::string> str;
    std::string mystr;
    for (int i=0; i < getNumRows()-1; i++) {
        for (int j=0; j < getNumCols()-1; j++) {
            mystr += boardState[i][j].getContentsIfHidden();
        }
        str[i] = mystr;
    }
    return str;
}

std::vector<std::string> BattleShip::Board::getVisibleVersion() const {
    std::vector<std::string> str;
    std::string mystr;
    for (int i=0; i < getNumRows()-1; i++) {
        for (int j=0; j < getNumCols()-1; j++) {
            mystr += boardState[i][j].getContentsIfVisible();
        }
        str[i] = mystr;
    }
    return str;
}


void BattleShip::Board::AddShip(char shipChar, const ShipPlacement& shipPlacement) {
    if (canPlaceShipAt(shipPlacement)) {
        for (int i=shipPlacement.rowStart; i<=shipPlacement.rowEnd; i++) {
            for (int j=shipPlacement.colStart; j<=shipPlacement.colEnd; j++) {
                at(i,j).contents = ShipChar;
            }
        }
    }

    else if (!canPlaceShipAt(shipPlacement)) {
        throw std::out_of_range("Cannot place ship!");
    }
}

bool BattleShip::Board::inBounds(int row, int col) const {
    int maxrow = getNumRows();
    int maxcol = getNumCols();
    if (between(row, 0, maxrow-1) && between(col, 0, maxcol-1)) {
        return true;
    }

    else {
        return false;
    }
}


BattleShip::Cell& BattleShip::Board::at(int i, int j) {
    return boardState[i][j];
}
const BattleShip::Cell& BattleShip::Board::at(int i, int j) const {
    return boardState[i][j];
}


bool BattleShip::Board::inBounds(const ShipPlacement& shipPlacement) const {
    if (shipPlacement.rowStart >= 0 && shipPlacement.rowEnd <= numRows && shipPlacement.colStart >= 0 && shipPlacement.colEnd <= numCols) {
        return true;
    }

    else {
        return false;
    }
}

bool BattleShip::Board::between(int value, int low, int high) const {
    if (value >= low && value <= high) {
        return true;
    }

    else {
        return false;
    }
}

bool BattleShip::Board::spacesAreEmpty(const ShipPlacement& shipPlacement) const {
    for (int i=0; i < numRows; i++){
        for (int j=0; j < numCols; j++) {
            if (at(i,j).contents != at(i,j).hiddenMarker) {
                return false;
            }

            else {
                return true;
            }
        }
    }

    return true;
}


