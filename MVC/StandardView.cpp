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
using namespace std;
BattleShip::StandardView::StandardView(std::istream& in, std::ostream& out): in(cin), out(cout){}

BattleShip::PlayerConfiguration BattleShip::StandardView::getPlayerConfiguration()
{
    int numHumanPlayers, numAiPlayers, choice;
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
                 
    }
    BattleShip::PlayerConfiguration config = PlayerConfiguration(numHumanPlayers, numAiPlayers);
    return config;
}

void BattleShip::StandardView::showPlacementBoard(const Player& player){
    player.getBoard().getVisibleVersion();
}

void BattleShip::StandardView::showPlayersBoard(const Player& player){
    player.getBoard().getVisibleVersion();
}

void BattleShip::StandardView::printBoard(const std::vector<std::string>& board)
{
    cout << " ";
    for(int i = 0; i < board[i].size();i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for(int r = 0; r < board.size(); i++)
}
/*
std::string BattleShip::StandardView::getPlayerName(int i){
    return players[i].getName();
}*/