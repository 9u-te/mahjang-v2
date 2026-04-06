#include "new-MJ_Y.h"

namespace Yaku{
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
        return P.W_REACH_STICK;
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
        if(P.SHUNTSU.empty() && P.CHI.empty()) return false;
    
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
            int c = std::count(P.SHUNTSU.begin(), P.SHUNTSU.end(), shu);
            if( c != 2 && c != 4) return false;
        }
        return true;
    }
    
    //6翻役-------------------------------------------------------
    
    bool PURE_ONE_COLOR_F(const PLAYER &P){
        std::vector<MAHJANG_HI> tehai = P.TEHAI;
        tehai.insert(tehai.end(), P.PON.begin(), P.PON.end());
        tehai.insert(tehai.end(), P.CHI.begin(), P.CHI.end());
        tehai.insert(tehai.end(), P.ANKAN.begin(), P.ANKAN.end());
        tehai.insert(tehai.end(), P.MINKAN.begin(), P.MINKAN.end());
        tehai.push_back(P.AGARI);
        std::sort(tehai.begin(), tehai.end());
    
        int type = tehai[0].TYPE;
        for(MAHJANG_HI HI : tehai){
            if(HI.TYPE < 3 && HI.TYPE != type || HI.TYPE >= 3) return false;
        }
        return true;
    }
    
    //役満---------------------------------------------------------
    
    bool BIG_THREE_ORIGIN_F(const PLAYER &P){
        if(WHITE_F(P) + GREEN_F(P)+ RED_F(P) == 3) return true;
        return false;
    }
    
    bool FOUR_DARK_SAME_F(const PLAYER &P){
        if(!P.MENZEN) return false;
        if(P.ANKAN.size() + P.ANKO.size() == 4) return true;
        return false;
    }
    
    bool CHAR_ONE_COLOR_F(const PLAYER &P){
        std::vector<MAHJANG_HI> mentsu = P.ANKO;
        mentsu.insert(mentsu.begin(), P.PON.begin(), P.PON.end());
        mentsu.insert(mentsu.begin(), P.ANKAN.begin(), P.ANKAN.end());
        mentsu.insert(mentsu.begin(), P.MINKAN.begin(), P.MINKAN.end());
        mentsu.push_back(P.HEAD_PAIR);
    
        for(MAHJANG_HI HI : mentsu){
            if(HI.TYPE < 3) return false;
        }
        return true;
    }
    
    bool GREEN_ONE_COLOR_F(const PLAYER &P){
        std::vector<MAHJANG_HI> green = {S2, S3, S4, S6, S8, HAT};
        std::vector<MAHJANG_HI> tehai = P.TEHAI;
        tehai.insert(tehai.end(), P.PON.begin(), P.PON.end());
        tehai.insert(tehai.end(), P.CHI.begin(), P.CHI.end());
        tehai.insert(tehai.end(), P.ANKAN.begin(), P.ANKAN.end());
        tehai.insert(tehai.end(), P.MINKAN.begin(), P.MINKAN.end());
        tehai.insert(tehai.end(), P.SHUNTSU.begin(), P.SHUNTSU.end());
        tehai.push_back(P.AGARI);
        for(MAHJANG_HI HI : tehai){
            if(std::find(green.begin(), green.end(), HI) == green.end()) return false;
        }
        return true;
    }
    
    bool PURE_OLD_HEAD_F(const PLAYER &P){
        std::vector<MAHJANG_HI> tehai = P.TEHAI;
        tehai.insert(tehai.end(), P.PON.begin(), P.PON.end());
        tehai.insert(tehai.end(), P.CHI.begin(), P.CHI.end());
        tehai.insert(tehai.end(), P.ANKAN.begin(), P.ANKAN.end());
        tehai.insert(tehai.end(), P.MINKAN.begin(), P.MINKAN.end());
        tehai.push_back(P.AGARI);
        for(MAHJANG_HI HI : tehai){
            if(HI.TYPE >= 3) return false;
            if(HI.RANK != 1 && HI.RANK != 9) return false;
        }
        return true;
    }
    
    bool SMALL_FOUR_PLEASURE_F(const PLAYER &P){
        std::vector<MAHJANG_HI> mentsu = P.ANKO;
        mentsu.insert(mentsu.begin(), P.PON.begin(), P.PON.end());
        mentsu.insert(mentsu.begin(), P.ANKAN.begin(), P.ANKAN.end());
        mentsu.insert(mentsu.begin(), P.MINKAN.begin(), P.MINKAN.end());
        int kaze_count = 0;
        for(MAHJANG_HI KAZE : {TON, NAM, SHA, PAY}){
            if(std::find(mentsu.begin(), mentsu.end(), KAZE) != mentsu.end()) kaze_count++;
        }
        if(kaze_count != 3) return false;
        if(P.HEAD_PAIR.TYPE != 3) return false;
        return true;
    }
    
    bool THIRTEEN_ORPHANS_F(const PLAYER &P){
        if(!P.MENZEN) return false;
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
        if(toitsu.size() != 1) return false;
        tehai.erase(std::find(tehai.begin(), tehai.end(), toitsu[0]));
    
        if(std::count(tehai.begin(), tehai.end(), M1) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), M9) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), P1) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), P9) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), S1) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), S9) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), TON) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), NAM) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), SHA) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), PAY) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), HAK) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), HAT) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), CHU) != 1) return false;
        return true;
    }
    
    bool FOUR_SWORD_F(const PLAYER &P){
        if(P.ANKAN.size() + P.MINKAN.size() == 4) return true;
        return false;
    }
    
    bool NINE_GATES_F(const PLAYER &P){
        if(!P.MENZEN) return false;
        if(!PURE_ONE_COLOR_F(P)) return false;
        if(PURE_NINE_GATES_F(P)) return false;
        std::vector<MAHJANG_HI> tehai = P.TEHAI;
        tehai.push_back(P.AGARI);
        int type = tehai[0].TYPE;
        if(std::count(tehai.begin(), tehai.end(), MAHJANG_HI(type, 1, 0)) < 3) return false;
        if(std::count(tehai.begin(), tehai.end(), MAHJANG_HI(type, 2, 0)) < 1) return false;
        if(std::count(tehai.begin(), tehai.end(), MAHJANG_HI(type, 3, 0)) < 1) return false;
        if(std::count(tehai.begin(), tehai.end(), MAHJANG_HI(type, 4, 0)) < 1) return false;
        if(std::count(tehai.begin(), tehai.end(), MAHJANG_HI(type, 5, 0)) < 1) return false;
        if(std::count(tehai.begin(), tehai.end(), MAHJANG_HI(type, 6, 0)) < 1) return false;
        if(std::count(tehai.begin(), tehai.end(), MAHJANG_HI(type, 7, 0)) < 1) return false;
        if(std::count(tehai.begin(), tehai.end(), MAHJANG_HI(type, 8, 0)) < 1) return false;
        if(std::count(tehai.begin(), tehai.end(), MAHJANG_HI(type, 9, 0)) < 3) return false;
        
        return true;
    }
    
    bool TENHO_F(const PLAYER &P){
        return P.W_REACH_FRAG && P.JIFU == TON;
    }
    
    bool CHIHO_F(const PLAYER &P){
        return P.W_REACH_FRAG && P.JIFU != TON;
    }
    
    //ダブル役満-----------------------------------------------------
    
    bool BIG_FOUR_PLEASURE_F(const PLAYER &P){
        std::vector<MAHJANG_HI> mentsu = P.ANKO;
        mentsu.insert(mentsu.begin(), P.PON.begin(), P.PON.end());
        mentsu.insert(mentsu.begin(), P.ANKAN.begin(), P.ANKAN.end());
        mentsu.insert(mentsu.begin(), P.MINKAN.begin(), P.MINKAN.end());
        int kaze_count = 0;
        for(MAHJANG_HI KAZE : {TON, NAM, SHA, PAY}){
            if(std::find(mentsu.begin(), mentsu.end(), KAZE) == mentsu.end()) return false;
        }
        return true;
    }
    
    bool FOUR_DARK_SAME_SINGLE_F(const PLAYER &P){
        std::vector<MAHJANG_HI> mentsu = P.ANKO;
        mentsu.insert(mentsu.begin(), P.ANKAN.begin(), P.ANKAN.end());
        mentsu.insert(mentsu.begin(), P.MINKAN.begin(), P.MINKAN.end());
        if(mentsu.size() != 4) return false;
        if(P.HEAD_PAIR != P.AGARI) return false;
        return false;
    }
    
    
    bool PURE_NINE_GATES_F(const PLAYER &P){
        if(!P.MENZEN) return false;
        if(!PURE_ONE_COLOR_F(P)) return false;
        std::vector<MAHJANG_HI> tehai = P.TEHAI;
        int type = tehai[0].TYPE;
        if(std::count(tehai.begin(), tehai.end(), MAHJANG_HI(type, 1, 0)) != 3) return false;
        if(std::count(tehai.begin(), tehai.end(), MAHJANG_HI(type, 2, 0)) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), MAHJANG_HI(type, 3, 0)) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), MAHJANG_HI(type, 4, 0)) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), MAHJANG_HI(type, 5, 0)) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), MAHJANG_HI(type, 6, 0)) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), MAHJANG_HI(type, 7, 0)) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), MAHJANG_HI(type, 8, 0)) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), MAHJANG_HI(type, 9, 0)) != 3) return false;
        if(P.AGARI.TYPE != type) return false;
        
        return true;
    }
    
    bool THIRTEEN_ORPHANS_SUPER_F(const PLAYER &P){
        if(!P.MENZEN) return false;
        std::vector<MAHJANG_HI> toitsu;
        std::vector<MAHJANG_HI> tehai = P.TEHAI;
        
        if(std::count(tehai.begin(), tehai.end(), M1) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), M9) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), P1) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), P9) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), S1) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), S9) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), TON) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), NAM) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), SHA) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), PAY) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), HAK) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), HAT) != 1) return false;
        if(std::count(tehai.begin(), tehai.end(), CHU) != 1) return false;
        if(P.AGARI.TYPE < 3 && P.AGARI.RANK != 1 && P.AGARI.RANK != 9) return false;
        return true;
    }
}
