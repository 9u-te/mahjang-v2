#pragma once
#include "new-MJ_H.h"
class PLAYER;




namespace Yaku_n{
        
    //1翻役
    inline YAKU REACH(1,0, 0, false);//立直*
    inline YAKU TWO_TO_EIGHT(1,1, 0, false);//たんやお*
    inline YAKU MENZEN_TSUMO(1,0, 0, false);//門前自摸
    inline YAKU MY_WIND(1,1, 0, false);//自風*
    inline YAKU GRAND_WIND(1,1, 0, false);//場風*
    inline YAKU WHITE(1,1, 0, false);//白*
    inline YAKU GREEN(1,1, 0, false);//發*
    inline YAKU RED(1,1, 0, false);//中*
    inline YAKU PEACE(1,0, 0, false);//平和*
    inline YAKU ONE_ORDER(1,0, 0, false);//一盃口*
    inline YAKU SPEAR_SWORD(1,1, 0, false);//槍槓
    inline YAKU SUMMIT_FLOWER(1,1, 0, false);//嶺上開花
    inline YAKU UNDERSEA(1,1, 0, false);//海底撈月
    inline YAKU UNDERRIVER(1,1, 0, false);//河底撈魚
    inline YAKU ONE_SHOT(1,0, 0, false);//一発


    //2翻役
    inline YAKU W_REACH(2, 0, 0, false);//ダブル立直
    inline YAKU THREE_COLOR_SAME_ORDER(2, 1, 0, false);//三色同順*
    inline YAKU THREE_COLOR_SAME_COLORS(2, 2, 0, false);//三色同刻*
    inline YAKU THREE_SWORD(2, 2, 0, false);//三槓子*
    inline YAKU TOYTOY(2, 2, 0, false);//対々和*
    inline YAKU THREE_DARK_SAME(2, 2, 0, false);//三暗刻*
    inline YAKU SMALL_THREE_ORIGIN(2, 2, 0, false);//小三元*
    inline YAKU MIXED_OLD_HEAD(2, 2, 0, false);//混老頭*
    inline YAKU SEVEN_PAIRS(2, 0, 0, false);//七対子*
    inline YAKU MIXED(2, 1, 0, false);//チャンタ*
    inline YAKU STRAIGHT(2, 1, 0, false);//一気通貫*
    //3翻役
    inline YAKU TWO_ORDER(3, 0, 0, false);//二盃口*
    inline YAKU PURE_MIXED(3, 2, 0, false);//純チャン*
    inline YAKU MIXED_ONE_COLOR(3, 2, 0, false);//混一色*
    //6翻役
    inline YAKU PURE_ONE_COLOR(6, 5, 0, false);//清一色*
    //役満
    inline YAKU TENHO(0, 0, 1, false);//天和
    inline YAKU CHIHO(0, 0, 1, false);//地和
    inline YAKU BIG_THREE_ORIGIN(0, 0, 1, true);//大三元*
    inline YAKU FOUR_DARK_SAME(0, 0, 1, false);//四暗刻*
    inline YAKU CHAR_ONE_COLOR(0, 0, 1, true);//字一色*
    inline YAKU GREEN_ONE_COLOR(0, 0, 1, true);//緑一色*
    inline YAKU PURE_OLD_HEAD(0, 0, 1, true);//清老頭*
    inline YAKU SMALL_FOUR_PLEASURE(0, 0, 1, true);//小四喜*
    inline YAKU THIRTEEN_ORPHANS(0, 0, 1, false);//国士無双*
    inline YAKU FOUR_SWORD(0, 0, 1, true);//四槓子*
    inline YAKU NINE_GATES(0, 0, 1, false);//九蓮宝燈
    //ダブル役満
    inline YAKU FOUR_DARK_SAME_SINGLE(0, 0, 2, false);//四暗刻単騎*
    inline YAKU THIRTEEN_ORPHANS_SUPER(0, 0, 2, false);//国士無双13面待ち*
    inline YAKU PURE_NINE_GATES(0, 0, 2, false);//純正九蓮宝燈
    inline YAKU BIG_FOUR_PLEASURE(0, 0, 2, true);//大四喜*
}


