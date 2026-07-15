#include "piece.h"
#include <string>
#include <memory>
class Rook : public Piece {
private:

    void addMovesInDirection(
    const std::vector<std::vector<std::unique_ptr<Piece>>>& gameBoard,
    int file,
    int rank,
    int fileDirection,
    int rankDirection) 
    {
        int newFile = file + fileDirection;
        int newRank = rank + rankDirection;

        // while in bounds 
        while (newFile >= 0 && newFile < gameBoard.size() && newRank >= 0 && newRank < gameBoard[0].size()) 
        {
            // if there isn't a peice there 
            if (gameBoard[newFile][newRank] != nullptr) {
                // if its the other colours peice we can take it 
                if (gameBoard[newFile][newRank]->isWhite != isWhite) {
                    possibleMoves.push_back(
                        Position(
                            static_cast<char>('A' + newFile),
                            static_cast<char>('1' + newRank)
                        )
                    );
                }
                break;                        
            }

            possibleMoves.push_back(
                Position(
                    static_cast<char>('A' + newFile),
                    static_cast<char>('1' + newRank)
                )
            );

            newFile += fileDirection;
            newRank += rankDirection;
        }
    }

public:
    Rook(Position StartPos, bool _isWhite) {
        key = 'R';
        position = StartPos;
        isWhite = _isWhite;
    }

    void createPossibleMoves(const std::vector<std::vector<std::unique_ptr<Piece>>>& gameBoard) override 
    {
        possibleMoves.clear();
        int fileIndex = position.file - 'A';
        int rankIndex = position.rank - '1';

        addMovesInDirection(gameBoard, fileIndex, rankIndex, 1, 0);  // right
        addMovesInDirection(gameBoard, fileIndex, rankIndex, -1, 0); // left
        addMovesInDirection(gameBoard, fileIndex, rankIndex, 0, 1);  // up
        addMovesInDirection(gameBoard, fileIndex, rankIndex, 0, -1); // down
    }

};