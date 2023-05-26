#include "pieces.cpp"

class Location {
public:
    Location(int x, int y) {
        this->piece = nullptr;
        this->x = x;
        this->y = y;
    }

    int getX() {
        return this->x;
    }

    int getY() {
        return this->y;
    }

    void setX(int x2) {
        this->x = x2;
    }

    void setY(int y2) {
        this->y = y2;
    }

    Pieces* getPiece() {
        return this->piece;
    }

    void setPiece(Pieces* piece) {
        this->piece = piece;
    }

private:
    Pieces* piece;
    int x;
    int y;
};