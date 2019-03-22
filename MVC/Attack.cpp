//
// Created by mfbut on 3/10/2019.
//

#include "Attack.h"

BattleShip::Attack::Attack(BattleShip::Player& attacker, int row, int col): Move(attacker), row(row), col(col) {

}

const int BattleShip::Attack::getRow() const {
    return col;
}

const int BattleShip::Attack::getCol() const {
    return row;
}
