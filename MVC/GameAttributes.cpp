//
// Created by mfbut on 3/9/2019.
//
#include <utility>
#include "Utility.h"
#include "GameAttributes.h"

BattleShip::GameAttributes::GameAttributes(): numRows(0), numCols(0) {

}

BattleShip::GameAttributes::GameAttributes(int numRows, int numCols): numRows(numRows), numCols(numCols) {

}

BattleShip::GameAttributes::GameAttributes(std::istream& in) {
    in >> numRows;
    in >> numCols;
    int ships;
    in >> ships;
    
    for (int i=0; i<ships; i++) {
        std::pair<char, int> ship;

        in >> ship.first;
        in >> ship.second;
        
        shipAttributes.insert(ship);
    }
}

int BattleShip::GameAttributes::getNumRows() const{
    return numRows;
}

void BattleShip::GameAttributes::setNumRows(int numRows) {
    this->numRows = numRows;
}

int BattleShip::GameAttributes::getNumCols() const {
    return numCols;
}

void BattleShip::GameAttributes::setNumCols(int numCols) {
    this->numCols = numCols;
}

int BattleShip::GameAttributes::getShipSize(const char ShipChar) const {
    return shipAttributes.at(ShipChar);
}

const std::map<char, int>& BattleShip::GameAttributes::getShipAttributes() const {
    return shipAttributes;
}