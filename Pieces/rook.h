#include "piece.h"
#include <string>
class Rook : public Piece {
private:
    void pathBlocked()
    {
        
    }

public:
    Rook(char file, char rank) {
        key = 'R';
        position = Position(file, rank);
    }

    void createPossibleMoves(Piece* board[8][8]) override {
        possibleMoves.clear();
        // Above Horizontal moves
        for (char f = position.file; f <= 'H'; ++f) {
            if (f != position.file) {
                possibleMoves.push_back(std::string(1, f) + position.rank);
            }

        }

        // Vertical moves
        for (char r = '1'; r <= '8'; ++r) {
            if (r != position.rank) {
                possibleMoves.push_back(std::string(1, position.file) + r);
            }
        }
    }

};