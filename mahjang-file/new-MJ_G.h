#pragma once
#include "new-MJ_C.h"
#include <random>
#include <iostream>

// ランダムシード
std::random_device rd;
std::mt19937 g(rd());

class Game
{
public:
    std::vector<MAHJANG_HI> YAMA;    // 山
    std::vector<MAHJANG_HI> WANGPAI; // 王牌

    MAHJANG_HI BAFU; // 場風
    int KanCount;

    std::vector<MAHJANG_HI> DraHyouji;
    std::vector<MAHJANG_HI> uraDraHyouji;

    std::vector<MAHJANG_HI> KAWA0, KAWA1, KAWA2, KAWA3;

    std::vector<PLAYER> players;
    int oya_id;

    Game();

    int dicision_oya();

    void initilize_kyoku(MAHJANG_HI bafu, int kyoku, int honba);
};