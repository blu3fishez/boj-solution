#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
#define endl '\n'
using namespace std;

const int node_counts = 500 * 10000 + 5; // 문자가 10000개, 500자를 넘지 않음
const int root = 0; // 0번부터 시작
int next_count = 1; // 그다음 번호
int node_pool[node_counts][26];
bool has_str[node_counts];

int main() {
    fastio
    int n, m; cin>>n>>m;
    string tmp;
    for(int i=0; i<n; ++i) {
        cin>>tmp;
        int cur = root;
        for(char c : tmp) {
            if (!node_pool[cur][c - 'a']) {
                node_pool[cur][c-'a'] = next_count;
                cur = next_count++;
                continue;
            }
            else {
                cur = node_pool[cur][c-'a'];
            }
        }
        has_str[cur] = true;
    }

    int count = 0;
    for(int i=0; i<m; ++i) {
        cin>>tmp;
        int cur = root;
        bool finished = true;
        for(char c : tmp) {
            if (!node_pool[cur][c - 'a']) {
                finished = false;
                break;
            }
            else {
                cur = node_pool[cur][c-'a'];
            }
        }
        if (finished) count++; // 트라이에서 종료 노드만 체크하는걸 빼고, 노드 탐색에서 실패하지만 않으면 됨.
    }
    cout<<count;
}