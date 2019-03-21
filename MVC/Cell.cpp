//
// Created by mfbut on 3/10/2019.
//

#include <stdexcept>
#include "Cell.h"

BattleShip::Cell::Cell(char contents, const char hiddenMarker, const char hitMarker, const char missMarker): contents(contents), hiddenMarker(hiddenMarker), hitMarker(hitMarker), missMarker(missMarker) {

}

BattleShip::Cell::Cell(char contents): contents(contents), hiddenMarker('*'), hitMarker('X'), missMarker('O'){
    
}


  char BattleShip::Cell::getContents() const {
    return contents;
  }

  void BattleShip::Cell::setContents(char contents) {
    this->contents = contents;
  }
  
  char BattleShip::Cell::getContentsIfHidden() const {
    if (HasBeenFiredAt()) {
      if (containsShip()) {
        return hitMarker;
      }

      else if (!containsShip()) {
        return missMarker;
      }
    }

    else {
      return hiddenMarker;
    }

    return '\0';

  }

  char BattleShip::Cell::getContentsIfVisible() const {
    if (HasBeenFiredAt()) {
      if (containsShip()) {
        return hitMarker;
      }

      else if (!containsShip()) {
        return missMarker;
      }
    }

    else {
      return contents;
    }

    return '\0';
  }

  bool BattleShip::Cell::HasBeenFiredAt() const {
    return firedAt;
  }

  void BattleShip::Cell::setHasBeenFiredAt(bool hasBeenFiredAt) {
    this->firedAt = hasBeenFiredAt;
  }

  bool BattleShip::Cell::containsShip() const {
    if (contents != hiddenMarker) {
      return true;
    }

    else {
      return false;
    }
  }
