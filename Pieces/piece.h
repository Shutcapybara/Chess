#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <stdexcept>
#include "position.h"
#pragma once
class Piece
{
protected:
    // eg e4
    Position position;
    // eg K - King
    char key;
    std::vector<Position> possibleMoves;

    char colour;

public:
    bool isWhite;

    // Destructer
    virtual ~Piece() {}

    virtual void createPossibleMoves(const std::vector<std::vector<std::unique_ptr<Piece>>> &gameBoard) = 0;

    std::vector<Position> getPossibleMoves()
    {
        return possibleMoves;
    }

    Position getPosition()
    {
        return position;
    }

    bool canMoveTo(Position newPos)
    {
        auto it = std::find(possibleMoves.begin(), possibleMoves.end(), newPos);
        if (it != possibleMoves.end())
        {
            position = newPos;
            return true;
        }
        return false;
    }


    /*
    void move(Position newPosition) {
        if (std::find(possibleMoves.begin(), possibleMoves.end(), newPosition.toString()) != possibleMoves.end()) {
            position = newPosition;
        }
        else {
            throw std::invalid_argument("Invalid move" + std::string(1, key) + " from " + position.toString() + " to " + newPosition.toString());
        }
    }
        */

    std::string getNotation()
    {
        return std::string(1, key) + position.toString();
    }

    char getColour()
    {
        return colour;
    }
};