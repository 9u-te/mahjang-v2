#pragma once
#include "mj_1H.h"
#include <algorithm>


struct YAKU;

class PLAYER
{
public:
    const int ID;
    int SCORE; // 得点

    MAHJANG_HI JIFU; // 自風

    MAHJANG_HI BAFU; // 場風
    inline static int yama_left_num = 0;

    std::vector<MAHJANG_HI> TEHAI;
    std::vector<MAHJANG_HI> PON;
    std::vector<MAHJANG_HI> CHI;
    std::vector<MAHJANG_HI> MINKAN;
    std::vector<MAHJANG_HI> ANKAN;
    std::vector<std::pair<int, MAHJANG_HI>> NAKI;

    std::vector<MAHJANG_HI> ANKO;
    std::vector<MAHJANG_HI> SHUNTSU;
    MAHJANG_HI HEAD_PAIR;

    MAHJANG_HI TSUMO;
    MAHJANG_HI KIRU;
    MAHJANG_HI AGARI;


    bool REACH_STICK; // 立直棒
    bool W_REACH_STICK;
    bool MENZEN;
    bool ONE_SHOT_FRAG;
    bool W_REACH_FRAG;

    PLAYER(int id) : ID(id), TEHAI(), PON(), CHI(), MINKAN(), ANKAN(), NAKI()
    {
        SCORE = 25000;
    }

    void repai();

    // 暗刻と順子リストをリセット
    void reset_mentsu();

    // 頭候補
    std::vector<MAHJANG_HI> atamaKouho(std::vector<MAHJANG_HI> tehai, MAHJANG_HI another_hi);

    // 再帰的に順子と暗刻に分ける
    bool sepAnkoShunts(std::vector<MAHJANG_HI> tehai);

    // 頭と順子と暗刻に分ける
    bool bunseki1(std::vector<MAHJANG_HI> tehai,MAHJANG_HI another_hi);

    //聴牌
    std::vector<MAHJANG_HI> TemPai0(const std::vector<MAHJANG_HI> &tehai);

    std::vector<std::vector<MAHJANG_HI>> TemPai1(MAHJANG_HI another_hi);

    // 立直する
    bool reachF();
    // ポンする
    bool ponF(MAHJANG_HI HI);
    // チーする
    bool chiF(MAHJANG_HI HI);
    // 明槓する
    bool minkanF(MAHJANG_HI HI);
    // 加槓する
    bool kakanF();
     // 暗槓する
    bool ankanF();
    //打牌
    MAHJANG_HI discard(int n);
    // ronagari
    //bool ronF();
    // tsumoagari
    bool tsumoF();
};