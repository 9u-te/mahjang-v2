#include "new-MJ_G.h"

Game::Game() : BAFU(TON), YAMA(), WANGPAI(), DraHyouji(), uraDraHyouji()
{
    for (int i = 0; i < 4; i++)
    {
        players.emplace_back(i);

        KAWAs.emplace_back();
    }
}

int Game::dicision_oya()
{
    std::uniform_int_distribution<> dist(0, 3); // 0~3
    int oya_num = dist(g);

    std::cout << "Oya is player" << oya_num << std::endl;

    for (int i = 0; i < 4; i++)
    {
        players[(oya_num + i) % 4].JIFU = MAHJANG_HI(TileType::Kaze, i, false);
    }
    return oya_num;
}

void Game::initilize_kyoku(MAHJANG_HI bafu, int kyoku, int honba)
{ // カンカウントのリセット
    KanCount = 0;
    YAMA.clear();
    WANGPAI.clear();
    DraHyouji.clear();
    uraDraHyouji.clear();


    // 河のリセット

    for (std::vector<MAHJANG_HI> &kawa : KAWAs)
    {
        kawa.clear();
    }

    // ダブル立直と天和地和フラグのリセット
    for (PLAYER &player : players)
    {
        player.TEHAI.clear();
        player.PON.clear();
        player.CHI.clear();
        player.MINKAN.clear();
        player.ANKAN.clear();
        player.reset_mentsu();

        player.W_REACH_FRAG = true;
    }

    // 山を作る
    for (int type = 0; type < 5; type++)
    {
        if (type < 3) // 数字牌
        {
            for (int rank = 1; rank <= 9; rank++)
            {
                YAMA.emplace_back(type, rank, false);
                YAMA.emplace_back(type, rank, false);
                YAMA.emplace_back(type, rank, false);
                YAMA.emplace_back(type, rank, false);
            }
        }
        else if (type == 3) // 風牌
        {
            for (int rank = 1; rank <= 4; rank++)
            {
                YAMA.emplace_back(type, rank, false);
                YAMA.emplace_back(type, rank, false);
                YAMA.emplace_back(type, rank, false);
                YAMA.emplace_back(type, rank, false);
            }
        }
        else // 三元牌
        {
            for (int rank = 1; rank <= 3; rank++)
            {
                YAMA.emplace_back(type, rank, false);
                YAMA.emplace_back(type, rank, false);
                YAMA.emplace_back(type, rank, false);
                YAMA.emplace_back(type, rank, false);
            }
        }
    }

    // 赤の追加
    *std::find(YAMA.begin(), YAMA.end(), M5) = M5_RED;
    *std::find(YAMA.begin(), YAMA.end(), P5) = P5_RED;
    *std::find(YAMA.begin(), YAMA.end(), S5) = S5_RED;

    // 洗牌
    std::shuffle(YAMA.begin(), YAMA.end(), rd);

    // 王牌の作成
    WANGPAI.insert(WANGPAI.begin(), YAMA.end() - 14, YAMA.end());
    YAMA.erase(YAMA.end() - 14, YAMA.end());

    // どら表示牌
    DraHyouji = {WANGPAI[9], HiUra, HiUra, HiUra};



    // 配牌
    for (int i = 0; i < 3; i++)
    {
        for (int player_id = 0; player_id < 4; player_id++)
        {
            std::vector<MAHJANG_HI> &whose_tehai = players[(oya_id + player_id) % 4].TEHAI;

            // 4枚とる
            whose_tehai.insert(whose_tehai.end(), YAMA.end() - 4, YAMA.end());
            // 山から4枚消す
            YAMA.erase(YAMA.end() - 4, YAMA.end());
        }
    }
    // ちょんちょん
    for (int player_id = 0; player_id < 4; player_id++)
    {
        std::vector<MAHJANG_HI> &whose_tehai = players[(oya_id + player_id) % 4].TEHAI;

        // 1枚とる
        whose_tehai.push_back(YAMA.back());
        // 山から1枚消す
        YAMA.pop_back();
    }

    for (PLAYER &player : players)
    {
        player.repai();
    }
}

