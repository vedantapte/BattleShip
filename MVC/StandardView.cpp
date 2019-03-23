//
// Created by mfbut on 3/9/2019.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <istream>
#include <cctype>
#include "StandardView.h"
#include "PlayerConfiguration.h"
#include "Utility.h"
#include "Model.h"
#include "Board.h"
#include "HumanPlayer.h"

using namespace std;
BattleShip::StandardView::StandardView(std::istream& in, std::ostream& out): in(cin), out(cout){

}

BattleShip::PlayerConfiguration BattleShip::StandardView::getPlayerConfiguration()
{
    int numHumanPlayers = 0, numAiPlayers = 0, choice;
    cout << "What type of game do you want to play?" << endl
         << "1. Human vs Human" << endl
         << "2. Human vs AI " << endl
         << "3. AI vs AI " << endl
         << "Your choice: " << endl;
    cin >> choice;

    switch(choice)
    {
        case 1:
            numHumanPlayers = 2;
            numAiPlayers = 0;
            break;
        case 2:
            numHumanPlayers = 1;
            numAiPlayers = 1;
            break;
        case 3:
            numHumanPlayers = 0;
            numAiPlayers = 2;
            break;
        default:
            this->getPlayerConfiguration();
            break;  
                 
    }
    BattleShip::PlayerConfiguration config = PlayerConfiguration(numHumanPlayers, numAiPlayers);
    return config;
}

/*
std::string BattleShip::StandardView::getPlayerName(int i) {
   
}
*/
/*
ShipPlacement BattleShip::StandardView::getShipPlacement(const Player& player, char shipChar, int shipLen) {

}
*/

void BattleShip::StandardView::showPlacementBoard(const Player& player){
    player.getBoard().getVisibleVersion();
}

void BattleShip::StandardView::showPlayersBoard(const Player& player){
    player.getBoard().getVisibleVersion();
}

void BattleShip::StandardView::printBoard(const std::vector<std::string>& board)
{
    cout << "  ";
    for(int i = 0; i < board[i].size(); i++)
    {
      cout << i << " ";
     }
     cout << endl;
     for(int r = 0; r < board.size(); r++)
     {
      cout << r << " ";
      for(int c = 0; c < board[r].size(); c++)
      {
       cout <<  board[r][c] << " ";
      }
     cout << endl;
    }
}

void BattleShip::StandardView::printBoardAsVisible(const Board& board) {
    cout << "  ";
    for(int i = 0; i < board.getNumCols(); i++)
    {
      cout << i << " ";
     }
     cout << endl;
     for(int r = 0; r < board.getNumRows(); r++)
     {
      cout << r << " ";
      for(int c = 0; c < board.getNumCols(); c++)
      {
       cout <<  board.boardState[r][c].getContentsIfVisible() << " ";
      }
     cout << endl;
    }
}

void BattleShip::StandardView::printBoardAsObscured(const Board& board) {
     cout << "  ";
    for(int i = 0; i < board.getNumCols(); i++)
    {
      cout << i << " ";
     }
     cout << endl;
     for(int r = 0; r < board.getNumRows(); r++)
     {
      cout << r << " ";
      for(int c = 0; c < board.getNumCols(); c++)
      {
       cout <<  board.boardState[r][c].getContentsIfHidden() << " ";
      }
     cout << endl;
    }
}
