#include <iostream>

class AI{
    public:
        char piece = 'Y';
        char (&board)[3][3];
        AI(char (&board)[3][3]);
        void Solve();
    
    private:
        void Win();
        void Block();
        void Fork();
        void BlockFork();
        void Center();
        void OppositeCorner();
        void EmptyCorner();
        void EmptySide();
};