#pragma once
#include "new-MJ_Y.h"

class YAKU;
class PLAYER;

namespace Calc{

    int FU_CAL(const PLAYER &P);//符計算

    std::vector<YAKU> YAKU_CAL(const PLAYER &P);//役の数

    int HAN_CAL(const PLAYER &P);//翻数

    int YAKUMAN_CAL(const PLAYER &P);//役満

    int STANDARD_POINTS(const PLAYER &P);//基礎点
}