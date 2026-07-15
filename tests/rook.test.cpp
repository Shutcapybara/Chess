#include <catch2/catch_test_macros.hpp>
#include "rook.h"

TEST_CASE("valid Rook instiliziation")
{
    Position pos = Position('a', '1');
    bool isWhite = true;
    REQUIRE_NOTHROW(Rook(pos,isWhite));
    Rook rook = Rook(pos,isWhite);
    CHECK(rook.getPosition() == pos);
    CHECK(rook.isWhite == isWhite);
}

TEST_CASE("Rook possible moves only peice on the board")
{
    Position pos = Position('b', '2');
    bool isWhite = true;
    Rook rook = Rook(pos,isWhite);
    std::vector<std::vector<std::unique_ptr<Piece>>> gameBoard(4);
    for (auto& row : gameBoard) {
        row.resize(4);
    }

    rook.createPossibleMoves(gameBoard);
    CHECK(rook.getPossibleMoves().size() == 6);
    CHECK(rook.canMoveTo(Position('b', '3')));
    CHECK(rook.canMoveTo(Position('b', '4')));
    CHECK(rook.canMoveTo(Position('b', '1')));
    CHECK(rook.canMoveTo(Position('a', '2')));
    CHECK(rook.canMoveTo(Position('c', '2')));
    CHECK(rook.canMoveTo(Position('d', '2')));
    CHECK_FALSE(rook.canMoveTo(Position('b', '2')));
}

TEST_CASE("Rook has no Valid Moves")
{
    Position pos = Position('a', '1');
    bool isWhite = false;
    Rook rook = Rook(pos,isWhite);
    std::vector<std::vector<std::unique_ptr<Piece>>> gameBoard(4);
    for (auto& row : gameBoard) {
        row.resize(4);
    }
    auto newRook = std::make_unique<Rook>(Position('a', '2'),false);
    gameBoard[1][0] = std::move(newRook);

    newRook = std::make_unique<Rook>(Position('b', '1'),false);
    gameBoard[0][1] = std::move(newRook);
    rook.createPossibleMoves(gameBoard);
    CHECK(rook.getPossibleMoves().size() == 0);
}

TEST_CASE("Rook has no Valid Moves")
{
    Position pos = Position('a', '1');
    bool isWhite = false;
    Rook rook = Rook(pos,isWhite);
    std::vector<std::vector<std::unique_ptr<Piece>>> gameBoard(4);
    for (auto& row : gameBoard) {
        row.resize(4);
    }
    auto newRook = std::make_unique<Rook>(Position('a', '2'),false);
    gameBoard[1][0] = std::move(newRook);

    newRook = std::make_unique<Rook>(Position('b', '1'),false);
    gameBoard[0][1] = std::move(newRook);
    rook.createPossibleMoves(gameBoard);
    CHECK(rook.getPossibleMoves().size() == 0);
}




