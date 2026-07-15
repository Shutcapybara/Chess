#include <catch2/catch_test_macros.hpp>
#include "position.h"

TEST_CASE("setting file to be an Uppercase Letter")
{
    char file = 'A';
    char rank = '1';
    CHECK_THROWS_AS(Position(file, rank),std::domain_error);
}

TEST_CASE("Setting file to be number character")
{
    char file = '1';
    char rank = '1';
    CHECK_THROWS_AS(Position(file, rank),std::domain_error);
}

TEST_CASE("Setting file to be an integer 1")
{
    char file = 1;
    char rank = '1';
    CHECK_THROWS_AS(Position(file, rank),std::domain_error);
}


TEST_CASE("Setting rank to be letter")
{
    char file = 'a';
    char rank = 'a';
    CHECK_THROWS_AS(Position(file, rank),std::domain_error);
}

TEST_CASE("Assigns valid Position")
{
    char file = 'a';
    char rank = '1';
    REQUIRE_NOTHROW(Position(file, rank));
    Position pos = Position(file, rank);
    CHECK(pos.file == file);
    CHECK(pos.rank == rank);
}

TEST_CASE("Valid Comparision test")
{
   Position pos1 = Position('a','1');
   Position pos2 = Position('a','1');
   CHECK(pos1 == pos2);

}

TEST_CASE("Differnt Position test")
{
   Position pos1 = Position('a','1');
   Position pos2 = Position('b','1');
   CHECK(pos1 != pos2);

}


TEST_CASE("Position ToString Valid")
{
    Position pos = Position('a','1');
    CHECK(pos.toString() == "a1");
}



