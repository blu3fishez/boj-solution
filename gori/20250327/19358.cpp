/** 

메모장 

인접 노드의 주변에 있는 인물들을 매번 세고 있었는데, 이걸 세지 않는게 시간초과 피하는 방법이라고 본다.

*/

#include<bits/stdc++.h>
using namespace std;
#define fastio \
    ios_base::sync_with_stdio(false); \
    cin.tie(0); \
    cout.tie(0);
#define endl '\n'

bool visited[200001];
int believe_time[200001];
int need_believe[200001];
int ans;

int main(){
    fastio;
    int n; cin>>n;
    vector<vector<int>> adj(n+1);
    memset(believe_time, -1, sizeof(int)*(n+1));
    // 최대 모두가 다 소문을 믿게되는 시간은 n초

    queue<pair<int, int>> q; // (루머를 믿을 수 있는 후보, 시간은 전역변수)

    for(int i=1; i<=n; ++i) {
        int tmp; 
        while(true) {
            cin>>tmp;
            if (!tmp) break;
            adj[i].push_back(tmp);
        }
    }

    int rumors; cin>>rumors;
    for(int i=0; i<rumors; ++i) {
        int tmp; cin>>tmp;
        believe_time[tmp] = 0;
        visited[tmp] = true;
        q.push({tmp, 0});
    }
    
    for(int i=1; i<=n; ++i) {
        need_believe[i] = adj[i].size()/2 + adj[i].size()%2;
    }

    while(!q.empty()) {
        int node = q.front().first;
        int time = q.front().second;
        q.pop();

        for(int t : adj[node]) {
            int adj_mems = adj[t].size();
            int adj_believe = 0;

            // 이게 문제 같은데
            // 인접 노드에 주변 애들을 매번 체크해야할까
            need_believe[t]--;
            
            if (need_believe[t]) continue;
            if (visited[t]) continue;

            visited[t] = true;
            believe_time[t] = time + 1;
            q.push({t, time + 1});
        }
    }

    for(int i=1; i<=n; ++i) {
        cout<<believe_time[i]<<' ';
    }
}