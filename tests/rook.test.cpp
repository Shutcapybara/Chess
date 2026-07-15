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