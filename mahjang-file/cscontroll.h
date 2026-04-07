#pragma once
#include "new-MJ_H.h"
#include <string>

namespace CsControll
{   
    inline const std::vector<std::string> manzEmoji = {"🀇", "🀈", "🀉", "🀊", "🀋", "🀌", "🀍", "🀎", "🀏"};

    inline const std::vector<std::string> pinzEmoji = {"🀙", "🀚", "🀛", "🀜", "🀝", "🀞", "🀟", "🀠", "🀡"};

    inline const std::vector<std::string> souzEmoji = {"🀐", "🀑", "🀒", "🀓", "🀔", "🀕", "🀖", "🀗", "🀘"};

    inline const std::vector<std::string> kazeEmoji = {"🀀", "🀁", "🀂", "🀃"};

    inline const std::vector<std::string> sangenEmoji = {"🀆", "🀅", "🀄︎"};
    
    inline const std::string ura = "🀫";

    std::string display(const MAHJANG_HI HI);

    std::string display(const std::vector<MAHJANG_HI> HIVector);
}

//🀇, 🀈, 🀉, 🀊, 🀋, 🀌, 🀍, 🀎, 🀏
//"🀙", "🀚", "🀛", "🀜", "🀝", "🀞", "🀟", "🀠", "🀡"
//"🀐", "🀑","🀒","🀓","🀔","🀕","🀖","🀗","🀘"
//🀀, 🀁, 🀂, 🀃
//🀆, 🀅, 🀄︎