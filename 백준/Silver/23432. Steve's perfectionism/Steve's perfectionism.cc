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
    
    int n; cin>>n;

    vi arr = vi(n);

    for(int i=0; i<n; ++i) {
        cin>>arr[i];
        if (i == 0) continue;

        // 작으면, 이것보다 더 큰 수를 순회하면서 n의 배수를 찾기
        if (arr[i-1] < arr[i]) continue;

        arr[i] = arr[i-1] - (arr[i-1]%arr[i]) + arr[i];
        
        
    }

    for(int i=0; i<n; ++i) cout<<arr[i]<<' ';
    cout<<endl;
}