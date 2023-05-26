#include <iostream>
#include "board.cpp"
#include "pieceLoc.cpp"
#include "pieces.cpp"

int main() {
    // Create a new chess board
    Board board;

    // Create and place pieces on the board
    Rook rook1(1);
    Rook rook2(1);
    Rook rook3(2);
    Rook rook4(2);
    Knight knight1(1);
    Knight knight2(1);
    Knight knight3(2);
    Knight knight4(2);
    Bishop bishop1(1);
    Bishop bishop2(1);
    Bishop bishop3(2);
    Bishop bishop4(2);
    Pawn pawn1(1);
    Pawn pawn2(1);
    Pawn pawn3(2);
    Pawn pawn4(2);
    Queen queen1(1);
    Queen queen2(2);
    King king1(1);
    King king2(2);


    // Place the pieces on the board
    board.placePiece(Location(0, 0), &rook1);
    board.placePiece(Location(7, 0), &rook2);
    board.placePiece(Location(0, 7), &rook3);
    board.placePiece(Location(7, 7), &rook4);
    board.placePiece(Location(1, 0), &knight1);
    board.placePiece(Location(6, 0), &knight2);
    board.placePiece(Location(1, 7), &knight3);
    board.placePiece(Location(6, 7), &knight4);
    board.placePiece(Location(2, 0), &bishop1);
    board.placePiece(Location(5, 0), &bishop2);
    board.placePiece(Location(2, 7), &bishop3);
    board.placePiece(Location(5, 7), &bishop4);
    board.placePiece(Location(0, 1), &pawn1);
    board.placePiece(Location(1, 1), &pawn2);
    board.placePiece(Location(0, 6), &pawn3);
    board.placePiece(Location(1, 6), &pawn4);
    board.placePiece(Location(0, 3), &queen1);
    board.placePiece(Location(7, 3), &queen2);
    board.placePiece(Location(0, 4), &king1);
    board.placePiece(Location(7, 4), &king2);

    // Print the initial board state
    std::cout << "Initial Board State:" << std::endl;
    board.printBoard();

    // Perform some moves and print the updated board state
    std::cout << "Performing moves..." << std::endl;
    board.printBoard();

    return 0;
}
