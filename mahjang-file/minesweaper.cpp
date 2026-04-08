#include <iostream>
#include <vector>
#include <random>

std::vector<int> dxs = {-1, -1, -1, 0, 0, 1, 1, 1};
std::vector<int> dys = {-1, 0, 1, -1, 1, -1, 0, 1};

std::random_device rd;
std::mt19937 g(rd());


struct tiledata {
    bool mine;
    bool cover;
    bool flag;
    int around_num;

    tiledata(bool m, bool c, bool f, int an){
        mine = m;
        cover = c;
        flag = f;
        around_num = an;
    }
};

namespace tiletype {
    int mine = 9;
    int cover = 10;
    int flag = 11;
}



class minesweaper {
        int game_size;
        int ratio;
        int all_mine_num;

        std::vector<std::vector<tiledata>> game_table;
    public:
        std::vector<std::vector<int>> display_table;

    
        minesweaper(int size, int first_x, int first_y):game_size(size), ratio(0.15), all_mine_num(size*size*ratio), game_table(size,std::vector<tiledata>(size)){
            for(int i = 0; i < game_size; i++){
                for(int j = 0; j < game_size; j++){
                    game_table[i][j] = tiledata(false, true, false, 0);
                }
            }

            game_table[first_x][first_y].mine = true;
            for(int i = 0; i < 8; i++){
                int mx = first_x + dxs[i];
                int my = first_y + dys[i];
                game_table[mx][my].mine = true;
            }
            std::uniform_int_distribution<> dist(0, size - 1);

            for(int i = 0; i < all_mine_num; i++){
                while(true){
                    int rx = dist(g);
                    int ry = dist(g);
                    if(game_table[rx][ry].mine){
                        continue;
                    }
                    game_table[rx][ry].mine = true;
                    break;
                }
            }

            game_table[first_x][first_y].mine = true;
            for(int i = 0; i < 8; i++){
                int mx = first_x + dxs[i];
                int my = first_y + dys[i];
                game_table[mx][my].mine = false;
            }

            for(int i = 0; i < game_size; i++){
                for(int j = 0; j < game_size; j++){
                    if(!game_table[i][j].mine){
                        continue;
                    }
                    for(int k = 0; k < 8; k++){
                        game_table[i+dxs[k]][j+dys[k]].around_num +=1;
                    }
                }
            }
        }

        bool chainf(int x, int y){
            if(!range_check(x, y)) return false;
            if(game_table[x][y].around_num != 0) return false;
            for(int i = 0; i < 8; i++){
                int mx = x + dxs[i];
                int my = y + dys[i];
                if(!range_check(mx, my)) break;
                game_table[mx][my].cover = false;
                chainf(mx, my);
            }
            
        }


        bool openf(int x, int y){
            if(!range_check(x, y) || !game_table[x][y].cover) return false;
            game_table[x][y].cover = false;
        }

        bool flagf(int x, int y){
            if(!range_check(x, y)) return false;
            if(!game_table[x][y].cover) return false;
            if(game_table[x][y].flag) game_table[x][y].flag = false;
            if(!game_table[x][y].flag) game_table[x][y].flag = true;
        }

    private:
        bool range_check(int x, int y){
            return 0 < x && x < game_size && 0 < y && y < game_size;
        }

        void display_table_gen(){
            for(int i = 0; i < game_size; i++){
                for(int j = 0; j < game_size; j++){
                    if(game_table[i][j].cover){
                        display_table[i][j] = tiletype::cover;
                    }
                    else if(game_table[i][j].flag){
                        display_table[i][j] = tiletype::flag;
                    }
                    else if(game_table[i][j].mine){
                        display_table[i][j] = tiletype::mine;
                    }
                    else {
                        display_table[i][j] = game_table[i][j].around_num;
                    }

                }
            }
        }
};

void displayf(std::vector<std::vector<int>> display_table){
    int size = display_table.size();

    std::cout << "  ";
    for(int i = 0; i < size; i++){
        std::cout << '|' << i << '|';
    }

    for(int i = 0; i < size; i++){
        std::cout << i << '|';
        for(int j = 0; j < size; j++){
            int num = display_table[i][j];
            if(num == 11){
                std::cout << "|_|";
            }
            else if(num == 10){
                std::cout << "|F|";
            }
            else if(num == 9){
                std::cout << "|M|";
            }
            else if(num == 0){
                std::cout << " - ";
            }
            else{
                std::cout << '|' << num << '|';
            }
        }
        std::cout << std::endl;
    }
}



int main(){
    std::cout << "put size, x, y";
    int size, fx, fy;
    std::cin >> size >> fx >> fy;
    minesweaper game(size, fx, fy);

    bool running = true;

    while(running){
        displayf(game.display_table);

    }
}