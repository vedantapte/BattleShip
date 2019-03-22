//
// Created by mfbut on 3/9/2019.
//

#include "Move.h"
#include "iostream"

using namespace std;
BattleShip::Move::Move(BattleShip::Player& moveMaker) : moveMaker(moveMaker) {

}

void BattleShip::Move::enact(Model& model, View& view) {
    int row, col;
    string name = moveMaker.getName();
    cout << name << ", where would you like to attack? " << endl;
    cin >> row >> col;

    moveMaker.fireAt(row, col);
}

/*
bool BattleShip::Move::isValid() const {

}
*/