#include "new-MJ_Y.h"

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




//1翻役-------------------------------------------

bool REACH_F(const PLAYER &P){
    return P.REACH_STICK;
}

bool MENZEN_TSUMO_F(const PLAYER &P){
    return P.MENZEN;
}

bool MY_WIND_F(const PLAYER &P){
    if(std::find(P.ANKO.begin(), P.ANKO.end(), P.JIFU) != P.ANKO.end()) return true;
    if(std::find(P.PON.begin(), P.PON.end(), P.JIFU) != P.PON.end()) return true;
    if(std::find(P.ANKAN.begin(), P.ANKAN.end(), P.JIFU) != P.ANKAN.end()) return true;
    if(std::find(P.MINKAN.begin(), P.MINKAN.end(), P.JIFU) != P.MINKAN.end()) return true;
    return false;
}

bool GRAND_WIND_F(const PLAYER &P){
    if(std::find(P.ANKO.begin(), P.ANKO.end(), BAFU) != P.ANKO.end()) return true;
    if(std::find(P.PON.begin(), P.PON.end(), BAFU) != P.PON.end()) return true;
    if(std::find(P.ANKAN.begin(), P.ANKAN.end(), BAFU) != P.ANKAN.end()) return true;
    if(std::find(P.MINKAN.begin(), P.MINKAN.end(), BAFU) != P.MINKAN.end()) return true;
    return false;
}

bool WHITE_F(const PLAYER &P){
    if(std::find(P.ANKO.begin(), P.ANKO.end(), HAK) != P.ANKO.end()) return true;
    if(std::find(P.PON.begin(), P.PON.end(), HAK) != P.PON.end()) return true;
    if(std::find(P.ANKAN.begin(), P.ANKAN.end(), HAK) != P.ANKAN.end()) return true;
    if(std::find(P.MINKAN.begin(), P.MINKAN.end(), HAK) != P.MINKAN.end()) return true;
    return false;
}

bool GREEN_F(const PLAYER &P){
    if(std::find(P.ANKO.begin(), P.ANKO.end(), HAT) != P.ANKO.end()) return true;
    if(std::find(P.PON.begin(), P.PON.end(), HAT) != P.PON.end()) return true;
    if(std::find(P.ANKAN.begin(), P.ANKAN.end(), HAT) != P.ANKAN.end()) return true;
    if(std::find(P.MINKAN.begin(), P.MINKAN.end(), HAT) != P.MINKAN.end()) return true;
    return false;
}

bool RED_F(const PLAYER &P){
    if(std::find(P.ANKO.begin(), P.ANKO.end(), CHU) != P.ANKO.end()) return true;
    if(std::find(P.PON.begin(), P.PON.end(), CHU) != P.PON.end()) return true;
    if(std::find(P.ANKAN.begin(), P.ANKAN.end(), CHU) != P.ANKAN.end()) return true;
    if(std::find(P.MINKAN.begin(), P.MINKAN.end(), CHU) != P.MINKAN.end()) return true;
    return false;
}

bool TWO_TO_EIGHT_F(const PLAYER &P){
    std::vector<MAHJANG_HI> tehai = P.TEHAI;
    tehai.push_back(P.AGARI);

    for(MAHJANG_HI YAOCHU : {M1, M9, P1, P9, S1,S9, TON, NAM, SHA, PAY, HAK, HAT, CHU}){
        if(std::find(tehai.begin(), tehai.end(), YAOCHU) != tehai.end()) return false;
        if(std::find(P.PON.begin(), P.PON.end(), YAOCHU) != P.PON.end()) return false;
        if(std::find(P.ANKAN.begin(), P.ANKAN.end(), YAOCHU) != P.ANKAN.end()) return false;
        if(std::find(P.MINKAN.begin(), P.MINKAN.end(), YAOCHU) != P.MINKAN.end()) return false;
        if(P.HEAD_PAIR == YAOCHU) return false;
    }
    for(MAHJANG_HI YAOCHU : {M1, M7, P1, P7, S1, S7}){
        if(std::find(P.CHI.begin(), P.CHI.end(), YAOCHU) != P.CHI.end()) return false;
    }
    return true;
}

bool PEACE_F(const PLAYER &P){
    if(P.SHUNTSU.size() != 4) return false;
    if(P.HEAD_PAIR == P.JIFU || P.HEAD_PAIR == BAFU) return false;
    if(P.HEAD_PAIR.TYPE == 4) return false;

    for(MAHJANG_HI shu : P.SHUNTSU){
        if(P.AGARI == shu || P.AGARI == shu + 2){
            if(shu.RANK == 1 && P.AGARI == shu + 2) continue;
            if(shu.RANK == 7 && P.AGARI == shu) continue;
            
            return true;
        };
    }
    return false;    
}

