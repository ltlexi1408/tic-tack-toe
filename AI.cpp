#include "AI.h"

AI::AI(char (&board)[3][3]) : board(board){
}

void AI::Solve(){
    board[0][0] = piece;
    board[1][0] = piece;
    board[2][0] = piece;
}