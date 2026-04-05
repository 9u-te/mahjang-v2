#pragma once
#include "new-MJ_P.h"


class YAKU{
    public:
        int han;
        int naki_han;
        int yaku_man;
        bool naki_yaku_man;
    
        YAKU(int h, int nh, int y, int ny){
            han = h;
            naki_han = nh;
            yaku_man = y;
            naki_yaku_man = ny;
        };
};    
        


 //1翻役---------------------------------------------------------------------------
        bool REACH_F(const PLAYER &P);//立直
        bool MENZEN_TSUMO_F(const PLAYER &P);//自摸
        bool MY_WIND_F(const PLAYER &P);//自風
        bool GRAND_WIND_F(const PLAYER &P);//場風
        bool WHITE_F(const PLAYER &P);//白
        bool GREEN_F(const PLAYER &P);//發
        bool RED_F(const PLAYER &P);//中
        bool TWO_TO_EIGHT_F(const PLAYER &P);//たんやお
        bool PEACE_F(const PLAYER &P);//平和
        bool ONE_ORDER_F(const PLAYER &P);//一盃口
        bool UNDERSEA_F(const PLAYER &P);//海底撈月
        bool UNDERRIVER_F(const PLAYER &P);//河底撈魚
        bool ONE_SHOT_F(const PLAYER &P);//一発

        //2翻役---------------------------------------------------------------------------
        bool W_REACH_F(const PLAYER &P);//ダブル立直
        bool SEVEN_PAIRS_F(const PLAYER &P);//七対子
        bool SMALL_THREE_ORIGIN_F(const PLAYER &P);//小三元
        bool THREE_COLOR_SAME_ORDER_F(const PLAYER &P);//三色同順
        bool THREE_COLOR_SAME_COLORS_F(const PLAYER &P);//三色同刻
        bool THREE_SWORD_F(const PLAYER &P);//三槓子
        bool TOYTOY_F(const PLAYER &P);//対々和
        bool THREE_DARK_SAME_F(const PLAYER &P);//三暗刻
        bool MIXED_F(const PLAYER &P);//チャンタ
        bool STRAIGHT_F(const PLAYER &P);//一気通貫
        bool MIXED_OLD_HEAD_F(const PLAYER &P);//混老頭

        //3翻役---------------------------------------------------------------------------
        bool MIXED_ONE_COLOR_F(const PLAYER &P);//混一色
        bool PURE_MIXED_F(const PLAYER &P);//純チャン
        bool TWO_ORDER_F(const PLAYER &P);//二盃口
        
        //6翻役---------------------------------------------------------------------------
        bool PURE_ONE_COLOR_F(const PLAYER &P);//清一色
        
        //役満---------------------------------------------------------------------------
        bool BIG_THREE_ORIGIN_F();//大三元
        bool FOUR_DARK_SAME_F();//四暗刻
        bool CHAR_ONE_COLOR_F();//字一色
        bool GREEN_ONE_COLOR_F();//緑一色
        bool PURE_OLD_HEAD_F();//清老頭
        bool SMALL_FOUR_PLEASURE_F();//小四喜
        bool THIRTEEN_ORPHANS_F();//国士無双
        bool FOUR_SWORD_F();//四槓子
        bool NINE_GATES_F();//九蓮宝燈
        bool TENHO_F();//天和
        bool CHIHO_F();//地和
        
        //ダブル役満---------------------------------------------------------------------------
        bool BIG_FOUR_PLEASURE_F();//大四喜
        bool FOUR_DARK_SAME_SINGLE_F();//四暗刻単騎
        bool PURE_NINE_GATES_F();//純正九蓮宝燈
        bool THIRTEEN_ORPHANS_SUPER_F();//国士無双13面待ち