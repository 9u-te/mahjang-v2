#include "new-MJ_P.h"


void PLAYER::repai(){
    std::sort(TEHAI.begin(), TEHAI.end());
}

void PLAYER::reset_mentsu(){
    ANKO.clear();
    SHUNTSU.clear();
}

std::vector<MAHJANG_HI> PLAYER::bunseki0(){
    std::vector<MAHJANG_HI> toitsu;
    std::vector<MAHJANG_HI> tehai = TEHAI;
    tehai.push_back(AGARI);
    for(MAHJANG_HI HI : tehai){
        if(std::count(tehai.begin(), tehai.end(), HI) == 2){
            if(std::find(toitsu.begin(), toitsu.end(), HI) == toitsu.end()){
                toitsu.push_back(HI);
            }
        }
    }
    return toitsu;
}

bool PLAYER::bunseki1(std::vector<MAHJANG_HI> tehai){
    if(tehai.empty()) return true;
    MAHJANG_HI first = tehai[0];
    //暗刻
    if(std::count(tehai.begin(), tehai.end(), first) >= 3){//三つ以上あるとき
        ANKO.push_back(first);//暗刻に入れる
        tehai.erase(std::find(tehai.begin(), tehai.end(), first));//三つ消す
        tehai.erase(std::find(tehai.begin(), tehai.end(), first));
        tehai.erase(std::find(tehai.begin(), tehai.end(), first));

        if(bunseki1(tehai)) return true;
    }
    //順子
    if(std::find(tehai.begin(), tehai.end(), first + 1) != tehai.end() && std::find(tehai.begin(), tehai.end(), first + 2) != tehai.end()){
        SHUNTSU.push_back(first);//暗刻に入れる
        tehai.erase(std::find(tehai.begin(), tehai.end(), first));//三つ消す
        tehai.erase(std::find(tehai.begin(), tehai.end(), first + 1));
        tehai.erase(std::find(tehai.begin(), tehai.end(), first + 2));

        if(bunseki1(tehai)) return true;
    }
    return false;
}

bool PLAYER::bunseki2(){
    std::vector<MAHJANG_HI> atama_list = bunseki0();
    std::vector<MAHJANG_HI> tehai = TEHAI;
    tehai.push_back(AGARI);
    for(MAHJANG_HI atama : atama_list){
        std::vector<MAHJANG_HI> test = tehai;
        reset_mentsu();
        //頭二枚を抜く
        test.erase(std::find(test.begin(), test.end(), atama));
        test.erase(std::find(test.begin(), test.end(), atama));

        if(bunseki1(test)) return true;
    }
    return false;
}