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

    int n, m; cin>>n>>m;

    if (n < m) m = n; // 이거 때문에 계속 틀린거 디버깅했음. 
    // 물론 다른 문제도 있었으나,, 생각한 로직은 맞는 로직이었음
    // N, M 값 이상하게 들어가는 경우 제대로 처리해두자. 문제에서 명백하게 정의되지 않으면 믿지말기..
    vi v(n);

    for(int i=0; i<n; ++i) {
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    ll ans_min = 0;
    ll ans_max = 0;

    for(int i=0; i<m; ++i) {
        ans_min += v[i];  
    }

    int plus_count = n%m;
    int hop = n/m;

    int cursor = 0;
    while(m--) {
        ans_max += v.at(cursor);

        if (plus_count > 0) {
            cursor += hop + 1;
            plus_count--;
        }
        else cursor += hop;
    }

    cout<<ans_min<<" "<<ans_max<<endl;
}