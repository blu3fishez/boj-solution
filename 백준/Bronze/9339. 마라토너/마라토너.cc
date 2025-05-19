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


bool targets[1000001];

int main(){
    fastio

    int t; cin>>t;
    while(t--) {
        int k; cin>>k;
        memset(targets, 0, sizeof(targets));
        
        for(int i=0; i<k; ++i) {
            int tmp; cin>>tmp;
            targets[tmp] = true;
        }

        int m; cin>>m;
        int counts = 0;
        int least_person = -1, least_hr = -1, least_min = -1;

        for(int i=0; i<m; ++i) {
            int person, hr, min;
            
            cin>>person>>hr>>min;
            if (hr == -1) continue;

            if (hr > 6 || (hr == 6 && min > 0)) {
                continue;
            }

            if (targets[person]) counts++;
            
            if (targets[person] && (least_person == -1 || (least_hr > hr || (least_hr == hr  && least_min > min)))) {
                least_person = person;
                least_hr = hr;
                least_min = min;
                continue;
            }
        }

        cout<<least_person<<' '<<counts<<endl;
    }
}