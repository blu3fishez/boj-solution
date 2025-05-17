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

// 결국 맨 처음 했던 상태공간 트리 문제와 비슷함
int shortest_visit[100001];
int counts;

int main(){
    fastio
    int n, k; cin>>n>>k;
    memset(shortest_visit, -1, sizeof(shortest_visit));
    
    qi q;

    q.push(n);
    shortest_visit[n] = 0;

    while(!q.empty()) {
        int place = q.front();
        int time = shortest_visit[place];
        q.pop();
        
        if (place == k) {
            counts++;
            continue;
        }
        
        if (2*place <= 100000 && (shortest_visit[2*place] == -1 || shortest_visit[2*place] == time + 1)) {
            shortest_visit[2*place] = time + 1;
            q.push(place*2);
        }

        if (shortest_visit[place + 1] == -1 || shortest_visit[place + 1] == time + 1) { 
            shortest_visit[place + 1] = time + 1;
            q.push(place + 1);
        }

        if (shortest_visit[place - 1] == -1 || shortest_visit[place - 1] == time + 1){
            shortest_visit[place - 1] = time + 1;
            q.push(place - 1);
        }
    }
    cout<<shortest_visit[k]<<endl<<counts;
}