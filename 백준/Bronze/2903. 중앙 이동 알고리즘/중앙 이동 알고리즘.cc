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

    // 초기상태 4

    // 2 -> (2 * a_n-1 - 1) 3 -> 5 -> 9

    // 4 -> 9 -> 25 -> 

    // n

    int n; cin>>n;
    long long rt = 2;

    for(int i=0; i<n; ++i) {
        rt += rt-1;
    }

    cout<<(long long)pow(rt, 2)<<endl;
}