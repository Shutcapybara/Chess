#include <string>
#include <vector>
#include <stdexcept>
class Piece {
private:
    // eg E4
    std::string position;
    // eg K - King
    std::string key;
    std::vector<std::string> possibleMoves;

public:

    // Destructer
    virtual ~Piece() {}

    virtual void CreatePossibleMoves()  = 0; 

    std::vector<std::string> getPossibleMoves() {
        return possibleMoves;
    }

    std::string getLocation() {
        return position;
    }

    void Move(std::string newPosition) {
        if (std::find(possibleMoves.begin(), possibleMoves.end(), newPosition) != possibleMoves.end()) {
            position = newPosition;
        }
        else {
            throw std::invalid_argument("Invalid move" + key + " from " + position + " to " + newPosition);
        }
    }

    std::string GetNotation() {
        return key + position;
    }




};