#pragma once
#include "new-MJ_C.h"

class Game{
    public:
        std::vector<MAHJANG_HI> YAMA;
        std::vector<MAHJANG_HI> WANGPAI;

        MAHJANG_HI BAFU;
        
        std::vector<MAHJANG_HI> KAWA0, KAWA1, KAWA2, KAWA3;
        
        PLAYER player0, player1, player2, player3;

        Game();

        void initilize_kyoku();
        
        
        
};