bool ONE_ORDER_F(const PLAYER &P){
    if(!P.MENZEN) return false;
    if(P.SHUNTSU.size() < 2) return false;
    for(MAHJANG_HI shu : P.SHUNTSU){
        if(std::count(P.SHUNTSU.begin(), P.SHUNTSU.end(), shu) >= 2) return true;
    }
    return false;
}

bool UNDERSEA_F(const PLAYER &P){
    return P.AGARI == P.TSUMO && YAMA.empty();
}

bool UNDERRIVER_F(const PLAYER &P){
    return P.AGARI != P.TSUMO && YAMA.empty();
}

bool ONE_SHOT_F(const PLAYER &P){
    if(!P.MENZEN) return false;
    return P.ONE_SHOT_FRAG;
}

//2翻役-----------------------------------------------------------------

bool W_REACH_F(const PLAYER &P){
    return P.W_REACH_FRAG;
}

bool SEVEN_PAIRS_F(const PLAYER &P){
    std::vector<MAHJANG_HI> toitsu;
    std::vector<MAHJANG_HI> tehai = P.TEHAI;
    tehai.push_back(P.AGARI);
    for(MAHJANG_HI HI : tehai){
        if(std::count(tehai.begin(), tehai.end(), HI) == 2){
            if(std::find(toitsu.begin(), toitsu.end(), HI) == toitsu.end()){
                toitsu.push_back(HI);
            }
        }
    }
    return toitsu.size() == 7;
}

bool SMALL_THREE_ORIGIN_F(const PLAYER &P){
    if(WHITE_F(P) + GREEN_F(P)+ RED_F(P) != 2) return false;
    if(P.HEAD_PAIR != HAK && P.HEAD_PAIR != HAT && P.HEAD_PAIR != CHU){
        return false;
    }
    return true;
}

bool THREE_COLOR_SAME_ORDER_F(const PLAYER &P){
    std::vector<MAHJANG_HI> shuntsu = P.SHUNTSU;
    shuntsu.insert(shuntsu.end(), P.CHI.begin(), P.CHI.end());
    if(shuntsu.size() < 3) return false;
    for(MAHJANG_HI shu : shuntsu){
        if(shu.TYPE != 0) continue;;
        MAHJANG_HI pshu(1, shu.RANK, 0);
        MAHJANG_HI sshu(2, shu.RANK, 0);
        if(std::find(shuntsu.begin(), shuntsu.end(), pshu) != shuntsu.end() && std::find(shuntsu.begin(), shuntsu.end(), sshu) != shuntsu.end()){
            return true;
        }
    }
    return false;
}

bool THREE_COLOR_SAME_COLORS_F(const PLAYER &P){
    std::vector<MAHJANG_HI> kotsu = P.ANKO;
    kotsu.insert(kotsu.end(), P.ANKAN.begin(), P.ANKAN.end());
    kotsu.insert(kotsu.end(), P.PON.begin(), P.PON.end());
    kotsu.insert(kotsu.end(), P.MINKAN.begin(), P.MINKAN.end());
    if(kotsu.size() < 3) return false;
    for(MAHJANG_HI anko : kotsu){
        if(anko.TYPE != 0) continue;
        MAHJANG_HI panko(1, anko.RANK, 0);
        MAHJANG_HI sanko(2, anko.RANK, 0);
        if(std::find(kotsu.begin(), kotsu.end(), panko) != kotsu.end() && std::find(kotsu.begin(), kotsu.end(), sanko) != kotsu.end()){
            return true;
        }
    }
    return false;
}

bool THREE_SWORD_F(const PLAYER &P){
    if(P.MINKAN.size() + P.ANKAN.size() ==  3) return true;
    return false;
}

bool TOYTOY_F(const PLAYER &P){
    if(P.ANKO.size() + P.PON.size() + P.ANKAN.size() + P.MINKAN.size() == 4) return true;
    return false;
}

bool THREE_DARK_SAME_F(const PLAYER &P){
    if(P.ANKO.size() + P.ANKAN.size() == 3) return true;
    return false;
}

bool MIXED_F(const PLAYER &P){
    if(P.SHUNTSU.empty() && P.CHI.empty()) return false;
    
    if(P.HEAD_PAIR.TYPE < 3 && (1 != P.HEAD_PAIR.RANK && P.HEAD_PAIR.RANK != 9)) return false;
    for(MAHJANG_HI HI : P.ANKO){
        if(HI.TYPE < 3 && (1 != HI.RANK && HI.RANK != 9)) return false;
    }
    for(MAHJANG_HI HI : P.PON){
        if(HI.TYPE < 3 && (1 != HI.RANK && HI.RANK != 9)) return false; 
    }
    for(MAHJANG_HI HI : P.MINKAN){
        if(HI.TYPE < 3 && (1 != HI.RANK && HI.RANK != 9)) return false; 
    }
    for(MAHJANG_HI HI : P.ANKAN){
        if(HI.TYPE < 3 && (1 != HI.RANK && HI.RANK != 9)) return false; 
    }

    for(MAHJANG_HI HI : P.CHI){
        if(1 != HI.RANK && HI.RANK != 7) return false; 
    }
    for(MAHJANG_HI HI : P.SHUNTSU){
        if(1 != HI.RANK && HI.RANK != 7) return false; 
    }
    return true;
}

