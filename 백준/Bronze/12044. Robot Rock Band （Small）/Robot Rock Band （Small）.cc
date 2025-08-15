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

int check_k(int robot_maps[][51], int place, int n, int k, int val) {
    int result = 0;

    for(int i=0; i<n; ++i) {
        if (place < 3) result += check_k(robot_maps, place + 1, n, k, place == 0 ? robot_maps[place][i] : (val ^ robot_maps[place][i]));
        else result += ((val ^ robot_maps[place][i]) == k) ? 1 : 0;
    }

    return result;
}

int main(){
    fastio

    int tc; cin>>tc;

    for(int t = 1; t<=tc; ++t) {
        int n, k; cin>>n>>k;
        
        int robot_maps[4][51];

        memset(robot_maps, 0, sizeof(robot_maps));

        for(int i=0; i<4; ++i) {
            for(int j=0; j<n; ++j) {
                cin>>robot_maps[i][j];
            }
        }

        cout<<"Case #"<<t<<": "<<check_k(robot_maps, 0, n, k, 0)<<endl;
    }
    
}
