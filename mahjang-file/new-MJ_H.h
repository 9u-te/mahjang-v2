#pragma once
#include<vector>

class MAHJANG_HI{
    public:
        int TYPE;
        int RANK;
        int DORA;


        MAHJANG_HI() = default;

        MAHJANG_HI(int t, int r, int d){
            TYPE = t;
            RANK = r;
            DORA = d;
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

//萬子
inline MAHJANG_HI M1(0, 1, 0);
inline MAHJANG_HI M2(0, 2, 0);
inline MAHJANG_HI M3(0, 3, 0);
inline MAHJANG_HI M4(0, 4, 0);
inline MAHJANG_HI M5(0, 5, 0);
inline MAHJANG_HI M6(0, 6, 0);
inline MAHJANG_HI M7(0, 7, 0);
inline MAHJANG_HI M8(0, 8, 0);
inline MAHJANG_HI M9(0, 9, 0);
inline MAHJANG_HI M5_RED(0, 5, 1);

//筒子
inline MAHJANG_HI P1(1, 1, 0);
inline MAHJANG_HI P2(1, 2, 0);
inline MAHJANG_HI P3(1, 3, 0);
inline MAHJANG_HI P4(1, 4, 0);
inline MAHJANG_HI P5(1, 5, 0);
inline MAHJANG_HI P6(1, 6, 0);
inline MAHJANG_HI P7(1, 7, 0);
inline MAHJANG_HI P8(1, 8, 0);
inline MAHJANG_HI P9(1, 9, 0);
inline MAHJANG_HI P5_RED(1, 5, 1);

//索子
inline MAHJANG_HI S1(2, 1, 0);
inline MAHJANG_HI S2(2, 2, 0);
inline MAHJANG_HI S3(2, 3, 0);
inline MAHJANG_HI S4(2, 4, 0);
inline MAHJANG_HI S5(2, 5, 0);
inline MAHJANG_HI S6(2, 6, 0);
inline MAHJANG_HI S7(2, 7, 0);
inline MAHJANG_HI S8(2, 8, 0);
inline MAHJANG_HI S9(2, 9, 0);
inline MAHJANG_HI S5_RED(2, 5, 1);

//風牌
inline MAHJANG_HI TON(3, 1, 0);
inline MAHJANG_HI NAM(3, 2, 0);
inline MAHJANG_HI SHA(3, 3, 0);
inline MAHJANG_HI PAY(3, 4, 0);

//三元牌
inline MAHJANG_HI HAK(4, 1, 0);
inline MAHJANG_HI HAT(4, 2, 0);
inline MAHJANG_HI CHU(4, 3, 0);



//すべての牌
inline std::vector<MAHJANG_HI> ALL_HI={ M1, M2, M3, M4, M5, M6, M7, M8, M9, 
                                        P1, P2, P3, P4, P5, P6, P7, P8, P9,
                                        S1, S2, S3, S4, S5, S6, S7, S8, S9, 
                                        TON, NAM, SHA, PAY,
                                        HAK, HAT, CHU};

