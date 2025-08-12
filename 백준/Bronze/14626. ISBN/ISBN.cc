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
using ld = long double;

int main(){
    fastio
    
    string input; cin>>input;

    bool is_three = false;
    bool t_is_three;
    int three_map[11] = {
        0,
        3,
        6,
        9,
        2,
        5,
        8,
        1,
        4,
        7
    };
    int sum = 0;
    for(char t : input) {
        if (t == '*') {
            t_is_three = is_three;
        }
        else {
            sum += is_three ? 3*(t - '0') : t - '0';  
        }
        is_three = !is_three;
    }

    if (!t_is_three) cout<<10 - sum%10<<endl;
    else cout<<three_map[sum%10]<<endl;
}