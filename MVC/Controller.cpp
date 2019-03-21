//
// Created by mfbut on 3/9/2019.
//

#include <stdexcept>
#include <vector>
#include <sstream>
#include <fstream>
#include "PlayerConfiguration.h"
#include "Controller.h"
#include "HumanPlayer.h"
#include "AiPlayer.h"
#include "StandardView.h"
#include "CheatingAI.h"
#include "RandomAI.h"
#include "HuntDestroyAI.h"

BattleShip::Controller::Controller() {

}

void BattleShip::Controller::setupGame(const std::string& GameConfigurationFile, int seed) {
    std::ifstream file(GameConfigurationFile);
    setupGame();
}

void BattleShip::Controller::setupGame(const std::string& GameConfigurationFile) {
    
}