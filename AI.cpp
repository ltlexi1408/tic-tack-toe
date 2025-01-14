#include "AI.h"

AI::AI(char (&board)[3][3]) : board(board){
}

void AI::Solve(){
    if(Win()){
        return;
    }
    if(Block()){
        return;
    }
    if(Fork()){
        return;
    }
    if(BlockFork()){
        return;
    }
    if(Center()){
        return;
    }
    if(OppositeCorner()){
        return;
    }
    if(EmptyCorner()){
        return;
    }
    if(EmptySide()){
        return;
    }
}

bool AI::Win(){
    for(int i = 0; i < 3; i++){
        if(board[0][i] == piece && board[0][i] == board[1][i] && board[2][i] == 0) {
            board[2][i] = piece;
            return true;
        }else if(board[1][i] == piece && board[1][i] == board[2][i] && board[0][i] == 0) {
            board[0][i] = piece;
            return true;
        }else if(board[2][i] == piece && board[2][i] == board[0][i] && board[1][i] == 0) {
            board[1][i] = piece;
            return true;
        }
    }

    for(int i = 0; i < 3; i++){
        if(board[i][0] == piece && board[i][0] == board[i][1] && board[i][2] == 0) {
            board[i][2] = piece;
            return true;
        }else if(board[i][1] == piece && board[i][1] == board[i][2] && board[i][0] == 0) {
            board[i][0] = piece;
            return true;
        }else if(board[i][2] == piece && board[i][2] == board[i][0] && board[i][1] == 0) {
            board[i][1] = piece;
            return true;
        }
    }

    if(board[0][0] == piece && board[0][0] == board[1][1] && board[2][2] == 0) {
        board[2][2] = piece;
        return true;
    }else if(board[1][1] == piece && board[1][1] == board[2][2] && board[0][0] == 0) {
        board[0][0] = piece;
        return true;
    }else if(board[2][2] == piece && board[2][2] == board[0][0] && board[1][1] == 0) {
        board[1][1] = piece;
        return true;
    }

    if(board[2][0] == piece && board[0][0] == board[1][1] && board[0][2] == 0) {
        board[0][2] = piece;
        return true;
    }else if(board[1][1] == piece && board[1][1] == board[2][0] && board[2][0] == 0) {
        board[2][0] = piece;
        return true;
    }else if(board[0][2] == piece && board[0][2] == board[2][0] && board[1][1] == 0) {
        board[1][1] = piece;
        return true;
    }

    return false;
}

bool AI::Block(){
        for(int i = 0; i < 3; i++){
        if(board[0][i] == user && board[0][i] == board[1][i] && board[2][i] == 0) {
            board[2][i] = piece;
            return true;
        }else if(board[1][i] == user && board[1][i] == board[2][i] && board[0][i] == 0) {
            board[0][i] = piece;
            return true;
        }else if(board[2][i] == user && board[2][i] == board[0][i] && board[1][i] == 0) {
            board[1][i] = piece;
            return true;
        }
    }

    for(int i = 0; i < 3; i++){
        if(board[i][0] == user && board[i][0] == board[i][1] && board[i][2] == 0) {
            board[i][2] = piece;
            return true;
        }else if(board[i][1] == user && board[i][1] == board[i][2] && board[i][0] == 0) {
            board[i][0] = piece;
            return true;
        }else if(board[i][2] == user && board[i][2] == board[i][0] && board[i][1] == 0) {
            board[i][1] = piece;
            return true;
        }
    }

    if(board[0][0] == user && board[0][0] == board[1][1] && board[2][2] == 0) {
        board[2][2] = piece;
        return true;
    }else if(board[1][1] == user && board[1][1] == board[2][2] && board[0][0] == 0) {
        board[0][0] = piece;
        return true;
    }else if(board[2][2] == user && board[2][2] == board[0][0] && board[1][1] == 0) {
        board[1][1] = piece;
        return true;
    }

    if(board[2][0] == user && board[0][0] == board[1][1] && board[0][2] == 0) {
        board[0][2] = piece;
        return true;
    }else if(board[1][1] == user && board[1][1] == board[2][0] && board[2][0] == 0) {
        board[2][0] = piece;
        return true;
    }else if(board[0][2] == user && board[0][2] == board[2][0] && board[1][1] == 0) {
        board[1][1] = piece;
        return true;
    }

    return false;
}

bool AI::Fork(){
    return false;
}

bool AI::BlockFork(){
    return false;
}

bool AI::Center(){
    return false;
}

bool AI::OppositeCorner(){
    if(board[0][0] == user && board[2][2] == 0) {
        board[2][2] = piece;
        return true;
    }
    if(board[0][2] ==  user && board[2][0] == 0) {
        board[2][0] = piece;
        return true;
    }
    if(board[2][2] ==  user && board[0][0] == 0) {
        board[0][0] = piece;
        return true;
    }
    if(board[2][0] ==  user && board[0][2] == 0) {
        board[0][2] = piece;
        return true;
    }

    return false;
}

bool AI::EmptyCorner(){
    if(board[0][0] == 0) {
        board[0][0] = piece;
        return true;
    }
    if(board[0][2] == 0) {
        board[0][2] = piece;
        return true;
    }
    if(board[2][2] == 0) {
        board[2][2] = piece;
        return true;
    }
    if(board[2][0] == 0) {
        board[2][0] = piece;
        return true;
    }

    return false;
}

bool AI::EmptySide(){
    if(board[0][1] == 0) {
        board[0][1] = piece;
        return true;
    }
    if(board[1][0] == 0) {
        board[1][0] = piece;
        return true;
    }
    if(board[1][2] == 0) {
        board[1][2] = piece;
        return true;
    }
    if(board[2][1] == 0) {
        board[2][1] = piece;
        return true;
    }

    return false;
}