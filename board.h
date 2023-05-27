#ifndef BOARD_H
#define BOARD_H

#include "pieces.cpp"
#include "pieceLoc.cpp"

class Board {
public:
    Board();

    bool isOccupied(int x, int y) const;
    bool isOccupiedByOpponent(int x, int y, int color) const;
    void placePiece(Location location, Pieces* piece);
    void removePiece(Location location);
    Pieces* getPiece(Location location) const;
    void printBoard() const;

private:
    Pieces* squares[8][8];
};

Board::Board() {}

bool Board::isOccupied(int x, int y) const {}

bool Board::isOccupiedByOpponent(int x, int y, int color) const {}

void Board::placePiece(Location location, Pieces* piece) {}


void Board::removePiece(Location location) {}


Pieces* Board::getPiece(Location location) const {}

void Board::printBoard() const {}

#endif // BOARD_H