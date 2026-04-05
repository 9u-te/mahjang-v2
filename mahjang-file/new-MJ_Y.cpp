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
    for(MAHJANG_HI YAOCHU : {M1, M9, P1, P9, S1,S9, TON, NAM, SHA, PAY, HAK, HAT, CHU}){
        if(std::find(P.TEHAI.begin(), P.TEHAI.end(), YAOCHU) != P.TEHAI.end()) return false;
        if(std::find(P.PON.begin(), P.PON.end(), YAOCHU) != P.PON.end()) return false;
        if(std::find(P.CHI.begin(), P.CHI.end(), YAOCHU) != P.CHI.end()) return false;
        if(std::find(P.ANKAN.begin(), P.ANKAN.end(), YAOCHU) != P.ANKAN.end()) return false;
        if(std::find(P.MINKAN.begin(), P.MINKAN.end(), YAOCHU) != P.MINKAN.end()) return false;
    }
    return true;
}

bool PEACE_F(const PLAYER &P){
    if(P.SHUNTSU.size() != 4) return false;
    if(P.HEAD_PAIR == P.JIFU || P.HEAD_PAIR == BAFU) return false;
    for(MAHJANG_HI shu : P.SHUNTSU){
        if(P.AGARI == shu || P.AGARI == shu + 2) return true;
    }
    return false;    
}

bool ONE_ORDER_F(const PLAYER &P){
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

bool ONE_CHOT_F(const PLAYER &P){
    return P.ONE_SHOT_FRAG;
}

//2翻役-----------------------------------------------------------------

bool W_REACH(const PLAYER &P){
    return P.W_REACH_FRAG;
}



std::vector<YAKU> YAKU_CHECK(PLAYER P){
    
}