void Game::TsumoAction(PLAYER &player)
{
    player.TSUMO = YAMA.back();
    YAMA.pop_back();
}

void Game::discard(MAHJANG_HI HI, int suteru_current_player_num)
{
    KAWAs[suteru_current_player_num].push_back(players[suteru_current_player_num].TSUMO);
}

void Game::reachF()
{
    kyotaku += 1000;
}

int Game::ponF(MAHJANG_HI HI, int pon_current_player_num)
{
    KAWAs[current_player_num].pop_back();
    return (pon_current_player_num + 1)%4;

}

void Game::chiF(MAHJANG_HI HI, int chi_current_player_num)
{
    KAWAs[current_player_num].pop_back();
}

int Game::minkanF(MAHJANG_HI HI, int kan_current_player_num)
{
    KAWAs[current_player_num].pop_back();
    return (kan_current_player_num + 1)%4;
}

void Game::doramekuri()
{
    auto it = std::find(DraHyouji.begin(), DraHyouji.end(), HiUra);

    *it = YAMA[9 - 2*(it - DraHyouji.begin())];
}

void Game::ryukyoku()
{
    std::vector<MAHJANG_HI>  oya_tempai = players[oya_id].TemPai0(players[oya_id].TEHAI);
    if(oya_tempai.size())
    {
        honba++;
    }
    else
    {
        honba = 0;
        oya_id = (oya_id + 1)%4;
    }
}

void Game::ron_tensu(int winner)
{
    PLAYER &hoju = players[current_player_num];
    PLAYER &agari = players[winner];

}



