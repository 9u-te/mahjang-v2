#pragma once
#include "new-MJ_H.h"

class PLAYER{
    public:
        int id;
        int points;//得点

        MAHJANG_HI JIFU;//自風

        std::vector<MAHJANG_HI> TEHAI;
        std::vector<MAHJANG_HI> PON;
        std::vector<MAHJANG_HI> CHI;
        std::vector<MAHJANG_HI> MINKAN;
        std::vector<MAHJANG_HI> ANKAN;
        std::vector<MAHJANG_HI> KAWA;

        std::vector<MAHJANG_HI> ANKO;
        std::vector<MAHJANG_HI> SHUNTSU;
        MAHJANG_HI HEAD_PAIR;

        MAHJANG_HI TSUMO;
        MAHJANG_HI KIRU;
        MAHJANG_HI AGARI;
        

        bool REACH_STICK;//立直棒
        bool MENZEN;
        bool ONE_SHOT_FRAG;
        bool W_REACH_FRAG;
};