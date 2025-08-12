#include<bits/stdc++.h>
#include <cmath>
#include <math.h>
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
using ld = long double;

const double PI = 4*atan2(1,1);

// 사실상 수식푸는 문제
// 공책을 펴고 수식 계산을 하자

// 두개의 미사일 이동에 관해 수식을 쓰면 바로 해답이 나온다..
// 정확한 T 값을 X 좌표로부터 확인할 수 있고, 이를 통해 도망칠지 말지 (...) 결정 할 수 있다.
// 그 다음엔 알아낸 T로 알파값을 구하면 되는 간단한 문제다.

// 다만 알파값이 문제가 되는데.. 이건 수학 이슈 - atan 값 자체가 파이로 나오기 때문에
// deg로 변환해주어야함...
// 45도 = 파이/4 이므로 위처럼 PI 값을 정의해주고 반대로 파이값으로 나누어주고 180도를 곱해주면 deg 값을 얻을 수 있다.

// 요격 발사 / tk 이해도 조금 어려웠음
// tk 가 발사된 시간이니까, 순수하게 2차함수 그래프만으로 tk 당시의 미사일 위치를 구하고, 그걸 바탕으로 요격 시간대를 정해주어야함.

// 그런데 요격 시간이 0 이후가 아니라면 발사 이전에 요격을 하려고 한다는 거니까 말이 안되므로 이 부분도 예외처리해주면 문제가 풀린다.


int main(){
    fastio

    ld xm, vx, vy, xa, va, tk;

    cin>>xm>>vx>>vy>>xa>>va>>tk;
    cout.precision(10);

    ld yk = vy*tk - 16*tk*tk;
    ld xk = xm + vx*tk;

    if (yk <= 0) {
        cout<<"start running"<<endl;
        return 0;
    }
    
    ld alpha = atan2(yk, xk - xa);

    ld dist = (long double)sqrt((xk - xa)*(xk - xa) + yk*yk);

    ld tl = tk - dist/va;

    if (tl < 0) {
        cout<<"start running"<<endl;
        return 0;
    }

    cout<<tl<<" "<<alpha*180/PI<<endl;
}