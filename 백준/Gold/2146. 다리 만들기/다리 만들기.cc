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

using piii = pair<pii, int>;

int board[100][100];
bool visited[100][100];
bool sea_visited[100][100];

const int dirs[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

int main(){
    fastio

    int n; cin>>n;

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) cin>>board[i][j];
    }

    int shortest_bridge = -1;

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(board[i][j] != 1 || visited[i][j]) continue;
            
            queue<pii> land_q;
            queue<piii> bridge_q;
            memset(sea_visited, false, sizeof(sea_visited));

            land_q.push({i, j});

            visited[i][j] = true;

            while (!land_q.empty()) {
                int y = land_q.front().first;
                int x = land_q.front().second; land_q.pop();

                for(int i=0; i<4; ++i) {
                    int dy = y + dirs[i][0];
                    int dx = x + dirs[i][1];
                    if (dy < 0 || dy >= n || dx < 0 || dx >= n) continue;
                    if (visited[dy][dx]) continue;
                    visited[dy][dx] = true;
                    if (!board[dy][dx]) {
                        sea_visited[dy][dx] = true;
                        bridge_q.push({{dy, dx}, 1});
                    }
                    else land_q.push({dy, dx});
                }
            }

            while(!bridge_q.empty()) {
                int y = bridge_q.front().first.first;
                int x = bridge_q.front().first.second;
                int bridge = bridge_q.front().second;

                bridge_q.pop();

                // cout<<y<<" "<<x<<" "<<bridge<<endl;
                
                if (shortest_bridge != -1 && bridge > shortest_bridge) continue;

                for(int i=0; i<4; ++i) {
                    int dy = y + dirs[i][0];
                    int dx = x + dirs[i][1];
                    if (dy < 0 || dy >= n || dx < 0 || dx >= n) continue;
                    if (visited[dy][dx]) continue;
                    if (sea_visited[dy][dx]) continue;

                    if (!board[dy][dx]) {
                        sea_visited[dy][dx] = true;
                        bridge_q.push({{dy, dx}, bridge + 1});
                    }
                    else {
                        // 다른 육지에 도착한 경우
                        if (shortest_bridge != -1 && bridge >= shortest_bridge) {
                            continue; // 더 길어지거나 같으면 의미 없으므로 거부
                        }
                        if (visited[dy][dx]) continue; // 이미 테스트해본 육지
                        // cout<<"arrived "<<y<<" "<<x<<" "<<bridge<<endl;
                        shortest_bridge = bridge;
                        break;
                    }
                }
            }
        }
        
        
    }
    
    cout<<shortest_bridge;
    
}