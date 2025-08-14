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

    // 상수 컷팅이 될 것 같다? 왜냐면  X Y 중 작은 수가 더 큰 base를 가질거니까.
    // 근데 TLE 라면 이분 탐색을 생각해봐야할듯
    // 일단 완탐은 안된다.

    // tc 가 있는 것도 고려 사항.
    // 값을 찾아내는 과정에서도 
    
    int tc; cin>>tc;

    while(tc--) {
        ll a, b; cin>>a>>b;

        bool swapped = false;
        if (a > b) {
            swapped = true;
            ll tmp = a;
            a = b;
            b = tmp;
        }

        

        for(ll i=11; i<=15000; ++i) {
            // i 와 b 를 바탕으로 N 값을 유추
            ll n = i*i*(b/100) + i*(b/10%10) + (b%10);
            
            ll j_min = i;
            ll j_max = 15000;
            
            bool found = false;
            
            while(j_min <= j_max) {
                // j 와 a를 바탕으로 N 값이 맞는 지 확인
                // 비교를 하는 과정에서, 이분탐색이 가능할 것 같음
                // 15000^2 번 도는 것보다 15000*log(15000) 번 도는게 나을 것 같음

                // cout<<j_min <<" "<<j_max<<endl;

                ll j = (j_min + j_max)/2;
                ll n_guess = j*j*(a/100) + j*(a/10%10) + (a%10);

                if (n == n_guess) {
                    if (swapped) cout<<i<<" "<<j<<endl;
                    else cout<<j<<" "<<i<<endl;
                    found = true;
                }

                if (j_min == j_max) {
                    break;
                }

                if (n < n_guess) {
                    j_max = j - 1;
                }
                else {
                    j_min = j + 1;
                }
            }

            if (found) break;
        }
    }

    
}