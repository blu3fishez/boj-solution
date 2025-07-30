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
    
    int tc; cin>>tc;

    while(tc--) {
        int n; cin>>n;
        int mx_sub = -987654321;
        vi arr = vi(n);
        vvi presum = vvi(n, vi(n, 0));

        for(int i=0; i<n; ++i) {
            cin>>arr[i];
            presum[i][i] = arr[i];
            mx_sub = mx_sub < arr[i] ? arr[i] : mx_sub;

            for(int j=0; j<i; ++j) {
                presum[j][i] = presum[j][i-1] + arr[i];
                mx_sub = mx_sub < presum[j][i] ? presum[j][i] : mx_sub;
            }
        }

        cout<<mx_sub<<endl;

        
    }
}