bool STRAIGHT_F(const PLAYER &P){
    if(P.SHUNTSU.size() + P.CHI.size() < 3) return false;
    std::vector<MAHJANG_HI> shuntsu = P.SHUNTSU;
    shuntsu.insert(shuntsu.end(), P.CHI.begin(), P.CHI.end());
    for(int i = 0; i < 3; i++){
        auto it123 = std::find(shuntsu.begin(), shuntsu.end(), MAHJANG_HI(i, 1, 0));
        auto it456 = std::find(shuntsu.begin(), shuntsu.end(), MAHJANG_HI(i, 4, 0));
        auto it789 = std::find(shuntsu.begin(), shuntsu.end(), MAHJANG_HI(i, 7, 0));
        if(it123 != shuntsu.end() && it456 != shuntsu.end() && it789 != shuntsu.end()) return true;
    }
    return false;   
}

bool MIXED_OLD_HEAD_F(const PLAYER &P){
    if(!P.SHUNTSU.empty() || !P.CHI.empty()) return false;
    
    for(MAHJANG_HI HI : P.ANKO){
        if(HI.TYPE < 3 && (1 != HI.RANK && HI.RANK != 9)) return false;
    }
    for(MAHJANG_HI HI : P.PON){
        if(HI.TYPE < 3 && (1 != HI.RANK && HI.RANK != 9)) return false; 
    }
    for(MAHJANG_HI HI : P.MINKAN){
        if(HI.TYPE < 3 && (1 != HI.RANK && HI.RANK != 9)) return false; 
    }
    for(MAHJANG_HI HI : P.ANKAN){
        if(HI.TYPE < 3 && (1 != HI.RANK && HI.RANK != 9)) return false; 
    }
    if(P.HEAD_PAIR.TYPE < 3 && (1 != P.HEAD_PAIR.RANK && P.HEAD_PAIR.RANK != 9)) return false;

    return true;
}

//3翻役------------------------------------------------------------------------------------

bool MIXED_ONE_COLOR_F(const PLAYER &P){
    if(PURE_ONE_COLOR_F(P)) return false;
    std::vector<MAHJANG_HI> tehai = P.TEHAI;
    tehai.insert(tehai.end(), P.PON.begin(), P.PON.end());
    tehai.insert(tehai.end(), P.CHI.begin(), P.CHI.end());
    tehai.insert(tehai.end(), P.ANKAN.begin(), P.ANKAN.end());
    tehai.insert(tehai.end(), P.MINKAN.begin(), P.MINKAN.end());
    tehai.push_back(P.AGARI);
    std::sort(tehai.begin(), tehai.end());
    
    int type = tehai[0].TYPE;
    for(MAHJANG_HI HI : tehai){
        if(HI.TYPE < 3 && HI.TYPE != type) return false;
    }
    return true;
}

bool PURE_MIXED_F(const PLAYER &P){
    if(P.SHUNTSU.empty() && P.CHI.size()) return false;

    for(MAHJANG_HI HI : P.SHUNTSU){
        if(HI.RANK != 1 && HI.RANK != 7) return false;
    }
    for(MAHJANG_HI HI : P.CHI){
        if(HI.RANK != 1 && HI.RANK != 7) return false;
    }
    for(MAHJANG_HI HI : P.ANKO){
        if(HI.TYPE >= 3 || HI.RANK != 1 && HI.RANK != 9) return false;
    }
    for(MAHJANG_HI HI : P.PON){
        if(HI.TYPE >= 3 || HI.RANK != 1 && HI.RANK != 9) return false;
    }
    for(MAHJANG_HI HI : P.ANKAN){
        if(HI.TYPE >= 3 || HI.RANK != 1 && HI.RANK != 9) return false;
    }
    for(MAHJANG_HI HI : P.MINKAN){
        if(HI.TYPE >= 3 || HI.RANK != 1 && HI.RANK != 9) return false;
    }
    if(P.HEAD_PAIR.TYPE >= 3 || P.HEAD_PAIR.RANK != 1 && P.HEAD_PAIR.RANK  != 9) return false;
    
    return true;
}

bool TWO_ORDER_F(const PLAYER &P){
    if(!P.MENZEN) return false;
    if(P.SHUNTSU.size() != 4) return false;
    for(MAHJANG_HI shu : P.SHUNTSU){
        if(std::count(P.SHUNTSU.begin(), P.SHUNTSU.end(), shu) != 2) return false;
    }
    return true;
}




