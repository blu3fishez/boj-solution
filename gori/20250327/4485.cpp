/** 

메모장 



*/

#include<bits/stdc++.h>
#include <queue>
using namespace std;
#define fastio \
    ios_base::sync_with_stdio(false); \
    cin.tie(0); \
    cout.tie(0);
#define endl '\n'

int graph[125][125];
int dp[125][125];
int dir[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

int main(){
    fastio;
    int tc = 0;
    while(1) {
        tc++;
        int n; cin>>n;
        if (!n) break;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j) {
                cin>>graph[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        queue<pair<int, pair<int, int>>> q;

        q.push({graph[0][0], {0, 0}});
        
        dp[0][0] = graph[0][0];

        while(!q.empty()) {
            int x = q.front().second.second;
            int y = q.front().second.first;
            int lost = q.front().first;
            q.pop();

            if (dp[y][x] != -1 && lost > dp[y][x]) continue;
            
            dp[y][x] = lost;

            for(int i=0; i<4; ++i) {
                int dy = y + dir[i][0];
                int dx = x + dir[i][1];
                if (dy >= n || dy < 0 || dx >= n || dx < 0) continue;
                if (dp[dy][dx] == -1 || graph[dy][dx] + dp[y][x] < dp[dy][dx]) {
                    dp[dy][dx] = dp[y][x] + graph[dy][dx];
                    q.push({dp[dy][dx], {dy, dx}});
                }
            }
        }

        cout<<"Problem "<<tc<<": "<<dp[n-1][n-1]<<endl;
    }
}