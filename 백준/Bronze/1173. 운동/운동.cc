#include<iostream>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
using namespace std;

int main(){
    fastio
    int N, m, M, T, R;
    cin>>N>>m>>M>>T>>R;

    int leastM = m;
    int count = 0;
    int time = 0;
    
    if (m + T > M) {
        // 아예 운동 못하는 경우
        cout<<-1;
        return 0;
    }

    while(count < N) {
        time++;
        if (m + T <= M) {
            m += T;
            count++;
            continue;
        }

        m = max(m - R, leastM);
    }

    cout<<time;
}   