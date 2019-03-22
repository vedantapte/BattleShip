//
// Created by mfbut on 3/9/2019.
//

#include "Player.h"
#include "Board.h"
#include "GameAttributes.h"
#include "Cell.h"

int BattleShip::Player::num_instances = 0;

BattleShip::Player::Player(const GameAttributes& gameAttributes, View& view): id(num_instances), view(view), board(Board(0,0)) {
    
}

const std::string& BattleShip::Player::getName() const {
    return name;
}

// void BattleShip::Player::setName(const std::string& name) {
//     this->name;
// }

const BattleShip::Board& BattleShip::Player::getBoard() const {
    return board;
}

BattleShip::Board& BattleShip::Player::getBoard() {
    return board;
}

const int BattleShip::Player::getId() const {
    return id;
}


BattleShip::AttackResult BattleShip::Player::fireAt(int row, int col) {

    if (not board.boardState[row][col].HasBeenFiredAt())
    {
        board.boardState[row][col].setHasBeenFiredAt(true);
        if(board.boardState[row][col].containsShip())
        {
            hit(board.boardState[row][col].contents);
            return AttackResult(true, false, board.boardState[row][col].contents); //add check for destroyed -- getshiphealth

        }
        else{
            return AttackResult(false, false, board.boardState[row][col].contents);
        }
    }
    return AttackResult(false, false, board.boardState[row][col].contents);
}


BattleShip::Player& BattleShip::Player::getOpponent() {
    return *opponent;
}

const BattleShip::Player& BattleShip::Player::getOpponent() const {
    return *opponent;
}

// void BattleShip::Player::setOpponent(Player& opponent) {
//     this->opponent;
// }


bool BattleShip::Player::hit(char shipChar) {
    for (int i = 0; i < board.getNumRows(); i++) {
        for (int j = 0; j < board.getNumCols(); j++) {
            if (board.at(i, j).contents == shipChar) {
                if (board.boardState[i][j].HasBeenFiredAt()) {
                    for(std::pair<char, int> ship: shipHealths)
                    {
                        if(ship.first == shipChar) {
                            ship.second--;
                        }
                    }
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }
    return false;
}

bool BattleShip::Player::allShipsSunk() const{
    int count = shipHealths.size();
    for(std::pair<char, int> ship: shipHealths)
    {
        if(ship.second == 0) {
            count--;
        }
        if(!(count > 0)) {
            return true;
        }
    }
    return false;
}
