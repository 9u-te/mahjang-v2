#include "cscontroll.h"
#include "new-MJ_P.h"
#include "new-MJ_C.h"

void PLAYER::repai()
{
    std::sort(TEHAI.begin(), TEHAI.end());
}

void PLAYER::reset_mentsu()
{
    ANKO.clear();
    SHUNTSU.clear();
}

std::vector<MAHJANG_HI> PLAYER::atamaKouho(std::vector<MAHJANG_HI> tehai, MAHJANG_HI another_hi)
{
    std::vector<MAHJANG_HI> toitsu;
    tehai.push_back(another_hi);
    for (MAHJANG_HI HI : tehai)
    {
        if (std::count(tehai.begin(), tehai.end(), HI) >= 2)
        {
            if (std::find(toitsu.begin(), toitsu.end(), HI) == toitsu.end())
            {
                toitsu.push_back(HI);
            }
        }
    }
    return toitsu;
}

bool PLAYER::sepAnkoShunts(std::vector<MAHJANG_HI> tehai)
{
    if (tehai.empty())
        return true;
    MAHJANG_HI first = tehai[0];
    // 暗刻
    if (std::count(tehai.begin(), tehai.end(), first) >= 3) // 三つ以上あるとき
    {
        std::vector<MAHJANG_HI> next_tehai = tehai;
        next_tehai.erase(std::find(next_tehai.begin(), next_tehai.end(), first)); // 三つ消す
        next_tehai.erase(std::find(next_tehai.begin(), next_tehai.end(), first));
        next_tehai.erase(std::find(next_tehai.begin(), next_tehai.end(), first));

        if (sepAnkoShunts(next_tehai))
        {
            ANKO.push_back(first); // 暗刻に入れる
            return true;
        }
    }
    // 順子
    if (std::find(tehai.begin(), tehai.end(), first + 1) != tehai.end() && std::find(tehai.begin(), tehai.end(), first + 2) != tehai.end())
    {

        std::vector<MAHJANG_HI> next_tehai = tehai;
        next_tehai.erase(std::find(next_tehai.begin(), next_tehai.end(), first)); // 三つ消す
        next_tehai.erase(std::find(next_tehai.begin(), next_tehai.end(), first + 1));
        next_tehai.erase(std::find(next_tehai.begin(), next_tehai.end(), first + 2));

        if (sepAnkoShunts(next_tehai))
        {
            SHUNTSU.push_back(first);
            return true;
        }
    }
    return false;
}

bool PLAYER::bunseki1(std::vector<MAHJANG_HI> tehai, MAHJANG_HI another_hi)
{
    std::vector<MAHJANG_HI> atama_list = atamaKouho(tehai, another_hi);
    tehai.push_back(another_hi);
    std::sort(tehai.begin(), tehai.end());
    for (MAHJANG_HI atama : atama_list)
    {
        std::vector<MAHJANG_HI> test = tehai;
        reset_mentsu();
        // 頭二枚を抜く
        test.erase(std::find(test.begin(), test.end(), atama));
        test.erase(std::find(test.begin(), test.end(), atama));

        if (sepAnkoShunts(test))
            return true;
    }
    return false;
}

std::vector<MAHJANG_HI> PLAYER::TemPai0(const std::vector<MAHJANG_HI> &tehai)
{
    std::vector<MAHJANG_HI> nanimachi{};
    for (MAHJANG_HI HI : ALL_HI)
    {
        if (bunseki1(tehai, HI))
        {
            if (std::find(nanimachi.begin(), nanimachi.end(), HI) == nanimachi.end())
                nanimachi.push_back(HI);
        }
    }
    return nanimachi;
}

std::vector<std::vector<MAHJANG_HI>> PLAYER::TemPai1(MAHJANG_HI another_hi)
{
    int tehai_size = TEHAI.size();
    std::vector<std::vector<MAHJANG_HI>> result(tehai_size);

    for (int i = 0; i < tehai_size; i++)
    {
        std::vector<MAHJANG_HI> tehai = TEHAI;
        tehai[i] = another_hi;
        result[i] = TemPai0(tehai);
    }
    return result;
}

void PLAYER::reachF()
{
    if (W_REACH_FRAG)
        W_REACH_STICK = true;
    else
        REACH_STICK = true;

    SCORE -= 1000;
}

bool PLAYER::ponF(MAHJANG_HI HI)
{
    if (std::count(TEHAI.begin(), TEHAI.end(), HI) > 2)
    {
        std::cout << "pon(y/n)" << std::endl;
        char ans;
        std::cin >> ans;
        if (ans == 'y')
        {
            PON.push_back(HI);
            TEHAI.erase(std::find(TEHAI.begin(), TEHAI.end(), HI));
            TEHAI.erase(std::find(TEHAI.begin(), TEHAI.end(), HI));
            return true;
        }
    }
    return false;
}

