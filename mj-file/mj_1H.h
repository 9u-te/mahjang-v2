#pragma once
#include <vector>
#include <iostream>




namespace TileType{
    const int Manzu = 0;
    const int Pinzu = 1;
    const int Souzu = 2;
    const int Kaze = 3;
    const int Sangen = 4;
}

class MAHJANG_HI{
    public:
        int TYPE;
        int RANK;
        bool isRed;


        MAHJANG_HI() = default;

        MAHJANG_HI(int t, int r, bool d){
            TYPE = t;
            RANK = r;
            isRed = d;
        };

        //演算子オーバーロード----------------------
        bool operator==(const MAHJANG_HI HI) const;//イコール

        bool operator!=(const MAHJANG_HI HI) const;//ノットイコール

        bool operator<(const MAHJANG_HI HI) const;//大小関係
        
        MAHJANG_HI operator+(const int n) const;//足し算

        MAHJANG_HI operator-(const int n) const;//引き算

        //ドラ関数---------------------------------------------------------------------
        MAHJANG_HI get_DRA();
 
};

//麻雀牌------------------------------------------------

inline const MAHJANG_HI HiUra(-1, -1, false);
//萬子
inline const MAHJANG_HI M1(TileType::Manzu, 1, false);
inline const MAHJANG_HI M2(TileType::Manzu, 2, false);
inline const MAHJANG_HI M3(TileType::Manzu, 3, false);
inline const MAHJANG_HI M4(TileType::Manzu, 4, false);
inline const MAHJANG_HI M5(TileType::Manzu, 5, false);
inline const MAHJANG_HI M6(TileType::Manzu, 6, false);
inline const MAHJANG_HI M7(TileType::Manzu, 7, false);
inline const MAHJANG_HI M8(TileType::Manzu, 8, false);
inline const MAHJANG_HI M9(TileType::Manzu, 9, false);
inline const MAHJANG_HI M5_RED(TileType::Manzu, 5, true);

//筒子
inline const MAHJANG_HI P1(TileType::Pinzu, 1, false);
inline const MAHJANG_HI P2(TileType::Pinzu, 2, false);
inline const MAHJANG_HI P3(TileType::Pinzu, 3, false);
inline const MAHJANG_HI P4(TileType::Pinzu, 4, false);
inline const MAHJANG_HI P5(TileType::Pinzu, 5, false);
inline const MAHJANG_HI P6(TileType::Pinzu, 6, false);
inline const MAHJANG_HI P7(TileType::Pinzu, 7, false);
inline const MAHJANG_HI P8(TileType::Pinzu, 8, false);
inline const MAHJANG_HI P9(TileType::Pinzu, 9, false);
inline const MAHJANG_HI P5_RED(TileType::Pinzu, 5, true);

//索子
inline const MAHJANG_HI S1(TileType::Souzu, 1, false);
inline const MAHJANG_HI S2(TileType::Souzu, 2, false);
inline const MAHJANG_HI S3(TileType::Souzu, 3, false);
inline const MAHJANG_HI S4(TileType::Souzu, 4, false);
inline const MAHJANG_HI S5(TileType::Souzu, 5, false);
inline const MAHJANG_HI S6(TileType::Souzu, 6, false);
inline const MAHJANG_HI S7(TileType::Souzu, 7, false);
inline const MAHJANG_HI S8(TileType::Souzu, 8, false);
inline const MAHJANG_HI S9(TileType::Souzu, 9, false);
inline const MAHJANG_HI S5_RED(TileType::Souzu, 5, true);

//風牌
inline const MAHJANG_HI TON(TileType::Kaze, 1, false);
inline const MAHJANG_HI NAM(TileType::Kaze, 2, false);
inline const MAHJANG_HI SHA(TileType::Kaze, 3, false);
inline const MAHJANG_HI PAY(TileType::Kaze, 4, false);

//三元牌
inline const MAHJANG_HI HAK(TileType::Sangen, 1, false);
inline const MAHJANG_HI HAT(TileType::Sangen, 2, false);
inline const MAHJANG_HI CHU(TileType::Sangen, 3, false);



//すべての牌
inline const std::vector<MAHJANG_HI> ALL_HI = { M1, M2, M3, M4, M5, M6, M7, M8, M9, 
                                                P1, P2, P3, P4, P5, P6, P7, P8, P9,
                                                S1, S2, S3, S4, S5, S6, S7, S8, S9, 
                                                TON, NAM, SHA, PAY,
                                                HAK, HAT, CHU};

struct YAKU{
    public:
        int han;
        int naki_han;
        int yaku_man;
        bool naki_yaku_man;
    
        YAKU(int h, int nh, int y, int ny){
            han = h;
            naki_han = nh;
            yaku_man = y;
            naki_yaku_man = ny;
        };
};