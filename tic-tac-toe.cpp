#include "AI.h"

void PrintBoard(char (&board)[3][3]);
void UserTurn(char (&board)[3][3]);
int CheckWinner(char (&board)[3][3], bool turn);

int main(){

    char board[3][3] {0};
    bool turn = true;
    int fin = 0;
    AI opponent(board);
    
    while(fin == 0){
        if(turn){
            std::cout << "X turn" << std::endl;
            UserTurn(board);
        }else{
            std::cout << "Y turn" << std::endl;
            opponent.Solve();
        }
        PrintBoard(board);
        fin = CheckWinner(board, turn);
        turn = !turn;
    }

    if(fin == 1){
        std::cout << "X Wins" << std::endl;
    }else if(fin == 2){
        std::cout << "Y Wins" << std::endl;
    }else{
        std::cout << "Draw" << std::endl;
    }

    return 0;
}

void PrintBoard(char (&board)[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == 0){
                std::cout << ' ';
            }
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void UserTurn(char (&board)[3][3]){
    int x = -1;
    int y = -1;

    while(x < 1 || x > 3 || y < 1 || y > 3){
        if(!(x >= 1 && x <= 3)){
            std::cout << "x cordinate: ";
            std::cin >> x;
        }
        if(!(y >= 1 && y <= 3)){
            std::cout << "y cordinate: ";
            std::cin >> y;
        }

        std::cout << x << y << std::endl;
        if(board[x - 1][y - 1] != 0){
            x = -1;
            y = -1;
            std::cout << "empty" << std::endl;
        }else{
            std::cout << "filled" << std::endl;
        }
    }

    board[x - 1][y - 1] = 'X';
}

int CheckWinner(char (&board)[3][3], bool turn){
    int winner = 0;
    int playerWin = turn ? 1 : 2;

    // check for draw

    for(int i = 0; i < 3; i++){
        if(board[0][i] != 0){
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
                winner = playerWin;
            }
        }
    }

    for(int i = 0; i < 3; i++){
        if(board[i][0] != 0){
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                winner = playerWin;
            }
        }
    }

    if(board[0][0] != 0 && (board[0][0] == board[1][1] && board[1][1] == board[2][2])) {
        winner = playerWin;
    }

    if(board[0][2] != 0 && (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        winner = playerWin;
    }

    return winner;
}