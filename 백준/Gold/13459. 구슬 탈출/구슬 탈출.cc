#include<iostream>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
#define endl '\n'
using namespace std;

char board[15][15];
int n, m;

using pii = pair<int, int>;

int lean_dir[4][2] = {
    {-1, 0}, 
    {0, 1},
    {1, 0},
    {0, -1}
};

// red, blue: 현재 당장의 위치. lean : 기울여서 가야함
void solve(int chance, int lean, pii red, pii blue) {
    if (chance == 0) {
        return;
    }
    pii next_red = red;
    pii next_blue = blue;
    int red_moves = 0;
    int blue_moves = 0;
    while(1) {
        // 파란 공이 먼저 빠지면 안되므로 파란 공부터 시뮬레이션해야함.
        pii db = next_blue;
        db.first += lean_dir[lean][0];
        db.second += lean_dir[lean][1];
        if (board[db.first][db.second] == '#') {
            break;
        }
        if (board[db.first][db.second] == 'O') {
            return; // 파란색 공이 빠져나가면 안됨
        }
        next_blue = db;
        blue_moves++;
    }

    while(1) {
        pii dr = next_red;
        dr.first += lean_dir[lean][0];
        dr.second += lean_dir[lean][1];

        if (board[dr.first][dr.second] == '#') {
            break;
        }
        
        if (board[dr.first][dr.second] == 'O') {
            cout<<1;
            exit(0);
        }

        next_red = dr;
        red_moves++;
    }
    
    // 공 겹친경우 예외처리
    if (next_red.first == next_blue.first && next_red.second == next_blue.second) {
        // 더 많이 움직인 쪽으로 기댄 반대쪽으로 이동
        // 
        if (red_moves > blue_moves) {
            next_red.first -= lean_dir[lean][0];
            next_red.second -= lean_dir[lean][1];
        }
        if (red_moves < blue_moves) {
            next_blue.first -= lean_dir[lean][0];
            next_blue.second -= lean_dir[lean][1];
        }
    }
    
    for(int i=0; i<4; ++i) {
        if (lean != i) solve(chance - 1, i, next_red, next_blue);
    }
}

int main(){
    fastio
    
    cin>>n>>m;

    pii red, blue;
    
    for(int i=0; i<n; ++i) {
        string line;
        cin>>line;
        for(int j=0; j<m; ++j) {
            board[i][j] = line[j];
            if (line[j] == 'R') {
                red = {i, j};
                board[i][j] = '.';
            }
            if (line[j] == 'B') {
                blue = {i, j};
                board[i][j] = '.';
            }
        }
    }

    for(int i=0; i<4; ++i) {
        solve(10, i, red, blue);
    }

    cout<<0; // exit 을 쓰지 않고 깔끔하게 정리하는 방법이 있을까?
}