//
// Created by mfbut on 3/9/2019.
//

#include <utility>
#include <iostream>
#include "HumanPlayer.h"
#include "ShipPlacement.h"
#include "Attack.h"
#include "board.h"
using namespace std;
BattleShip::HumanPlayer::HumanPlayer(const GameAttributes& gameAttributes, View& view): Player(gameAttributes, view)  {

}

void BattleShip::HumanPlayer::initializeName()
{
    cout << "Player /1/ please enter your name:" << endl;
    cin >> name;
}

void BattleShip::HumanPlayer::placeShips(){
    //int numShips = shipHealths.size();
    char orientation;
    int colStart, rowStart;
    for(pair<char, int> ship: shipHealths)
    {
        board.getVisibleVersion();
        cout <<  getName() <<  ", do you want to place "<< ship.first << " horizontally or vertically?" << endl
                                    << "Enter h for horizontal or v for vertical" << endl
                                    << "Your choice: " << endl;
        cin >> orientation;
        if(orientation == 'h' || orientation == 'H') //horiz
        {
            cout << getName() << ", enter the row and column you want to place " 
                              << ship.first << ", which is " 
                              << ship.second << " long, at with a space in between row and col: " 
                              << endl;
            cin >> rowStart >> colStart;
            int size = ship.second;
            ShipPlacement* place = new ShipPlacement(rowStart, colStart, rowStart, colStart+size);
            board.AddShip(ship.first, *place);            

        }
        else if(orientation == 'v' || orientation == 'V') //Vert
        {
            cout << getName() << ", enter the row and column you want to place " 
                              << ship.first << ", which is " 
                              << ship.second << " long, at with a space in between row and col: " 
                              << endl;
            cin >> rowStart >> colStart;
            int size = ship.second;
            ShipPlacement* place = new ShipPlacement(rowStart, colStart, rowStart+size, colStart);
            board.AddShip(ship.first, *place);   
        }
        else{
            continue;
        }
    }

}
