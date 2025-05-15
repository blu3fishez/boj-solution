#include<bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
#define endl '\n'
using namespace std;

int visited[200][200];

int main(){
    fastio
    int tc; cin>>tc;
    while(tc--) {
        int s, t, count = 0; cin>>s>>t;
        memset(visited, -1, sizeof(visited));
        queue<pair<int, int>> q;

        q.push({s, t});
        visited[s][t] = 0;
        while (!q.empty()) {
            pair<int, int> node = q.front(); q.pop();
            
            int cs = node.first;
            int ct = node.second;

            if (ct == cs) {
                cout<<visited[cs][ct]<<endl;
                break;
            }

            if (2*cs <= ct + 3 && (visited[2*cs][ct + 3] == -1 || visited[2*cs][ct + 3] > visited[cs][ct] + 1))  {
                visited[2*cs][ct + 3] = visited[cs][ct] + 1;
                q.push({2*cs, ct + 3});
            }
            
            if (visited[cs + 1][ct] == -1 || visited[cs + 1][ct] > visited[cs][ct] + 1) {
                visited[cs + 1][ct] = visited[cs][ct] + 1;
                q.push({cs + 1, ct});
            }
        }
    }
}