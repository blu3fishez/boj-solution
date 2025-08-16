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

bool is_not_prime[10001];

int main(){
    fastio

    int n, m; cin>>n>>m;

    is_not_prime[1] = true;
    for(int i=2; i*i<=10000; ++i) {
        if (is_not_prime[i]) {
            continue;
        }
        for (int j=i + i; j<=10000; j += i) {
            is_not_prime[j] = true;
        }
    }

    int sum = 0;
    int mn = 0;
    for(int i=n; i<=m; ++i) {
        if (!is_not_prime[i]) {
            if (!sum) mn = i;
            sum += i;
        }
    }

    if (!sum) cout<<-1<<endl;
    else cout<<sum<<endl<<mn<<endl;
}