#include "AI.h"

AI::AI(char (&board)[3][3]) : board(board){
}

void AI::Solve(){
    std::cout << "AI code" << std::endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == 0){
                std::cout << ' ';
            }
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}