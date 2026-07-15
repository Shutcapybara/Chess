#include <string>
#include <iostream>
#pragma once
struct Position
{
    public:
    char file;
    char rank;

    // Default constructor so types that contain Position can be default-constructed
    Position()
        : file('a'), rank('1') {}

    Position(char f, char r)
    {
        if (!std::isalpha(f))
        {
            throw std::domain_error("File needs to be an lowercase english letter");
        }
        if (std::isupper(f))
        {
            throw std::domain_error("File needs to be an lowercase letter");
        }
        if (!std::isdigit(r))
        {
            throw std::domain_error("rank needs to be an number character");
        }
        file = f;
        rank = r;
    }

    // isequal
    bool operator==(const Position&) const = default;

    std::string toString()
    {
        return std::string(1, file) + std::string(1, rank);
    }  
};
