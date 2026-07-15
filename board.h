#include <vector>
#include <memory>
#include "Pieces/piece.h"

class Board
{
private:
    std::vector<std::vector<std::unique_ptr<Piece>>> gameBoard;

public:
    // Constructs an emplty pointer array of board stat
    Board(int boardHeight = 8, int boardWidth = 8)
        : gameBoard(boardHeight, std::vector<std::unique_ptr<Piece>>(boardWidth))
    {
    }

    
};