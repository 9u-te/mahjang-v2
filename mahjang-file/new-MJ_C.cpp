#include "new-MJ_C.h"
namespace Calc {
    int FU_CAL(const PLAYER &P){
        if(SEVEN_PAIRS_F(P)) return 25;
    
        if(PEACE_F(P)){
            if(P.AGARI == P.TSUMO) return 20;
            else return 30;
        }
    
        int Fu = 20;
    
        //面子-----------------
        for(MAHJANG_HI HI : P.PON){
            if(HI.TYPE < 3 && HI.RANK != 1 && HI.RANK != 9) Fu += 2;
            else Fu += 4;
        }
    
        for(MAHJANG_HI HI : P.ANKO){
            if(HI.TYPE < 3 && HI.RANK != 1 && HI.RANK != 9) Fu += 4;
            else Fu += 8;
        }
    
        for(MAHJANG_HI HI : P.MINKAN){
            if(HI.TYPE < 3 && HI.RANK != 1 && HI.RANK != 9) Fu += 8;
            else Fu += 16;
        }
    
        for(MAHJANG_HI HI : P.ANKAN){
            if(HI.TYPE < 3 && HI.RANK != 1 && HI.RANK != 9) Fu += 16;
            else Fu += 32;
        }
    
        //雀頭---------------------------------
        if(P.HEAD_PAIR == P.JIFU) Fu += 2;
        if(P.HEAD_PAIR == BAFU) Fu += 2;
        if(P.HEAD_PAIR == HAK) Fu += 2;
        if(P.HEAD_PAIR == HAT) Fu += 2;
        if(P.HEAD_PAIR == CHU) Fu += 2;
    
        //待ちの形
        for(MAHJANG_HI shu : P.SHUNTSU){
            if(P.AGARI == shu + 1){
                Fu += 2;
                break;
            }
            if(P.AGARI == shu + 2 && P.AGARI.RANK == 3){
                Fu += 2;
                break;
            }
            if(P.AGARI == shu && P.AGARI.RANK == 7){
                Fu += 2;
                break;
            }
        }
        if(P.AGARI == P.HEAD_PAIR) Fu += 2;
    
        //上がり方
        if(P.AGARI == P.TSUMO) Fu += 2;
        else if(P.MENZEN) Fu += 10;
    
        if(Fu == 20) return 30;
    
        return (Fu + 9)/10 * 10;
    }
    
