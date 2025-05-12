#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
using namespace std;

int main(){
    fastio
    unsigned long long n;
    cin>>n;
    
    // 1. N의 MSB의 바로 윗자리수 구하기 (그래야 N보다 작은 수 중에서 찾을 수 있으니까..)
    unsigned long long flag = 1;
    while (n >= flag) { // 부등호 조심..
        flag = flag << 1;
    }
    
    // 2. MSB를 포함한 N보다 작은수를 포함하는 작은 플래그 만들기
    flag -= 1;

    // N의 전체 비트와 완전히 다른 비트의 숫자 출력 -> N이 제일 크니까 
    // 왜 N보다 작을 수 밖에 없는가? N의 MSB 에 대응해서 XOR해서 최대가 되려면 다른 수의 N이 가진 MSB비트의 값은 0이 되어야하므로.
    unsigned long long value = n ^ flag;

    // value 가 0이면 N 자체가 XOR 최대값
    if (!value) cout<<1<<endl<<n;
    // 아니면 두개
    else cout<<2<<endl<<value<<endl<<n;
    
}