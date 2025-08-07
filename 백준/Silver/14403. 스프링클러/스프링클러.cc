#include<bits/stdc++.h>
#include <queue>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
#define endl '\n'
using namespace std;
using ll = long long;
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
    
    int n;
    ll s1_x, s2_x, s1_y, s2_y;

    cin>>n>>s1_x>>s1_y>>s2_x>>s2_y;

    ll r1 = 0, r2 = 0;

    ll ans = 999999999999999999L;

    vector<pii> v(n);
    vector<ll> d1;
    vector<ll> d2;

    for(int i=0; i<n; ++i) {
        
        cin>>v[i].first>>v[i].second;
    }

    // 처음부터 최적의 해를 계산할 수 없기 때문에, 임의의 점 하나를 좌표하나와 거리를 잡은 다음,
    // 그 거리에 포함되지 않는 지점들 중 포함되지 않는 점들을 

    for(int i=0; i<n; ++i) {
        // 임의의 점을 하나로 잡는 루프
        r1 = pow(v[i].first - s1_x, 2) + pow(v[i].second - s1_y, 2);
        r2 = 0;

        // 이후, 포함되지 않는 원들 중 나머지 스프링쿨러 좌표와 가장 거리가 먼 경우가 최종 답변의 후보가 된다.
        for(int j=0; j<n; ++j) {
            ll r1_j = pow(v[j].first - s1_x, 2) + pow(v[j].second - s1_y, 2);
            if (r1_j > r1) {
                ll r2_j = pow(v[j].first - s2_x, 2) + pow(v[j].second - s2_y, 2);
                r2 = r2_j > r2 ? r2_j : r2;
            }
        }

        ans = ans > (r1 + r2) ? (r1 + r2) : ans;
    }

    // 처음 임의로 좌표 s1 과의 관계를 바탕으로 생각해볼때, 정답의 순서가 달라질 수 있다.
    // 왜냐하면 위치가 다르기 때문에, 루프를 돌리는 원의 크기가 매번 달라지기 때문

    for(int i=0; i<n; ++i) {
        // 임의의 점을 하나로 잡는 루프
        r1 = pow(v[i].first - s2_x, 2) + pow(v[i].second - s2_y, 2);
        r2 = 0;

        // 이후, 포함되지 않는 원들 중 나머지 스프링쿨러 좌표와 가장 거리가 먼 경우가 최종 답변의 후보가 된다.
        for(int j=0; j<n; ++j) {
            ll r1_j = pow(v[j].first - s2_x, 2) + pow(v[j].second - s2_y, 2);
            if (r1_j > r1) {
                ll r2_j = pow(v[j].first - s1_x, 2) + pow(v[j].second - s1_y, 2);
                r2 = r2_j > r2 ? r2_j : r2;
            }
        }

        ans = ans > (r1 + r2) ? (r1 + r2) : ans;
    }

    cout<<ans<<endl;
}