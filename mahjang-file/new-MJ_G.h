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

    int kyotaku;//供託にあるリーチ棒
    int honba;
    MAHJANG_HI BAFU; // 場風
    int KanCount;

    std::vector<MAHJANG_HI> DraHyouji;
    std::vector<MAHJANG_HI> uraDraHyouji;

    std::vector<std::vector<MAHJANG_HI>> KAWAs;

    std::vector<PLAYER> players;
    int current_player_num;
    int oya_id;

    Game();

    //oyagime
    int dicision_oya();
    //shokika
    void initilize_kyoku(MAHJANG_HI bafu, int kyoku, int honba);
    //tsumo raseru
    void TsumoAction(PLAYER &player);

    void discard(MAHJANG_HI HI, int suteru_player_num);

    void reachF();

    int ponF(MAHJANG_HI HI, int pon_player_num);

    void chiF(MAHJANG_HI HI, int chi_player_num);

    int minkanF(MAHJANG_HI HI, int kan_player_num);

    void doramekuri();

    void ryukyoku();

    void ron_tensu(int winner);

    void tsumo_tensu();


    void yaku_hantei(PLAYER &P);

    void play_kyoku();

};