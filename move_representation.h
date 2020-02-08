#ifndef PEGASUS_STUFF_MOVE_REPRESENTATION_H
#define PEGASUS_STUFF_MOVE_REPRESENTATION_H

#include <stdlib.h>
#include <iostream>
#include <array>

#include "constants.h"
#include "board_object.h"

namespace move_rep {

    #define NUM_MOVE_INDICES 7
    enum : unsigned char {
        startPosIndex /*6 bits*/, endPosIndex /*6 bits*/,
        castleIndex /*1 bits*/, enPassantIndex /*1 bits*/, captureIndex /*4 bits*/,
        promoteIndex /*1 bits*/, pieceThatMovedIndex /*4 bits*/};

    const UL numBits = sizeof(UL) * 8;
    // Redid this so its easier to work with lol
    constexpr const static unsigned short widths[NUM_MOVE_INDICES] = {
        6, 6,
        1, 1, 4,
        1, 4 };
    // Automatically calculated from widths for speed and maintainability.
    static unsigned short prefixRanges[NUM_MOVE_INDICES];

    /** All initialization of data required in this namespace */
    void init() {
        // calculate prefixRanges
        prefixRanges[0] = widths[0];
        for (unsigned char i = 1; i < NUM_MOVE_INDICES; i++) {
            prefixRanges[i] = prefixRanges[i-1] + widths[i];
            std::cout << "prefix " << i << " : " << prefixRanges[i] << std::endl;
        }
    }

    /**
     * Creates a new move given the parameters.
     * Required parameters: 
     *   <start/end>Position: 64-index of the moving piece (castling is done by a king move)
     *   pieceThatMoved: colored piece that is making the move
     * Optional parameters:
     *   castle: 0 = no castle, 1 = castle, can determine which side by start/end position
     *   enPassant: 0 = no enPassant, 1 = enPassant(either the capture or the initial forward 2 jump), can determine btw them by checking whether capture is empty or not, since the jump forward 2 cannot capture
     *   capture: the colored piece that was captured during this move
     *   promote: 0 = no promote, 1 = promote. If 1, pieceThatMoved will contain what it promoted to, can be assumed it WAS a pawn cuz only pawns promote
     * board::EMPTY is used for no capture/promote and stuff
     */
    Move encodeMove(short startPosition, short endPosition, short piece,
    short capturedPiece=board::EMPTY, bool castle=false, bool enPassant=false, bool promoted=false) {
        UL code = 0;
        // Get result by bit-shifting the inputs into place then or'ing the results
        code |= (startPosition << (numBits - prefixRanges[startPosIndex]));
        code |= (endPosition << (numBits - prefixRanges[endPosIndex]));
        code |= (castle << (numBits - prefixRanges[castleIndex]));
        code |= (enPassant << (numBits - prefixRanges[enPassantIndex]));
        code |= (capturedPiece << (numBits - prefixRanges[captureIndex]));
        code |= (promoted << (numBits - prefixRanges[promoteIndex]));
        code |= (piece << (numBits - prefixRanges[pieceThatMovedIndex]));

        return code;
    }

    // Generic decoder function, decodes "target" from "toDecode"
    // Meant to use move_rep::"enum" as "target"
    short decodeMove(Move code, unsigned short target){
        // Use bit operations to extract "len" bits starting from right-most bit "right"
        // Bit mask generated by shifting 1 to the left, then subtracting 1, then shifting: ex: 0000 0001 -> 0001 0000 -> 0000 1111 -> 0111 1000
        return ((1u << (prefixRanges[target] - ((target == 0) ? 0 : prefixRanges[target-1])) ) - 1u) & (code >> (numBits - prefixRanges[target]));
    }
};

#endif //PEGASUS_STUFF_MOVE_REPRESENTATION_H
