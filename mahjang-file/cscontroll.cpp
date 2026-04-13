#include "cscontroll.h"

std::string CsControll::display(const MAHJANG_HI HI)
{
    if(HI.TYPE == TileType::Manzu) return CsControll::manzEmoji[HI.RANK - 1];
    if(HI.TYPE == TileType::Pinzu) return CsControll::pinzEmoji[HI.RANK - 1];
    if(HI.TYPE == TileType::Souzu) return CsControll::souzEmoji[HI.RANK - 1];
    if(HI.TYPE == TileType::Kaze) return CsControll::kazeEmoji[HI.RANK - 1];
    if(HI.TYPE == TileType::Sangen) return CsControll::sangenEmoji[HI.RANK - 1];
    return CsControll::ura;
}

std::string CsControll::display(const std::vector<MAHJANG_HI> HIVector){
    std::string result;
    for(MAHJANG_HI HI : HIVector){

        result += CsControll::display(HI);
    }
    return result;
}

int CsControll::index(){//入力
    std::string hi;
    int t;
    int r;
    int d;
    while (true)
    {
        std::cin >> hi;

        if(hi[0] == 'M') t = TileType::Manzu;
        if(hi[0] == 'P') t = TileType::Pinzu;
        if(hi[0] == 'S') t = TileType::Souzu;
        

        

    }
}