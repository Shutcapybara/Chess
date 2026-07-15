#include <iostream>
#include <vector>
#include <memory>
#include "Pieces/rook.h"
#include "Pieces/bishop.h"


int main() {
    Bishop rook(Position('c', '5'), true);
    auto newRook = std::make_unique<Rook>(Position('e', '5'),false);
    std::vector<std::vector<std::unique_ptr<Piece>>> gameBoard(8);
    for (auto& row : gameBoard) {
        row.resize(8);
    }
    gameBoard[4][4] = std::move(newRook);
    rook.createPossibleMoves(gameBoard);

    std::cout << "Rook at " << rook.getLocation() << " (" << rook.getNotation() << ") moves:\n";

    for (auto& move : rook.getPossibleMoves()) {
        std::cout << move.toString() << '\n';
    }

    return 0;
}