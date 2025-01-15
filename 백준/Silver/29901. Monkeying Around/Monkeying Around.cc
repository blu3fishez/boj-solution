#include<iostream>
#include<vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin>>N>>M;
    int sum, place, x, place_x, highest = 0, ans = 0;
    for (int i=1; i<=N; ++i) {
        sum = 0;
        place = 0;
        x = 0;
        vector<int> v;
        for(int j=0; j<M; ++j) {
            int tmp; cin>>tmp;
            x += tmp;
            v.push_back(tmp);
        }
        x = -x;
        for(int j=0; j<M; ++j) {
            int hop = v[j] ? v[j] : x;
            place += hop;
            sum += place;
        }
        if (!ans || highest < sum) {
            ans = i;
            highest = sum;
        }
    }
    cout<<ans;
}