#include <iostream>
#include "pieceLoc.cpp"
#include "board.cpp"

class Pieces{
public:
    Pieces(){
        return;
    }

    Pieces(int color){
        this->pieceColor = color;
    }

    int getColor(){
        return pieceColor;
    }

    void setColor(int color){
        this->pieceColor = color;
    }
    void pieceCaptured(){
        captured = true;
    }

    bool checkCapture(){
        return captured;
    }

    void setType(std::string types){
        this->type = types;
    }
    std::string getType(){
        return type;
    }

    virtual bool checkMove(Board board, Location cur, Location end) = 0;
private:
    int pieceColor;
    bool captured = false;
    std::string type;
};

class Rook : public Pieces{
public:
    Rook(int color){
        Pieces::setColor(color);
        Pieces::setType("Rook");
    }

    bool checkMove(Board board, Location cur, Location end) override {
        // Check if the move is valid for a rook
        int curX = cur.getX();
        int curY = cur.getY();
        int endX = end.getX();
        int endY = end.getY();

        if (curX == endX || curY == endY) {
            // The move is along a straight line (horizontal or vertical)
            // Check if there are any pieces in the way
            int minX = std::min(curX, endX);
            int minY = std::min(curY, endY);
            int maxX = std::max(curX, endX);
            int maxY = std::max(curY, endY);

            // Check if any squares between the start and end positions are occupied
            for (int i = minX + 1; i < maxX; i++) {
                if (board.isOccupied(i, curY)) {
                    return false;  // There is a piece blocking the move
                }
            }

            for (int j = minY + 1; j < maxY; j++) {
                if (board.isOccupied(curX, j)) {
                    return false;  // There is a piece blocking the move
                }
            }

            return true;  // The move is valid
        }

        return false;  // The move is not valid for a rook
    }
};

class Bishop : public Pieces {
public:
    Bishop(int color) {
        Pieces::setColor(color);
        Pieces::setType("Bishop");
    }

    bool checkMove(Board board, Location cur, Location end) override {
        // Check if the move is valid for a bishop
        int curX = cur.getX();
        int curY = cur.getY();
        int endX = end.getX();
        int endY = end.getY();

        if (abs(curX - endX) == abs(curY - endY)) {
            // The move is along a diagonal
            // Check if there are any pieces in the way
            int minX = std::min(curX, endX);
            int minY = std::min(curY, endY);
            int maxX = std::max(curX, endX);
            int maxY = std::max(curY, endY);

            int dx = (endX > curX) ? 1 : -1;
            int dy = (endY > curY) ? 1 : -1;

            int x = curX + dx;
            int y = curY + dy;

            while (x != endX && y != endY) {
                if (board.isOccupied(x, y)) {
                    return false;  // There is a piece blocking the move
                }

                x += dx;
                y += dy;
            }

            return true;  // The move is valid
        }

        return false;  // The move is not valid for a bishop
    }
};

class Knight : public Pieces {
public:
    Knight(int color) {
        Pieces::setColor(color);
        Pieces::setType("Knight");
    }

    bool checkMove(Board board, Location cur, Location end) override {
        // Check if the move is valid for a knight
        int curX = cur.getX();
        int curY = cur.getY();
        int endX = end.getX();
        int endY = end.getY();

        int dx = abs(curX - endX);
        int dy = abs(curY - endY);

        // Check if the move is a valid L-shape move for a knight
        if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {
            // Check if the destination square is unoccupied or occupied by an opponent's piece
            Pieces* piece = board.getPiece(end);
            if (piece == nullptr || piece->getColor() != getColor()) {
                return true;  // The move is valid
            }
        }

        return false;  // The move is not valid for a knight
    }
};

class Pawn : public Pieces {
public:
    Pawn(int color) : Pieces(color) {
        this->hasMoved = false;
    }

    bool checkMove(Board board, Location cur, Location end) override {
        int curX = cur.getX();
        int curY = cur.getY();
        int endX = end.getX();
        int endY = end.getY();

        int direction = getColor() == 1 ? 1 : -1;

        // Check if the move is forward
        if (curX == endX && curY + direction == endY && !board.isOccupied(endX, endY)) {
            return true;
        }

        // Check if the move is the initial two-square advance
        if (!hasMoved && curX == endX && curY + (2 * direction) == endY && !board.isOccupied(endX, endY) && !board.isOccupied(endX, endY - direction)) {
            return true;
        }

        // Check if the move is a capture
        if (std::abs(curX - endX) == 1 && curY + direction == endY && board.isOccupiedByOpponent(endX, endY, getColor())) {
            return true;
        }

        return false;
    }

private:
    bool hasMoved;
};

class Queen : public Pieces {
public:
    Queen(int color) {
        Pieces::setColor(color);
        Pieces::setType("Queen");
    }

    bool checkMove(Board board, Location cur, Location end) override {
        // Check if the move is valid for a queen
        int curX = cur.getX();
        int curY = cur.getY();
        int endX = end.getX();
        int endY = end.getY();

        // Check if the move is along a straight line (horizontal or vertical)
        if (curX == endX || curY == endY) {
            // Check if there are any pieces in the way
            int minX = std::min(curX, endX);
            int minY = std::min(curY, endY);
            int maxX = std::max(curX, endX);
            int maxY = std::max(curY, endY);

            // Check if any squares between the start and end positions are occupied
            for (int i = minX + 1; i < maxX; i++) {
                if (board.isOccupied(i, curY)) {
                    return false;  // There is a piece blocking the move
                }
            }

            for (int j = minY + 1; j < maxY; j++) {
                if (board.isOccupied(curX, j)) {
                    return false;  // There is a piece blocking the move
                }
            }

            return true;  // The move is valid
        }

        // Check if the move is along a diagonal
        if (abs(curX - endX) == abs(curY - endY)) {
            // Check if there are any pieces in the way
            int minX = std::min(curX, endX);
            int minY = std::min(curY, endY);
            int maxX = std::max(curX, endX);
            int maxY = std::max(curY, endY);

            int dx = (endX > curX) ? 1 : -1;
            int dy = (endY > curY) ? 1 : -1;

            int x = curX + dx;
            int y = curY + dy;

            while (x != endX && y != endY) {
                if (board.isOccupied(x, y)) {
                    return false;  // There is a piece blocking the move
                }

                x += dx;
                y += dy;
            }

            return true;  // The move is valid
        }

        return false;  // The move is not valid for a queen
    }
};

class King : public Pieces {
public:
    King(int color) {
        Pieces::setColor(color);
        Pieces::setType("King");
    }

    bool checkMove(Board board, Location cur, Location end) override {
        // Check if the move is valid for a king
        int curX = cur.getX();
        int curY = cur.getY();
        int endX = end.getX();
        int endY = end.getY();

        int dx = abs(curX - endX);
        int dy = abs(curY - endY);

        // Check if the move is a valid single square move for a king
        if ((dx == 1 && dy == 0) || (dx == 0 && dy == 1) || (dx == 1 && dy == 1)) {
            // Check if the destination square is unoccupied or occupied by an opponent's piece
            Pieces* piece = board.getPiece(end);
            if (piece == nullptr || piece->getColor() != getColor()) {
                return true;  // The move is valid
            }
        }

        return false;  // The move is not valid for a king
    }
};



