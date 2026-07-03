#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <stdexcept>
#include "position.h"
#pragma once
class Piece {
protected:
    // eg E4
    bool isWhite;
    Position position;
    // eg K - King
    char key;
    std::vector<std::string> possibleMoves;

    char colour;
public:
    
    // Destructer
    virtual ~Piece() {}
    
    virtual void createPossibleMoves(Piece* board[8][8]) = 0; 

    std::vector<std::string> getPossibleMoves() {
        return possibleMoves;
    }

    std::string getLocation() {
        return position.toString();
    }

    void move(Position newPosition) {
        if (std::find(possibleMoves.begin(), possibleMoves.end(), newPosition.toString()) != possibleMoves.end()) {
            position = newPosition;
        }
        else {
            throw std::invalid_argument("Invalid move" + std::string(1, key) + " from " + position.toString() + " to " + newPosition.toString());
        }
    }

    std::string getNotation() {
        return std::string(1, key) + position.toString();
    }

    char getColour() {
        return colour;
    }




};