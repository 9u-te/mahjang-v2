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

    int kyotaku;
    MAHJANG_HI BAFU; // 場風
    int KanCount;

    std::vector<MAHJANG_HI> DraHyouji;
    std::vector<MAHJANG_HI> uraDraHyouji;

    std::vector<MAHJANG_HI> KAWA0, KAWA1, KAWA2, KAWA3;

    std::vector<PLAYER> players;
    int player_num;
    int oya_id;

    Game();

    //oyagime
    int dicision_oya();
    //shokika
    void initilize_kyoku(MAHJANG_HI bafu, int kyoku, int honba);
    //tsumo raseru
    void TsumoAction(PLAYER &player);

    void suteru(MAHJANG_HI HI);

    void reachF();

    void ponF(MAHJANG_HI HI, int pon_player_num);

    int chiF(MAHJANG_HI HI);

    int minkanF(MAHJANG_HI HI);

    void doramekuri();


    void ryukyoku();

    void ron_tensu();

    void tsumo_tensu();

    
};