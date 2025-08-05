#include<bits/stdc++.h>
#include <math.h>
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

    while(1) {
        int n; cin>>n;
        if (n == -1) return 0;
        vector<int> v;
        int check = 0;
        for(int i=1; i<n; ++i) {
            if (n%i == 0) {
                v.push_back(i);
                check += i;
            }
        }
        if (check == n) {
            cout<<n<<" = ";
            for(int i=0; i<v.size()-1; ++i) {
                cout<<v[i]<<" + ";
            }
            cout<<v.at(v.size()-1)<<endl;
        }
        else cout<<n<<" is NOT perfect."<<endl;
    }
    
}