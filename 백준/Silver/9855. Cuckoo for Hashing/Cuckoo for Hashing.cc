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
using ll = long long;

int main(){
    fastio

    int tc = 0;

    while(1) {
        int n[2], m;
        cin>>n[0]>>n[1]>>m;

        if (!n[0] && !n[1] && !m) {
            break;
        }

        cout<<"Case "<<++tc<<":"<<endl;

        vector<map<int, int>> hashmaps;

        hashmaps.push_back(map<int, int>());
        hashmaps.push_back(map<int, int>());

        for(int i=0; i<m; ++i) {
            int tmp; cin>>tmp;
            
            int it = 0;

            // 충돌이 일어났을 때
            while(hashmaps[it%2].find(tmp % n[it%2]) != hashmaps[it%2].end()) {
                int swp = hashmaps[it%2][tmp % n[it%2]];

                hashmaps[it%2][tmp % n[it%2]] = tmp;

                tmp = swp;

                it++;
            }

            hashmaps[it % 2][tmp % n[it%2]] = tmp;
        }

        if (!hashmaps[0].empty()) {
            cout<<"Table 1"<<endl;
            for(pii t : hashmaps[0]) {
                cout<<t.first<<":"<<t.second<<endl;
            }
        }
        if (!hashmaps[1].empty()) {
            cout<<"Table 2"<<endl;
            for(pii t : hashmaps[1]) {
                cout<<t.first<<":"<<t.second<<endl;
            }
        }
    }
}