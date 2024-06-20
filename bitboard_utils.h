#include <iostream>
#include <bitset>

using namespace std;

typedef uint64_t Bitboard;

Bitboard wPawns;
Bitboard wKnights;
Bitboard wBishops;
Bitboard wRooks;
Bitboard wQueens;
Bitboard wKing;

Bitboard bPawns;
Bitboard bKnights;
Bitboard bBishops;
Bitboard bRooks;
Bitboard bQueens;
Bitboard bKing;

// Utility boards
Bitboard allWhitePieces, allBlackPieces, allPieces;

void updateAllPieces() {
    allWhitePieces = wPawns | wKnights | wBishops | wRooks | wQueens | wKing;
    allBlackPieces = bPawns | bKnights | bBishops | bRooks | bQueens | bKing;
    allPieces = allWhitePieces | allBlackPieces;
}

void initBoard() {
    wPawns = 0x000000000000FF00;
    wKnights = 0x0000000000000042;
    wBishops = 0x0000000000000024;
    wRooks = 0x0000000000000081;
    wQueens = 0x0000000000000008;
    wKing = 0x0000000000000010;

    bPawns = 0x00FF000000000000;
    bKnights = 0x4200000000000000;
    bBishops = 0x2400000000000000;
    bRooks = 0x8100000000000000;
    bQueens = 0x0800000000000000;
    bKing = 0x1000000000000000;

    updateAllPieces();
}

// Bitboard Functionality
inline void setBit(Bitboard &board, int square) {
    board |= (1ULL << square); }
inline void clearBit(Bitboard &board, int square) {
    board &= ~(1ULL << square); }
inline void toggleBit(Bitboard &board, int square) {
    board ^= (1ULL << square); }
inline bool isBitSet(const Bitboard &board, int square) {
    return board & (1ULL << square); }

void printBB_bits(Bitboard board) {
    bitset<64> bits(board);
    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 8; file++) {
            cout << bits[rank * 8 + file] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

