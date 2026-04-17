#include "mj_5G.h"
#include "cscontroll.h"
#include "mj_2P.h"

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
        players[(oya_num + i) % 4].JIFU = MAHJANG_HI(TileType::Kaze, i + 1, false);
    }
    return oya_num;
}

void Game::initilize_kyoku()
{ // カンカウントのリセット
    KanCount = 0;
    YAMA.clear();
    WANGPAI.clear();
    DraHyouji.clear();
    uraDraHyouji.clear();

    for (int i = 0; i < 4; i++)
    {
        players[(oya_id + i) % 4].JIFU = MAHJANG_HI(TileType::Kaze, i + 1, false);
    }

    if(BAFU == TON) std::cout << "東";
    else if(BAFU == NAM) std::cout << "南";
    else if(BAFU == SHA) std::cout << "西";
    else if(BAFU == PAY) std::cout << "北";
    std::cout << kyoku%4 + 1 << "局" << honba << "本場" <<std::endl;

    std::cout << "あなたは";
    if(players[0].JIFU == TON) std::cout << "東家\n";
    else if(players[0].JIFU == NAM) std::cout << "南家\n";
    else if(players[0].JIFU == SHA) std::cout << "西家\n";
    else if(players[0].JIFU == PAY) std::cout << "北家\n";
    std::cout << std::endl;

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
    DraHyouji = {WANGPAI[9], HiUra, HiUra, HiUra, HiUra};



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

    std::cout << "どら表示:" << CsControll::display(DraHyouji) << std::endl;
    std::cout << CsControll::display(players[0].TEHAI) << std::endl;
}

// つも
void Game::TsumoAction(PLAYER &player)
{
    player.TSUMO = YAMA.back();
    YAMA.pop_back();
}

//捨てる
void Game::discard(MAHJANG_HI HI, int suteru_current_player_num)
{
    KAWAs[suteru_current_player_num].push_back(players[suteru_current_player_num].TSUMO);
}

//リーチ
void Game::reachF()
{
    kyotaku += 1000;
}

//ポン
int Game::ponF(int pon_current_player_num)
{
    KAWAs[current_player_num].pop_back();
    return pon_current_player_num;

}

//チー
void Game::chiF(int chi_current_player_num)
{
    KAWAs[current_player_num].pop_back();
}

//みんかん
int Game::minkanF(int kan_current_player_num)
{
    KAWAs[current_player_num].pop_back();
    return kan_current_player_num;
}

//どらめくり
void Game::doramekuri()
{
    auto it = std::find(DraHyouji.begin(), DraHyouji.end(), HiUra);

    *it = WANGPAI[9 - 2*(it - DraHyouji.begin())];

    std::cout << "どら表示:" << CsControll::display(DraHyouji) << std::endl;
}

//流局
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
        kyoku = kyoku + 1;
        BAFU = MAHJANG_HI(TileType::Kaze, kyoku/4 + 1, 0);
    }
}

//で上がり点数
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

//つも上がりテンス
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





int Game::play_kyoku()
{
    current_player_num = oya_id;

    while (!YAMA.empty())
    {
        PLAYER &current_player = players[current_player_num];
        current_player.yama_left_num = YAMA.size();

        TsumoAction(current_player);
        if(current_player.ID == 0){
            std::cout << "0123456789" << std::endl;
            std::cout << CsControll::display(current_player.TEHAI) << ':' << CsControll::display(current_player.TSUMO) << std::endl;
        }
        MAHJANG_HI SUTEHI;//捨てられた牌

        if(current_player.ID == 0){
            // あんかん
            if(current_player.ankanF()){
                if(KanCount == 4){
                    ryukyoku();
                    return 0;
                }
                doramekuri();
                TsumoAction(current_player);//嶺上のかわり
                KanCount++;
            }
            //リーチ
            if(current_player.reachF()){
                kyotaku += 1000;
            }
            //つも
            if(current_player.tsumoF()){
                tsumo_tensu();
                return 1;
            }
        }
        



        if(current_player.ID == 0){
            
            std::cout << "捨てる牌を選んでください" << std::endl;
            int ind = CsControll::index();
            SUTEHI = current_player.discard(ind);
        }
        else {
            SUTEHI = current_player.discard(13);
        }
        current_player.repai();

        if(current_player.JIFU == TON) std::cout << "東家: ";
        else if(current_player.JIFU == NAM) std::cout << "南家: ";
        else if(current_player.JIFU == SHA) std::cout << "西家: ";
        else if(current_player.JIFU == PAY) std::cout << "北家: ";

        KAWAs[current_player_num].push_back(SUTEHI);
        
        std::cout << CsControll::display(KAWAs[current_player_num]) << "\n" << std::endl;
        
        //鳴き チーは後で実装
        for(PLAYER &p : players){
            if(p.ID == 0){
                if(p.ponF(SUTEHI)){
                    current_player_num = ponF(p.ID);
                    break;
                }
                if (p.minkanF(SUTEHI)){
                    if(KanCount == 4){
                        ryukyoku();
                        return 0;
                    }
                    current_player_num = minkanF(p.ID);
                    TsumoAction(p);
                    doramekuri();
                    KanCount++;
                }
                
            }

        }

        //次の人
        current_player_num = (current_player_num + 1)%4;
    }

    if(YAMA.empty()){
        std::cout << "===流局===\n" << std::endl;
        ryukyoku();
        return 0;
    }
    return 0;
}