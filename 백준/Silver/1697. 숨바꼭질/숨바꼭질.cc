// bfs 에서 가장 중요한 패턴인데, visit배열에 방문체크 시점에 대해서 조심해야합니다.
// 방문 체크를 현재 노드에서 할지, 방문할 시점에서 할지에 따라 성능도 달라지고, 중복 방문 여부도 달라집니다.
// bfs 에서 방문 체크를 현재 노드에 함으로써, 하나의 노드에 대한 중복 방문을 허용하게 됩니다.
// 대신, 현재 노드에서 방문체크를 하기 때문에 중복된 경로는 생기지 않아요.

// 이전 제 코드입니다.

#include<iostream>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
bool visit[100001];

int find(int N, int K){
    queue<pii> q;
    q.push(make_pair(N, 0));
    while(!q.empty()){
        pii node = q.front(); q.pop();
        visit[node.first] = true;
        if(node.first == K) return node.second;
        if(node.first*2 <= 100000 && !visit[node.first*2]) q.push(make_pair(node.first*2, node.second + 1));
        if(node.first + 1 <= 100000 && !visit[node.first + 1]) q.push(make_pair(node.first + 1, node.second + 1));
        if(node.first - 1 >= 0 && !visit[node.first - 1]) q.push(make_pair(node.first - 1, node.second + 1));
    }
    return -1;
}

int main(){
    int N, K; cin>>N>>K;
    cout<<find(N, K);
}