#include "piece.h"
#include <string>
#include <memory>
class Rook : public Piece {
private:
    void pathBlocked()
    {
        
    }

public:
    Rook(Position StartPos) {
        key = 'R';
        position = StartPos;
    }

    void createPossibleMoves(const std::vector<std::vector<std::unique_ptr<Piece>>>& gameBoard) override {
        possibleMoves.clear();
        int fileIndex = static_cast<int>(position.file) - 'A';
        int rankIndex = position.rank - '1';
        
        // adds all valid moves to the left of current piece
        for (int f = fileIndex-1; f >= 0; --f) {
            possibleMoves.push_back(Position(static_cast<char>(f + 'A'), position.rank));
            if (gameBoard[f][rankIndex] != nullptr) {
                break;
            }
        }

        // adds all valid moves to the right of current piece
        for (int f = fileIndex+1; f < gameBoard[0].size(); ++f) {
            possibleMoves.push_back(Position(static_cast<char>(f + 'A'), position.rank));
            if (gameBoard[f][rankIndex] != nullptr) {
                break;
            }
        }
        
        for (int r = rankIndex-1; r >= 0; --r) {
            possibleMoves.push_back(Position(position.file, static_cast<char>('1' + r)));
            if (gameBoard[fileIndex][r] != nullptr) {
                break;
            }
        }

        // Vertical moves
        for (int r = rankIndex+1; r < gameBoard.size(); ++r) {
            possibleMoves.push_back(Position(position.file, static_cast<char>('1' + r)));
            if (gameBoard[fileIndex][r] != nullptr) {
                break;
            }
        }



    }

};