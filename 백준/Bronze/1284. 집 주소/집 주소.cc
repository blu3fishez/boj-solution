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
    string input;
    while(1) {
        cin>>input;
        if (input == "0") break;
        int ans = 1;
        for(char t : input) {
            if (t == '0') ans += 5;
            else if (t == '1') ans += 3;
            else ans += 4;
        }
        cout<<ans<<endl;
    }
}