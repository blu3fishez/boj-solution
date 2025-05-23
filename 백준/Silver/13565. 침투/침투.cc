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

int arr[1000][1000];
bool visited[1000][100];

int dir[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0 ,1}
};

bool connected;

int main(){
    fastio
    int n, m; cin>>n>>m;
    for(int i=0; i<n; ++i) {
        string line;
        cin>>line;
        for(int j=0; j<m; ++j) {
            arr[i][j] = line[j] - '0';
        }
    }
    
    for(int i=0; i<m && !connected; ++i) {
        qpii q;
        if (arr[0][i]) continue;
        q.push({0, i});

        while(!q.empty()) {
            pii node = q.front(); q.pop();
            int y = node.first;
            int x = node.second;
            if (y == n - 1) {
                connected = true;
                break;
            }

            for(int k=0; k<4; ++k) { 
                int dy = y + dir[k][0];
                int dx = x + dir[k][1];
                if (dy >= n || dy < 0 || dx >= m || dx < 0) continue;
                if (arr[dy][dx] || visited[dy][dx]) continue;
                visited[dy][dx] = true;
                q.push({dy, dx});
            }
        }
    }

    cout<<(connected ? "YES" : "NO");
}