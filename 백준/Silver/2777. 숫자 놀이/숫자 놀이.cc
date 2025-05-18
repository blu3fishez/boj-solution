#include<bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
#define endl '\n'
using namespace std;

int nums[10]; // 2 ~ 9

int main(){
    fastio
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        memset(nums, 0, sizeof(nums));

        if (n == 1) {
            cout<<1<<endl;
            continue;
        }

        for (int i=9; i>=2; --i) {
            while (!(n%i)) {
                nums[i]++;
                n /= i;
            }
        }

        if (n != 1) {
            cout<<-1<<endl;
            continue;
        } 

        int answer = 0;

        for(int i=2; i<=9; ++i) {
            answer += nums[i];
        }

        cout<<answer<<endl;
    }
    

}