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

int main(){
    fastio
    
    vector<string> vs(5);

    int mx_len = -1;
    for(int i=0; i<5; ++i) {
        cin>>vs[i];
        mx_len = (mx_len < (int)vs[i].length()) ? vs[i].length() : mx_len;
    }

    for(int i=0; i<mx_len; ++i) {
        for(int j=0; j<5; ++j) {
            if ((int)vs[j].length() <= i) continue;
            cout<<vs[j][i];
        }
    }
}