bool PLAYER::chiF(MAHJANG_HI HI)
{
    bool hi_m2 = std::find(TEHAI.begin(), TEHAI.end(), HI - 2) != TEHAI.end();
    bool hi_m1 = std::find(TEHAI.begin(), TEHAI.end(), HI - 1) != TEHAI.end();
    bool hi_p1 = std::find(TEHAI.begin(), TEHAI.end(), HI + 1) != TEHAI.end();
    bool hi_p2 = std::find(TEHAI.begin(), TEHAI.end(), HI + 2) != TEHAI.end();

    if (hi_m2 && hi_m1 + hi_m1 && hi_p1 + hi_p1 && hi_p2 == 0)
    {
        return false;
    };
    std::cout << "chi(y/n)" << std::endl;
    char ans;
    std::cin >> ans;
    if (ans != 'y')
    {
        return false;
    }

    if (hi_m2 && hi_m1)
    {
        std::cout << CsControll::display({HI - 2, HI - 1, HI}) << " ";
    }
    if (hi_m1 && hi_p1)
    {
        std::cout << CsControll::display({HI - 1, HI, HI + 1}) << " ";
    }
    if (hi_p1 && hi_p2)
    {
        std::cout << CsControll::display({HI, HI + 1, HI + 2}) << "\n";
    }

    int n = (hi_m2 && hi_m1) + (hi_m1 && hi_p1) + (hi_p1 && hi_p2);

    if (n == 1)
    {
        if (hi_m2 && hi_m1)
        {
            CHI.push_back(HI - 2);
            return true;
        }
        if (hi_m1 && hi_p1)
        {
            CHI.push_back(HI - 1);
            return true;
        }
        if (hi_p1 && hi_p2)
        {
            CHI.push_back(HI);
            return true;
        }
    }
    else if (n > 1)
    {
        if (hi_m2 && hi_m1)
        {
            std::cout << 4 - n << " : " << CsControll::display({HI - 2, HI - 1, HI});
            n--;
        }
        if (hi_m1 && hi_p1)
        {
            std::cout << 4 - n << " : " << CsControll::display({HI - 1, HI, HI + 1});
            n--;
        }
        if (hi_p1 && hi_p2)
        {
            std::cout << 4 - n << " : " << CsControll::display({HI, HI + 1, HI + 2});
            n--;
        }
        std::cout << "\n"
                  << "choose num\n";
        int ans;
        std::cin >> ans;
    }
}

bool PLAYER::minkanF(MAHJANG_HI HI)
{
    if (std::count(TEHAI.begin(), TEHAI.end(), HI) < 3)
    {
        return false;
    }
    std::cout << "kan(y/n)" << std::endl;
    char ans;
    std::cin >> ans;
    if (ans == 'y')
    {
        MINKAN.push_back(HI);
        TEHAI.erase(std::find(TEHAI.begin(), TEHAI.end(), HI));
        TEHAI.erase(std::find(TEHAI.begin(), TEHAI.end(), HI));
        TEHAI.erase(std::find(TEHAI.begin(), TEHAI.end(), HI));

        return true;
    }
    return false;
}

bool PLAYER::kakanF()
{
    if (std::find(PON.begin(), PON.end(), TSUMO) == PON.end())
    {
        return false;
    }
    std::cout << "kan(y/n)" << std::endl;
    char ans;
    std::cin >> ans;
    if (ans == 'y')
    {
        MINKAN.push_back(TSUMO);
        PON.erase(std::find(PON.begin(), PON.end(), TSUMO));
        return true;
    }
    return false;
}

bool PLAYER::ankanF()
{
    std::vector<MAHJANG_HI> tehai = TEHAI;
    tehai.push_back(TSUMO);
    for (MAHJANG_HI HI : tehai)
    {
        if (std::count(tehai.begin(), tehai.end(), HI) != 4)
        {
            continue;
        }
        std::cout << "kan(y/n)" << std::endl;
        char ans;
        std::cin >> ans;
        if (ans == 'y')
        {
            ANKAN.push_back(TSUMO);
            TEHAI.erase(std::find(TEHAI.begin(), TEHAI.end(), HI));
            TEHAI.erase(std::find(TEHAI.begin(), TEHAI.end(), HI));
            TEHAI.erase(std::find(TEHAI.begin(), TEHAI.end(), HI));
            TEHAI.erase(std::find(TEHAI.begin(), TEHAI.end(), HI));
            return true;
        }
    }
    return false;
}

MAHJANG_HI PLAYER::discard(int n)
{
    if (REACH_STICK)
    {
        return TSUMO;
    }

    if (n >= TEHAI.size())
    {
        return TSUMO;
    }
    else
    {
        MAHJANG_HI HI = TEHAI[n];
        TEHAI[n] = TSUMO;

        return HI;
    }
}

/*
bool PLAYER::ronF(MAHJANG_HI HI)
{
    
}
*/

bool PLAYER::tsumoF()
{
    if(!bunseki1(TEHAI, TSUMO)) return false;

    std::vector<YAKU> yaku_list = Calc::YAKU_CAL(*this);
    if(yaku_list.empty()) return false;

    std::cout << "tsumo(y/n)\n";
    char ans;
    std::cin >> ans;
    if (ans == 'y')
    {
        return true;
    }

    return false;
}