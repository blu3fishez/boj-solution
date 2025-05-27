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
    vi v;
    
    int avg = 0;

    for(int i=0; i<5; ++i) {
        int t; cin>>t;
        avg += t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    cout<<avg/5<<endl<<v[2];
}