#include <iostream>
#include <vector>
#include <memory>
#include "Pieces/rook.h"

int main() {
    Rook rook('C', '5');

    std::vector<std::vector<std::unique_ptr<Piece>>> gameBoard(8);
    for (auto& row : gameBoard) {
        row.resize(8);
    }

    rook.createPossibleMoves(gameBoard);

    std::cout << "Rook at " << rook.getLocation() << " (" << rook.getNotation() << ") moves:\n";

    for (auto& move : rook.getPossibleMoves()) {
        std::cout << move.toString() << '\n';
    }

    return 0;
}