#include "piece.h"
#include <string>
#include <memory>
class Bishop : public Piece {
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
                            static_cast<char>('a' + newFile),
                            static_cast<char>('1' + newRank)
                        )
                    );
                }
                break;                        
            }

            possibleMoves.push_back(Position(static_cast<char>('a' + newFile), static_cast<char>('1' + newRank)));

            newFile += fileDirection;
            newRank += rankDirection;
        }
    }

public:
    Bishop(Position StartPos, bool _isWhite) {
        key = 'B';
        position = StartPos;
        isWhite = _isWhite;
    }

    void createPossibleMoves(const std::vector<std::vector<std::unique_ptr<Piece>>>& gameBoard) override 
    {
        possibleMoves.clear();
        int fileIndex = position.file - 'a';
        int rankIndex = position.rank - '1';

        addMovesInDirection(gameBoard, fileIndex, rankIndex, 1, 1); 
        addMovesInDirection(gameBoard, fileIndex, rankIndex, 1, -1);
        addMovesInDirection(gameBoard, fileIndex, rankIndex, -1, 1);  
        addMovesInDirection(gameBoard, fileIndex, rankIndex, -1, -1);
    
    }

};