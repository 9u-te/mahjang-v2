#include "new-MJ_H.h"


bool MAHJANG_HI::operator==(const MAHJANG_HI HI) const{//イコール
        return this->TYPE == HI.TYPE && this->RANK == HI.RANK;
}

bool MAHJANG_HI::operator!=(const MAHJANG_HI HI) const{//ノットイコール
        return this->TYPE != HI.TYPE || this->RANK != HI.RANK;
}

bool MAHJANG_HI::operator<(const MAHJANG_HI HI) const{//大小関係
    if(this->TYPE != HI.TYPE) return this->TYPE < HI.TYPE;
    return this->RANK < HI.RANK;
}

MAHJANG_HI MAHJANG_HI::operator+(const int n) const{//足し算
    return MAHJANG_HI(this->TYPE, this->RANK + n, 0);
}

MAHJANG_HI MAHJANG_HI::operator-(const int n) const{//引き算
    return MAHJANG_HI(this->TYPE, this->RANK - n, 0);
}

MAHJANG_HI MAHJANG_HI::get_DRA(){//どら表示からどらを見つける
    if(TYPE < 3){
        if(RANK < 9) return MAHJANG_HI(TYPE, RANK + 1, 0);
        else return MAHJANG_HI(TYPE, 1, 0);
    }
    else if(TYPE == 3){
        if(RANK < 4) return MAHJANG_HI(TYPE, RANK + 1, 0);
        else return MAHJANG_HI(TYPE, 1, 0);
    }
    else{
        if(RANK < 3) return MAHJANG_HI(TYPE, RANK + 1, 0);
        else return MAHJANG_HI(TYPE, 1, 0);
    }
}

