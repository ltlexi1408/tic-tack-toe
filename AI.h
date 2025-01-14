#include <iostream>

class AI{
    public:
        char piece = 'O';
        char user = 'X';
        char (&board)[3][3];
        AI(char (&board)[3][3]);
        void Solve();
    
    private:
        bool Win();
        bool Block();
        bool Fork();
        bool BlockFork();
        bool Center();
        bool OppositeCorner();
        bool EmptyCorner();
        bool EmptySide();
};