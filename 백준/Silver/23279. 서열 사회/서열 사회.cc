#include<bits/stdc++.h>
#include <queue>
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
using ll = long long;

int main(){
    fastio

    int n, k; cin>>n>>k;

    vector<priority_queue<int>> pq_list(k, priority_queue<int>());
    vvi ans(k, vi());

    for(int i=0; i<k; ++i) {
        int sz, tmp; cin>>sz;
        while(sz--) {
            cin>>tmp;
            pq_list[i].push(-tmp);
        }
    }

    for(int i=1; i<=n; ++i) {
        int least_idx = -1;
        int least_val = -1;
        for(int j=0; j<k; ++j) {
            if (!pq_list[j].empty() && (least_val == -1 || least_val > ans[j].size() - pq_list[j].top())) {
                least_val = ans[j].size() - pq_list[j].top();
                least_idx = j;
            }
        }
        ans[least_idx].push_back(i);
        pq_list[least_idx].pop();
    }

    for(vi v : ans) {
        for(int val : v) {
            cout<<val<<" ";
        }
        cout<<endl;
    }
}