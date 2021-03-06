#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cstdint>

typedef uint32_t UL;
typedef uint32_t Move;
typedef unsigned char UC; // for convenience
typedef unsigned int uint; // for convenience

#define STARTING_MATERIAL 0 //TODO: what is an appropriate value?

// White is even, black is odd, and all pieces are less than EMPTY
// For example, WP means White Pawn, BN mean Black kNight
enum : unsigned char {WP, BP, WR, BR, WN, BN, WB, BB, WQ, BQ, WK, BK, EMPTY, INVALID};

const unsigned char blackPieces[6] = {BP, BR, BN, BB, BQ, BK};
const unsigned char whitePieces[6] = {WP, WR, WN, WB, WQ, WK};

const char index120to64[] = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1,  0,  1,  2,  3,  4,  5,  6,  7, -1,
    -1,  8,  9, 10, 11, 12, 13, 14, 15, -1,
    -1, 16, 17, 18, 19, 20, 21, 22, 23, -1,
    -1, 24, 25, 26, 27, 28, 29, 30, 31, -1,
    -1, 32, 33, 34, 35, 36, 37, 38, 39, -1,
    -1, 40, 41, 42, 43, 44, 45, 46, 47, -1,
    -1, 48, 49, 50, 51, 52, 53, 54, 55, -1,
    -1, 56, 57, 58, 59, 60, 61, 62, 63, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
};
const char index64to120[] = {
    21, 22, 23, 24, 25, 26, 27, 28,
    31, 32, 33, 34, 35, 36, 37, 38,
    41, 42, 43, 44, 45, 46, 47, 48,
    51, 52, 53, 54, 55, 56, 57, 58,
    61, 62, 63, 64, 65, 66, 67, 68,
    71, 72, 73, 74, 75, 76, 77, 78,
    81, 82, 83, 84, 85, 86, 87, 88,
    91, 92, 93, 94, 95, 96, 97, 98
};


//---------- 120 index position constants ---------//
// Corners of the board
#define ROOK_B_SHORT_CORNER 98 // h8
#define ROOK_B_LONG_CORNER 91 // a8
#define ROOK_W_SHORT_CORNER 28 // h1
#define ROOK_W_LONG_CORNER 21 // a1

// Castling constants
#define ROOK_B_SHORT_CASTLE_TO 96 // f8
#define ROOK_B_LONG_CASTLE_TO 94 // d8
#define ROOK_W_SHORT_CASTLE_TO 26 // f1
#define ROOK_W_LONG_CASTLE_TO 24 // d1

// piece value list:
// used as follows: PIECEVALUES[WP], for example
const short PIECEVALUES[] = {100, -100, 500, -500, 300, -300, 300, -300, 900, -900, 10000, -10000, 0};

const char* EMPTY_BOARD_FEN = "8/8/8/8/8/8/8/8 w - - 0 1";

const char* STARTING_BOARD_FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

#endif