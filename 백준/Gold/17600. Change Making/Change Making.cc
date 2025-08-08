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

// 태그 보고 풀었다.
// DP를 생각하지 못했다. 이 문제는 DP로도 해결가능한 문제다.
// N과 조사 범위가 작으므로, 충분히 그리디와 DP를 같이 해보면서 비교하면 되는 문제였다..

int main(){
    fastio

    int n; cin>>n;

    vi v(n);
    vi dp(100001, -1);

    for(int i=0; i<n; ++i) {
        cin>>v[i];
        dp[v[i]] = 1;
    }
    
    bool can_optimize = false;

    for(int i=1; i<=100000; ++i) {

        for(int j=0; j<n; ++j) {
            if (i - v[j] > 0 && dp[i - v[j]] != -1) {
                dp[i] = (dp[i] == -1 || dp[i] > dp[i - v[j]] + 1) ? dp[i - v[j]] + 1 : dp[i];
            }
        }

        int tmp = i;
        int greed_result = 0;

        for(int j=n-1; j>=0; --j) {
            if (tmp < v[j]) continue;
            greed_result += tmp / v[j];
            tmp %= v[j];
        }
        
        if (tmp != 0) continue; // greedy 결과로 나오지 않는 경우.

        if (greed_result > dp[i]) {
            can_optimize = true;
            cout<<i<<endl;
            break;
        }
    }

    if (!can_optimize) cout<<-1<<endl;
}