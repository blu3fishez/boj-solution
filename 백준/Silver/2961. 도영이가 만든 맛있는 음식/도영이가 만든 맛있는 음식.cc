#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
#define endl '\n'
using namespace std;

long long min_diff = -1;
long long bitter[10], sour[10];

void get_min(int index, long long sour_sum, long long bitter_sum, int n) {
    if (sour_sum > 0 && (min_diff == -1 || min_diff > llabs(sour_sum - bitter_sum))) {
        min_diff = llabs(sour_sum - bitter_sum);
    }
    
    // index : 조합 탐색을 위한 현재 index.

    for (int i=index + 1; i<n; ++i) {
        get_min(i, sour_sum, bitter_sum, n); // 고르지 않음
        get_min(i, sour_sum == 0 ? sour[i] : sour_sum * sour[i], bitter_sum + bitter[i], n); // 고름
    }
}

int main(){
    fastio
    
    int n; cin>>n;
    

    for(int i=0; i<n; ++i) {
        cin>>sour[i]>>bitter[i];
    }
    
    get_min(-1, 0, 0, n);

    cout<<min_diff;
}