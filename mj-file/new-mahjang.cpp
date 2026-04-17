#include "mj_5G.h"
#include <windows.h> 

int main(){
    //コンソール画面の設定
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(fontInfo);
    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo); // 現在のフォント設定を取得

    fontInfo.dwFontSize.Y = 32;
    wcscpy(fontInfo.FaceName, L"MS Gothic");
    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);



    Game mahjang;

    mahjang.oya_id = mahjang.dicision_oya();

    while (mahjang.kyoku <= 9){
        mahjang.initilize_kyoku();
        
        mahjang.play_kyoku();
    }
}