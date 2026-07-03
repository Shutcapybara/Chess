#include <string>
#pragma once
struct Position
{
    public:
    char file;
    char rank;

    // Default constructor so types that contain Position can be default-constructed
    Position()
        : file('A'), rank('1') {}

    Position(char f, char r)
    {
       file = f;
       rank = r;
    }

    std::string toString()
    {
        return std::string(1, file) + std::string(1, rank);
    }  
};
