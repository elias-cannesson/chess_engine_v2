#include <iostream>
#include <string>

#include "bitboard_utils.h"

using namespace std;

int main() {
    initBoard();
    printBB_bits(allPieces);
    return 1;
}