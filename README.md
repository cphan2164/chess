# Chess Program (Work in Progress)

This is a chess program that is currently a work in progress. It aims to provide a basic implementation of a chess game using object-oriented programming principles.

## Features

- The program supports the movement rules of various chess pieces, including pawns, rooks, knights, bishops, queens, and kings.
- It enforces the basic rules of chess, such as legal moves and capturing opponent pieces.
- The program keeps track of the state of the chessboard and the positions of the pieces.
- The board is displayed in the console, allowing players to visualize the game.
- The program currently does not include advanced features like checkmate detection, castling, pawn promotion, and en passant capture.

## Usage

The program is written in C++ and consists of multiple source files:

- `main.cpp`: Contains the main function to run the chess program.
- `board.cpp`: Implements the `Board` class, which represents the chessboard and manages the pieces.
- `pieces.cpp`: Defines the base `Pieces` class and derived classes for different chess pieces (e.g., `Rook`, `Knight`, `Bishop`, `Queen`, `King`, `Pawn`).
- `pieceLoc.cpp`: Implements the `Location` class, which represents a specific position on the chessboard.

## Future Enhancements

The current version of the chess program is still a work in progress, and there are several features and improvements planned for the future:
- Add user movement for pieces
- Implement checkmate detection to determine the end of the game.
- Add support for castling, pawn promotion, and en passant capture.
- Implement an AI opponent to play against the human player.
- Improve the user interface by implementing a graphical representation of the chessboard.
- Enhance the program's efficiency and performance.
- Incorporate additional chess variants and game modes.

Made by Conor Phan
