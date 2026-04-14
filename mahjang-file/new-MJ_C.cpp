#include "new-MJ_C.h"
#include "new-MJ_P.h"

namespace Calc {
    int FU_CAL(const PLAYER &P){
        if(Yaku_F::SEVEN_PAIRS_F(&P)) return 25;
    
        if(Yaku_F::PEACE_F(&P)){
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
        if(P.HEAD_PAIR == P.BAFU) Fu += 2;
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
        using namespace Yaku_n;
        
        std::vector<YAKU> yaku_list;
        if(Yaku_F::REACH_F(&P)) yaku_list.push_back(REACH);
        if(Yaku_F::TWO_TO_EIGHT_F(&P)) yaku_list.push_back(TWO_TO_EIGHT);
        if(Yaku_F::MENZEN_TSUMO_F(&P)) yaku_list.push_back(MENZEN_TSUMO);
        if(Yaku_F::MY_WIND_F(&P)) yaku_list.push_back(MY_WIND);
        if(Yaku_F::GRAND_WIND_F(&P)) yaku_list.push_back(GRAND_WIND);
        if(Yaku_F::WHITE_F(&P)) yaku_list.push_back(WHITE);
        if(Yaku_F::GREEN_F(&P)) yaku_list.push_back(GREEN);
        if(Yaku_F::RED_F(&P)) yaku_list.push_back(RED);
        if(Yaku_F::PEACE_F(&P)) yaku_list.push_back(PEACE);
        if(Yaku_F::ONE_ORDER_F(&P)) yaku_list.push_back(ONE_ORDER);
        //if(SPEAR_SWORD_F(&P)) yaku_list.push_back(SPEAR_SWORD);
        if(Yaku_F::UNDERSEA_F(&P)) yaku_list.push_back(UNDERSEA);
        if(Yaku_F::UNDERRIVER_F(&P)) yaku_list.push_back(UNDERRIVER);
        if(Yaku_F::ONE_SHOT_F(&P)) yaku_list.push_back(ONE_SHOT);
        //2翻役---------------------------------------------------------------------------
        if(Yaku_F::W_REACH_F(&P)) yaku_list.push_back(W_REACH);
        if(Yaku_F::SEVEN_PAIRS_F(&P)) yaku_list.push_back(SEVEN_PAIRS);
        if(Yaku_F::SMALL_THREE_ORIGIN_F(&P)) yaku_list.push_back(SMALL_THREE_ORIGIN);
        if(Yaku_F::THREE_COLOR_SAME_ORDER_F(&P)) yaku_list.push_back(THREE_COLOR_SAME_ORDER);
        if(Yaku_F::THREE_COLOR_SAME_COLORS_F(&P)) yaku_list.push_back(THREE_COLOR_SAME_COLORS);
        if(Yaku_F::THREE_SWORD_F(&P)) yaku_list.push_back(THREE_SWORD);
        if(Yaku_F::TOYTOY_F(&P)) yaku_list.push_back(TOYTOY);
        if(Yaku_F::THREE_DARK_SAME_F(&P)) yaku_list.push_back(THREE_DARK_SAME);
        if(Yaku_F::MIXED_F(&P)) yaku_list.push_back(MIXED);
        if(Yaku_F::STRAIGHT_F(&P)) yaku_list.push_back(STRAIGHT);
        if(Yaku_F::MIXED_OLD_HEAD_F(&P)) yaku_list.push_back(MIXED_OLD_HEAD);
        //3翻役---------------------------------------------------------------------------
        if(Yaku_F::MIXED_ONE_COLOR_F(&P)) yaku_list.push_back(MIXED_ONE_COLOR);
        if(Yaku_F::PURE_MIXED_F(&P)) yaku_list.push_back(PURE_MIXED);
        if(Yaku_F::TWO_ORDER_F(&P)) yaku_list.push_back(TWO_ORDER); 
        //6翻役---------------------------------------------------------------------------
        if(Yaku_F::PURE_ONE_COLOR_F(&P)) yaku_list.push_back(PURE_ONE_COLOR);   
        //役満---------------------------------------------------------------------------
        if(Yaku_F::BIG_THREE_ORIGIN_F(&P)) yaku_list.push_back(BIG_THREE_ORIGIN);
        if(Yaku_F::FOUR_DARK_SAME_F(&P)) yaku_list.push_back(FOUR_DARK_SAME);
        if(Yaku_F::CHAR_ONE_COLOR_F(&P)) yaku_list.push_back(CHAR_ONE_COLOR);
        if(Yaku_F::GREEN_ONE_COLOR_F(&P)) yaku_list.push_back(GREEN_ONE_COLOR);
        if(Yaku_F::PURE_OLD_HEAD_F(&P)) yaku_list.push_back(PURE_OLD_HEAD);
        if(Yaku_F::SMALL_FOUR_PLEASURE_F(&P)) yaku_list.push_back(SMALL_FOUR_PLEASURE);
        if(Yaku_F::THIRTEEN_ORPHANS_F(&P)) yaku_list.push_back(THIRTEEN_ORPHANS);
        if(Yaku_F::FOUR_SWORD_F(&P)) yaku_list.push_back(FOUR_SWORD);
        if(Yaku_F::NINE_GATES_F(&P)) yaku_list.push_back(NINE_GATES);
        if(Yaku_F::TENHO_F(&P)) yaku_list.push_back(TENHO);
        if(Yaku_F::CHIHO_F(&P)) yaku_list.push_back(CHIHO);
        //ダブル役満---------------------------------------------------------------------------
        if(Yaku_F::BIG_FOUR_PLEASURE_F(&P)) yaku_list.push_back(BIG_FOUR_PLEASURE);
        if(Yaku_F::FOUR_DARK_SAME_SINGLE_F(&P)) yaku_list.push_back(FOUR_DARK_SAME_SINGLE);
        if(Yaku_F::PURE_NINE_GATES_F(&P)) yaku_list.push_back(PURE_NINE_GATES);
        if(Yaku_F::THIRTEEN_ORPHANS_SUPER_F(&P)) yaku_list.push_back(THIRTEEN_ORPHANS_SUPER);

        return yaku_list;
    }
    
    int HAN_CAL(const PLAYER &P){
        std::vector<YAKU> yaku_list = Calc::YAKU_CAL(P);
        int all_yaku = 0;
        for(YAKU y : yaku_list){
            all_yaku += P.MENZEN ? y.han : y.naki_han;
        }
        
    }
    
    int YAKUMAN_CAL(const PLAYER &P){
        std::vector<YAKU> yaku_list = Calc::YAKU_CAL(P);
        int all_yakuman = 0;
        for(YAKU y : yaku_list){
            all_yakuman += y.yaku_man;
        } 
    }
    
    int DORA_CAL(const PLAYER &P){
        
    }
    
    int STANDARD_POINTS(const PLAYER &P){
        int yakuman_num = Calc::YAKUMAN_CAL(P);
        if(yakuman_num > 0) return yakuman_num * 8000;
    
        int han = Calc::HAN_CAL(P) + Calc::DORA_CAL(P);
        int Fu = Calc::FU_CAL(P);
    
        if(han >= 13) return 8000;
    
        if(han < 13 && han >= 11) return 6000;
    
        if(han < 11 && han >= 8) return 4000;
    
        if(han < 8 && han >= 6) return 3000;
    
        if(han == 5) return 2000;
    
        int STP = Fu * (1 << (han + 2));

        if(STP > 2000) return 2000;

        return (Fu + 99)/100 * 100;
    
        
    }
}