#include <iostream>

void PrintBoard(char (&board)[3][3]);

int main(){

    char board[3][3] {0};

    board[1][2] = 'X';

    PrintBoard(board);

    return 0;
}

void PrintBoard(char (&board)[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}