    std::vector<YAKU> YAKU_CAL(const PLAYER &P){
        std::vector<YAKU> yaku_list;
        if(REACH_F(P)) yaku_list.push_back(REACH);
        if(TWO_TO_EIGHT_F(P)) yaku_list.push_back(TWO_TO_EIGHT);
        if(MENZEN_TSUMO_F(P)) yaku_list.push_back(MENZEN_TSUMO);
        if(MY_WIND_F(P)) yaku_list.push_back(MY_WIND);
        if(GRAND_WIND_F(P)) yaku_list.push_back(GRAND_WIND);
        if(WHITE_F(P)) yaku_list.push_back(WHITE);
        if(GREEN_F(P)) yaku_list.push_back(GREEN);
        if(RED_F(P)) yaku_list.push_back(RED);
        if(PEACE_F(P)) yaku_list.push_back(PEACE);
        if(ONE_ORDER_F(P)) yaku_list.push_back(ONE_ORDER);
        //if(SPEAR_SWORD_F(P)) yaku_list.push_back(SPEAR_SWORD);
        if(UNDERSEA_F(P)) yaku_list.push_back(UNDERSEA);
        if(UNDERRIVER_F(P)) yaku_list.push_back(UNDERRIVER);
        if(ONE_SHOT_F(P)) yaku_list.push_back(ONE_SHOT);
        //2翻役---------------------------------------------------------------------------
        if(W_REACH_F(P)) yaku_list.push_back(W_REACH);
        if(SEVEN_PAIRS_F(P)) yaku_list.push_back(SEVEN_PAIRS);
        if(SMALL_THREE_ORIGIN_F(P)) yaku_list.push_back(SMALL_THREE_ORIGIN);
        if(THREE_COLOR_SAME_ORDER_F(P)) yaku_list.push_back(THREE_COLOR_SAME_ORDER);
        if(THREE_COLOR_SAME_COLORS_F(P)) yaku_list.push_back(THREE_COLOR_SAME_COLORS);
        if(THREE_SWORD_F(P)) yaku_list.push_back(THREE_SWORD);
        if(TOYTOY_F(P)) yaku_list.push_back(TOYTOY);
        if(THREE_DARK_SAME_F(P)) yaku_list.push_back(THREE_DARK_SAME);
        if(MIXED_F(P)) yaku_list.push_back(MIXED);
        if(STRAIGHT_F(P)) yaku_list.push_back(STRAIGHT);
        if(MIXED_OLD_HEAD_F(P)) yaku_list.push_back(MIXED_OLD_HEAD);
        //3翻役---------------------------------------------------------------------------
        if(MIXED_ONE_COLOR_F(P)) yaku_list.push_back(MIXED_ONE_COLOR);
        if(PURE_MIXED_F(P)) yaku_list.push_back(PURE_MIXED);
        if(TWO_ORDER_F(P)) yaku_list.push_back(TWO_ORDER); 
        //6翻役---------------------------------------------------------------------------
        if(PURE_ONE_COLOR_F(P)) yaku_list.push_back(PURE_ONE_COLOR);   
        //役満---------------------------------------------------------------------------
        if(BIG_THREE_ORIGIN_F(P)) yaku_list.push_back(BIG_THREE_ORIGIN);
        if(FOUR_DARK_SAME_F(P)) yaku_list.push_back(FOUR_DARK_SAME);
        if(CHAR_ONE_COLOR_F(P)) yaku_list.push_back(CHAR_ONE_COLOR);
        if(GREEN_ONE_COLOR_F(P)) yaku_list.push_back(GREEN_ONE_COLOR);
        if(PURE_OLD_HEAD_F(P)) yaku_list.push_back(PURE_OLD_HEAD);
        if(SMALL_FOUR_PLEASURE_F(P)) yaku_list.push_back(SMALL_FOUR_PLEASURE);
        if(THIRTEEN_ORPHANS_F(P)) yaku_list.push_back(THIRTEEN_ORPHANS);
        if(FOUR_SWORD_F(P)) yaku_list.push_back(FOUR_SWORD);
        if(NINE_GATES_F(P)) yaku_list.push_back(NINE_GATES);
        if(TENHO_F(P)) yaku_list.push_back(TENHO);
        if(CHIHO_F(P)) yaku_list.push_back(CHIHO);
        //ダブル役満---------------------------------------------------------------------------
        if(BIG_FOUR_PLEASURE_F(P)) yaku_list.push_back(BIG_FOUR_PLEASURE);
        if(FOUR_DARK_SAME_SINGLE_F(P)) yaku_list.push_back(FOUR_DARK_SAME_SINGLE);
        if(PURE_NINE_GATES_F(P)) yaku_list.push_back(PURE_NINE_GATES);
        if(THIRTEEN_ORPHANS_SUPER_F(P)) yaku_list.push_back(THIRTEEN_ORPHANS_SUPER);
    }
    
    int HAN_CAL(const PLAYER &P){
        std::vector<YAKU> yaku_list = YAKU_CAL(P);
        int all_yaku;
        for(YAKU y : yaku_list){
            all_yaku += P.MENZEN ? y.han : y.naki_han;
        }    
    }
    
    int YAKUMAN_CAL(const PLAYER &P){
        std::vector<YAKU> yaku_list = YAKU_CAL(P);
        int all_yakuman;
        for(YAKU y : yaku_list){
            all_yakuman += y.yaku_man;
        } 
    }
    
    int DORA_CAL(const PLAYER &P){
        
    }
    
    int STANDARD_POINTS(const PLAYER &P){
        int yakuman_num = YAKUMAN_CAL(P);
        if(yakuman_num > 0) return yakuman_num * 8000;
    
        int han = HAN_CAL(P);
        int Fu = 
    
        if(yaku_num >= 13) return 8000;
    
        if(yaku_num < 13 && yaku_num >= 11) return 6000;
    
        if(yaku_num < 11 && yaku_num >= 8) return 4000;
    
        if(yaku_num < 8 && yaku_num >= 6) return 3000;
    
        if(yaku_num == 5) return 2000;
    
        if()
    
    
        
    }
}