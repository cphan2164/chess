#include "pieces.cpp"
#include "pieceLoc.cpp"

class Board {
public:
    Board() {
        // Initialize the board with empty squares
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                squares[i][j] = nullptr;
            }
        }
    }

    bool isOccupied(int x, int y) const {
        // Check if the given square is occupied
        return squares[x][y] != nullptr;
    }

    bool isOccupiedByOpponent(int x, int y, int color) const {
        // Check if the given square is occupied by an opponent's piece
        if (isOccupied(x, y)) {
            Pieces* piece = squares[x][y];
            return piece->getColor() != color;
        }
        return false;
    }

    void placePiece(Location location, Pieces* piece) {
        // Place a piece on the board at the specified location
        int x = location.getX();
        int y = location.getY();
        squares[x][y] = piece;
    }

    void removePiece(Location location) {
        // Remove a piece from the board at the specified location
        int x = location.getX();
        int y = location.getY();
        squares[x][y] = nullptr;
    }

    Pieces* getPiece(Location location) const {
        // Get the piece at the specified location
        int x = location.getX();
        int y = location.getY();
        return squares[x][y];
    }

    void printBoard() const {
        std::cout << "  a b c d e f g h" << std::endl;
        std::cout << " +----------------+" << std::endl;

        for (int y = 7; y >= 0; --y) {
            std::cout << y + 1 << "|";
            for (int x = 0; x < 8; ++x) {
                Pieces* piece = squares[x][y];
                if (piece != nullptr) {
                    std::string pieceType = piece->getType();
                    int pieceColor = piece->getColor();
                    char symbol = (pieceColor == 1) ? 'W' : 'B';  // 'W' for white, 'B' for black

                    std::cout << symbol << pieceType[0] << "|";
                } else {
                    std::cout << " |";
                }
            }
            std::cout << " " << y + 1 << std::endl;
        }

        std::cout << " +----------------+" << std::endl;
        std::cout << "  a b c d e f g h" << std::endl;
    }

private:
    Pieces* squares[8][8];
};