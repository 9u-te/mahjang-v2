#include "new-MJ_G.h"

Game::Game() : BAFU(TON), YAMA(), WANGPAI(), DraHyouji(), uraDraHyouji()
{
    for (int i = 0; i < 4; i++)
    {
        players.emplace_back(i);
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
    KAWA0.clear();
    KAWA1.clear();
    KAWA2.clear();
    KAWA3.clear();

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
    DraHyouji = {WANGPAI[9]};

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

    for (PLAYER &player : players) {
        player.repai();
    }

}

void Game::TsumoAction(PLAYER &player)
{
    player.TSUMO = YAMA.back();
    YAMA.pop_back();
}



