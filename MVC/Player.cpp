//
// Created by mfbut on 3/9/2019.
//

#include "Player.h"
#include "Board.h"

int BattleShip::Player::num_instances = 0;

BattleShip::Player::Player(const GameAttributes& gameAttributes, View& view): board(Board(0,0)), view(view), id(num_instances) {}

const std::string& BattleShip::Player::getName() const {
    return name;
}

void BattleShip::Player::setName(const std::string& name) {
    this->name;
}

const BattleShip::Board& BattleShip::Player::getBoard() const {
    return board;
}

BattleShip::Board& BattleShip::Player::getBoard() {
    return board;
}

const int BattleShip::Player::getId() const {
    return id;
}

/*
BattleShip::AttackResult BattleShip::Player::fireAt(int row, int col) {
    if ()
}
*/

BattleShip::Player& BattleShip::Player::getOpponent() {
    return *opponent;
}

const BattleShip::Player& BattleShip::Player::getOpponent() const {
    return *opponent;
}

void BattleShip::Player::setOpponent(Player& opponent) {
    this->opponent;
}

bool BattleShip::Player::hit(char shipChar) {
    for (ShipChar) {
        if 
    }
}