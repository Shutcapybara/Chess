#include <iostream>
#include "rook.h"

int main() {
    Rook rook('A', '1');
    rook.createPossibleMoves(nullptr);

    std::cout << "Rook at " << rook.getLocation() << " (" << rook.getNotation() << ") moves:\n";
    for (const auto& move : rook.getPossibleMoves()) {
        std::cout << move << '\n';
    }

    return 0;
}
