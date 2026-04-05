#pragma once
#include "new-MJ_H.h"
#include <algorithm>

class PLAYER{
    public:
        int ID;
        int POINTS;//得点

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
        bool W_REACH_STICK;
        bool MENZEN;
        bool ONE_SHOT_FRAG;
        bool W_REACH_FRAG;

        PLAYER(int id){
            ID = id;
            POINTS = 25000;
        }

        void repai();

        //暗刻と順子リストをリセット
        void reset_mentsu();

        //頭候補
        std::vector<MAHJANG_HI> bunseki0();

        //再帰的に順子と暗刻に分ける
        bool bunseki1(std::vector<MAHJANG_HI> tehai);

        //頭と順子と暗刻に分ける
        bool bunseki2();
};