void Game::yaku_hantei(PLAYER &P)
{
    P.yaku_list.clear();
    using namespace Yaku_F;
    // 1翻役---------------------------------------------------------------------------
    if(REACH_F(P)) P.yaku_list.push_back(Yaku_n::REACH);
    if(TWO_TO_EIGHT_F(P)) P.yaku_list.push_back(Yaku_n::TWO_TO_EIGHT);
    if(MENZEN_TSUMO_F(P)) P.yaku_list.push_back(Yaku_n::MENZEN_TSUMO);
    if(MY_WIND_F(P)) P.yaku_list.push_back(Yaku_n::MY_WIND);
    if(GRAND_WIND_F(P)) P.yaku_list.push_back(Yaku_n::GRAND_WIND);
    if(WHITE_F(P)) P.yaku_list.push_back(Yaku_n::WHITE);
    if(GREEN_F(P)) P.yaku_list.push_back(Yaku_n::GREEN);
    if(RED_F(P)) P.yaku_list.push_back(Yaku_n::RED);
    if(PEACE_F(P)) P.yaku_list.push_back(Yaku_n::PEACE);
    if(ONE_ORDER_F(P)) P.yaku_list.push_back(Yaku_n::ONE_ORDER);
    if(UNDERSEA_F(P)) P.yaku_list.push_back(Yaku_n::UNDERSEA);
    if(UNDERRIVER_F(P)) P.yaku_list.push_back(Yaku_n::UNDERRIVER);
    if(ONE_SHOT_F(P)) P.yaku_list.push_back(Yaku_n::ONE_SHOT);
    // 2翻役---------------------------------------------------------------------------
    if(W_REACH_F(P)) P.yaku_list.push_back(Yaku_n::W_REACH);
    if(SEVEN_PAIRS_F(P)) P.yaku_list.push_back(Yaku_n::SEVEN_PAIRS);
    if(SMALL_THREE_ORIGIN_F(P)) P.yaku_list.push_back(Yaku_n::SMALL_THREE_ORIGIN);
    if(THREE_COLOR_SAME_ORDER_F(P)) P.yaku_list.push_back(Yaku_n::THREE_COLOR_SAME_ORDER);
    if(THREE_COLOR_SAME_COLORS_F(P)) P.yaku_list.push_back(Yaku_n::THREE_COLOR_SAME_COLORS);
    if(THREE_SWORD_F(P)) P.yaku_list.push_back(Yaku_n::THREE_SWORD);
    if(TOYTOY_F(P)) P.yaku_list.push_back(Yaku_n::TOYTOY);
    if(THREE_DARK_SAME_F(P)) P.yaku_list.push_back(Yaku_n::THREE_DARK_SAME);
    if(MIXED_F(P)) P.yaku_list.push_back(Yaku_n::MIXED);
    if(STRAIGHT_F(P)) P.yaku_list.push_back(Yaku_n::STRAIGHT);
    if(MIXED_OLD_HEAD_F(P)) P.yaku_list.push_back(Yaku_n::MIXED_OLD_HEAD);
    // 3翻役---------------------------------------------------------------------------
    if(MIXED_ONE_COLOR_F(P)) P.yaku_list.push_back(Yaku_n::MIXED_ONE_COLOR);
    if(PURE_MIXED_F(P)) P.yaku_list.push_back(Yaku_n::PURE_MIXED);
    if(TWO_ORDER_F(P)) P.yaku_list.push_back(Yaku_n::TWO_ORDER);
    // 6翻役---------------------------------------------------------------------------
    if(PURE_ONE_COLOR_F(P)) P.yaku_list.push_back(Yaku_n::PURE_ONE_COLOR);
    // 役満---------------------------------------------------------------------------
    if(BIG_THREE_ORIGIN_F(P)) P.yaku_list.push_back(Yaku_n::BIG_THREE_ORIGIN);
    if(FOUR_DARK_SAME_F(P)) P.yaku_list.push_back(Yaku_n::FOUR_DARK_SAME);
    if(CHAR_ONE_COLOR_F(P)) P.yaku_list.push_back(Yaku_n::CHAR_ONE_COLOR);
    if(GREEN_ONE_COLOR_F(P)) P.yaku_list.push_back(Yaku_n::GREEN_ONE_COLOR);
    if(PURE_OLD_HEAD_F(P)) P.yaku_list.push_back(Yaku_n::PURE_OLD_HEAD);
    if(SMALL_FOUR_PLEASURE_F(P)) P.yaku_list.push_back(Yaku_n::SMALL_FOUR_PLEASURE);
    if(THIRTEEN_ORPHANS_F(P)) P.yaku_list.push_back(Yaku_n::THIRTEEN_ORPHANS);
    if(FOUR_SWORD_F(P)) P.yaku_list.push_back(Yaku_n::FOUR_SWORD);
    if(NINE_GATES_F(P)) P.yaku_list.push_back(Yaku_n::NINE_GATES);
    if(TENHO_F(P)) P.yaku_list.push_back(Yaku_n::TENHO);
    if(CHIHO_F(P)) P.yaku_list.push_back(Yaku_n::CHIHO);
    // ダブル役満---------------------------------------------------------------------------
    if(BIG_FOUR_PLEASURE_F(P)) P.yaku_list.push_back(Yaku_n::BIG_FOUR_PLEASURE);
    if(FOUR_DARK_SAME_SINGLE_F(P)) P.yaku_list.push_back(Yaku_n::FOUR_DARK_SAME_SINGLE);
    if(PURE_NINE_GATES_F(P)) P.yaku_list.push_back(Yaku_n::PURE_NINE_GATES);
    if(THIRTEEN_ORPHANS_SUPER_F(P)) P.yaku_list.push_back(Yaku_n::THIRTEEN_ORPHANS_SUPER);
}



void Game::play_kyoku()
{
    current_player_num = oya_id;

    while (!YAMA.empty())
    {
        PLAYER &current_player = players[current_player_num];

        TsumoAction(current_player);

        if(current_player.bunseki1(current_player.TEHAI, current_player.TSUMO))
        {//つも上がり
            yaku_hantei(current_player);

            if(!current_player.yaku_list.empty()){
                current_player.tsumoF();
            }
        }

        



    }
}