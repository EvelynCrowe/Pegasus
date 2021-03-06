#ifndef PEGASUS_STUFF_BOARD_OBJECT_H
#define PEGASUS_STUFF_BOARD_OBJECT_H

#include <cstdint>
#include <stack>

#include "constants.h"

namespace board {
    class Board {
        public:
            /* ------- independent fields, provide necessary information about board ------- */
            unsigned char chessboard[120];
            bool CWK, CWQ, CBK, CBQ; // castle rights
            char EP; // en passant rights: what column did a double jump just occur? -1 if no double jump. 
            short movesSinceLastCapture; // 50 move rule
            bool turnWhite; // whose turn it is
            std::stack<Move> moveHistory; // list of moves applied to starting FEN.

            /* ------- dependent fields, store information about board that is derived from independent fields -------- */
            short material; // changed material score to just be material for both
            uint64_t hashCode;
            
            unsigned char pieceLocations[12][10];
            unsigned char pieceNumbers[12]; // for example, piceNumbers[BP] = number of black pawns in the pieceLocations list

            /** 
             * Creates a new board with array set to INVALID. Usually you should call parseFen after creating a new board. 
             */
            Board() {
                // set up the chessboard with all INVALID
                for (int i = 0; i < 120; i++) {
                    chessboard[i] = INVALID;
                }
                movesSinceLastCapture = 0;
            }

            /** 
             * Boards are equal if all independent fields except moveHistory are equal. 
             * Note that comparing the hashes is MUCH faster that this, and should be used to compare boards
             * for most practical purposes. Really, this is just here to test if the hash function is working.
             */
            bool operator==(const Board& other) const {
                if (CBK != other.CBK || 
                    CBQ != other.CBQ || 
                    CWK != other.CWK || 
                    CWQ != other.CWQ ||
                    EP != other.EP ||
                    turnWhite != other.turnWhite ||
                    movesSinceLastCapture != other.movesSinceLastCapture) {
                    return false;
                }
                for (int i = 0; i < 120; i++) {
                    if (chessboard[i] != other.chessboard[i]) {
                        return false;
                    }
                }
                return true;
            }

    };
}

#endif //PEGASUS_STUFF_BOARD_OBJECT_H
