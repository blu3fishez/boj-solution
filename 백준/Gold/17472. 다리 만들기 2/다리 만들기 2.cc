#include<bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
#define endl '\n'
using namespace std;
using pii = pair<int, int>;
using psi = pair<string, int>;
using pss = pair<string, string>;
using pis = pair<int, string>;
using pci = pair<char, int>;
using pic = pair<int, char>;
using qi = queue<int>;
using qpii = queue<pii>;
using vi = vector<int>;
using vvi = vector<vector<int>>;


int sets[7]; // 1 to 6

int uf_find(int a) {
    return (sets[a] == a ? a : uf_find(sets[a]));
}

int uf_union(int a, int b) {
    if (a > b) {
        int swp = a; a = b; b = swp;
    }

    return sets[b] = uf_find(a);
}

int board[10][10];
bool visited[10][10];
priority_queue<pair<int, pii>> pq;

int n, m; 

int dirs[4][2] = {
    {0, 1},
    {0 , -1},
    {1 , 0},
    {-1, 0}
};

void mark_board(int color, int y, int x) {
    
    for(int i=0; i<4; ++i) {
        int dy = y + dirs[i][0];
        int dx = x + dirs[i][1];

        if (dy < 0 || dy >= n || dx < 0 || dx >= m) continue;
        if (visited[dy][dx]) continue;
        if (!board[dy][dx]) continue; // ?

        board[dy][dx] = color;
        visited[dy][dx] = true;
        mark_board(color, dy, dx);
    }
}


// 0 : E, 1 : W, 2 : S, 3 : N
void make_bridge(int y, int x, int len, int dir, int color) {
    // 현재 island 에서 dir 방향으로 이동
    // color 가 다르면, 이제 (color, 현재 위치로 pq 에 push)
    if (!board[y][x]) {
        int dy = y + dirs[dir][0];
        int dx = x + dirs[dir][1];
        if (dy >= n || dy < 0 || dx >= m || dx < 0) return;
        
        make_bridge(dy, dx, len + 1, dir, color);
        
        return;
    }

    if (visited[y][x]) return; // 의미없는 경우
    if (color == board[y][x]) return;
    if (len-1 == 1) return ; // 다리 길이는 2 이상

    pq.push({-len+1, {color, board[y][x]}}); // 현재 육지위 이므로
}

void test_island(int sy, int sx) {
    queue<pii> q;
    visited[sy][sx] = true;
    int color = board[sy][sx];
    q.push({sy, sx});

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; ++i) {
            int dy = y + dirs[i][0];
            int dx = x + dirs[i][1];
            
            if (dy >= n || dy < 0 || dx >= m || dx < 0) continue;
            if (visited[dy][dx]) continue;
            
            if (board[dy][dx] == color) {
                visited[dy][dx] = true;
                q.push({dy, dx});
            }

            if (!board[dy][dx]) {
                make_bridge(dy, dx, 1, i, color);
            }
        }
    }
    
}

int main(){
    fastio
    for(int i=1; i<=6; ++i) sets[i] = i;
    
    cin>>n>>m;

    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin>>board[i][j];
        }
    }

    int is_count = 0;

    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if (!visited[i][j] && board[i][j]) {
                visited[i][j] = true;
                is_count++;
                board[i][j] = is_count;
                mark_board(is_count, i, j);
            }
        }
    }


    memset(visited, false, sizeof(visited));

    for (int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            // cout<<board[i][j]<<' ';
            if (board[i][j]) test_island(i, j);
        }
    }

    // uf 로 이제 mst 구성

    int cnt = 0;
    int ans = 0;
    while(cnt < is_count - 1 && !pq.empty()) {
        int union_a = uf_find(pq.top().second.first);
        int union_b = uf_find(pq.top().second.second);
        int len = -pq.top().first;
        pq.pop();
        if (union_a == union_b) continue;
        
        // cout<<" bridge (a, b, len): "<<union_a<<" "<<union_b<<" "<<len<<endl;
        

        
 
        uf_union(union_a, union_b);
        cnt++;
        ans += len;
    }

    if (cnt != is_count - 1) {
        cout<<-1;
    }
    else cout<<ans;
}