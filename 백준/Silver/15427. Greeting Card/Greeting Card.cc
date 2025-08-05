#include<bits/stdc++.h>
#include <unordered_map>
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


int main() {
    fastio
    
    int n; cin>>n;
    const int DISTANCE = 2018 * 2018;

    set<pii> hashset;

    set<pii> dists; // 거리가 2018이 되는 지점
    
    // 런타임 이전의 전처리
    for(int i=-2018; i<=2018; ++i) {
        for(int j=-2018; j<=2018; ++j) {
            if (DISTANCE == i * i + j * j) {
                dists.insert({i, j});
            }
        }
    }


    // n 개의 점을 입력받고
    for(int i=0; i<n; ++i) {
        int y, x;
        cin>>x>>y;
        hashset.insert({x, y});
    }

    int ans = 0;

    for(pii point : hashset) {
        for(pii offset : dists) {
            pii biased = {
                point.first + offset.first,
                point.second + offset.second
            };
            
            if (hashset.find(biased) != hashset.end()) {
                ans++;
            }
        }
    }

    cout<<ans/2<<endl;
}