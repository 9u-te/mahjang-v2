#include "new-MJ_G.h"
#include "cscontroll.h"
#include "new-MJ_P.h"

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

    int stp = Calc::STANDARD_POINTS(agari);
    if(agari.ID == oya_id)
    {
        agari.SCORE += 6*stp + 300*honba + kyotaku;
        hoju.SCORE += 6*stp + 300*honba;
    }
    else
    {
        agari.SCORE += 4*stp + 300*honba + kyotaku;
        hoju.SCORE += 4*stp + 300*honba;
    }
    
    kyotaku = 0;

}

void Game::tsumo_tensu()
{
    PLAYER &agari = players[current_player_num];
    int stp = Calc::STANDARD_POINTS(agari);

    if(agari.ID == oya_id)//親の自摸
    {
        agari.SCORE += 6*stp + 300*honba + kyotaku;
        for(PLAYER &p : players)
        {
            if(p.ID == current_player_num) continue;

            p.SCORE -= 2*stp + 100*honba;
        }
    }
    else//子の自摸
    {
        agari.SCORE += 4*stp + 300*honba + kyotaku;
        for(PLAYER &p : players)
        {
            if(p.ID == current_player_num) continue;

            if(p.ID == oya_id) p.SCORE -= 2*stp + 100*honba;
            else p.SCORE -= 1*stp + 100*honba;
        }
    }

    kyotaku = 0;
}





void Game::play_kyoku()
{
    current_player_num = oya_id;

    while (!YAMA.empty())
    {
        PLAYER &current_player = players[current_player_num];
        current_player.yama_left_num = YAMA.size();

        TsumoAction(current_player);

        MAHJANG_HI SUTEHI;

        if(current_player.tsumoF())
        {
            tsumo_tensu();
        }
        else if(current_player.ankanF())
        {
            doramekuri();
            continue;
        }
        else
        {
            int ind = CsControll::index();
            current_player.discard(ind);
        }

        

        //次の人
        current_player_num = (current_player_num + 1)%4;

    }
}