namespace Yaku_F{


    //1翻役---------------------------------------------------------------------------
    bool REACH_F(const PLAYER *P);//立直
    bool MENZEN_TSUMO_F(const PLAYER *P);//自摸
    bool MY_WIND_F(const PLAYER *P);//自風
    bool GRAND_WIND_F(const PLAYER *P);//場風
    bool WHITE_F(const PLAYER *P);//白
    bool GREEN_F(const PLAYER *P);//發
    bool RED_F(const PLAYER *P);//中
    bool TWO_TO_EIGHT_F(const PLAYER *P);//たんやお
    bool PEACE_F(const PLAYER *P);//平和
    bool ONE_ORDER_F(const PLAYER *P);//一盃口
    bool UNDERSEA_F(const PLAYER *P);//海底撈月
    bool UNDERRIVER_F(const PLAYER *P);//河底撈魚
    bool ONE_SHOT_F(const PLAYER *P);//一発

    //2翻役---------------------------------------------------------------------------
    bool W_REACH_F(const PLAYER *P);//ダブル立直
    bool SEVEN_PAIRS_F(const PLAYER *P);//七対子
    bool SMALL_THREE_ORIGIN_F(const PLAYER *P);//小三元
    bool THREE_COLOR_SAME_ORDER_F(const PLAYER *P);//三色同順
    bool THREE_COLOR_SAME_COLORS_F(const PLAYER *P);//三色同刻
    bool THREE_SWORD_F(const PLAYER *P);//三槓子
    bool TOYTOY_F(const PLAYER *P);//対々和
    bool THREE_DARK_SAME_F(const PLAYER *P);//三暗刻
    bool MIXED_F(const PLAYER *P);//チャンタ
    bool STRAIGHT_F(const PLAYER *P);//一気通貫
    bool MIXED_OLD_HEAD_F(const PLAYER *P);//混老頭

    //3翻役---------------------------------------------------------------------------
    bool MIXED_ONE_COLOR_F(const PLAYER *P);//混一色
    bool PURE_MIXED_F(const PLAYER *P);//純チャン
    bool TWO_ORDER_F(const PLAYER *P);//二盃口
    
    //6翻役---------------------------------------------------------------------------
    bool PURE_ONE_COLOR_F(const PLAYER *P);//清一色
    
    //役満---------------------------------------------------------------------------
    bool BIG_THREE_ORIGIN_F(const PLAYER *P);//大三元
    bool FOUR_DARK_SAME_F(const PLAYER *P);//四暗刻
    bool CHAR_ONE_COLOR_F(const PLAYER *P);//字一色
    bool GREEN_ONE_COLOR_F(const PLAYER *P);//緑一色
    bool PURE_OLD_HEAD_F(const PLAYER *P);//清老頭
    bool SMALL_FOUR_PLEASURE_F(const PLAYER *P);//小四喜
    bool THIRTEEN_ORPHANS_F(const PLAYER *P);//国士無双
    bool FOUR_SWORD_F(const PLAYER *P);//四槓子
    bool NINE_GATES_F(const PLAYER *P);//九蓮宝燈
    bool TENHO_F(const PLAYER *P);//天和
    bool CHIHO_F(const PLAYER *P);//地和
    
    //ダブル役満---------------------------------------------------------------------------
    bool BIG_FOUR_PLEASURE_F(const PLAYER *P);//大四喜
    bool FOUR_DARK_SAME_SINGLE_F(const PLAYER *P);//四暗刻単騎
    bool PURE_NINE_GATES_F(const PLAYER *P);//純正九蓮宝燈
    bool THIRTEEN_ORPHANS_SUPER_F(const PLAYER *P);//国士無双13面待ち
       
}