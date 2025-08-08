#include<bits/stdc++.h>
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

typedef struct socks { 
    int left = 0;
    int right = 0;
    int any = 0;
} socks;

int main(){
    fastio

    // unordered_map<string, pii<int (any 수), pii(left 수 / right 수) >>
    unordered_map<string, socks> m;
    int n; cin>>n;
    int mx_cnt = 0;
    for(int i=0; i<n; ++i) {
        string typ, fit; int cnt;
        cin>>typ>>fit>>cnt;

        if (m.find(typ) == m.end()) m.insert({typ, {0, 0, 0}});

        if(fit == "any") m[typ].any += cnt;
        if(fit == "left") m[typ].left += cnt;
        if(fit == "right") m[typ].right += cnt;
    }

    // 총 any 가 1개 이하거나, type 에 대응되는 짝이 하나도 없을 경우 -> impossible
    bool is_impossible = true;
    for(auto mp : m) {
        if (mp.second.any > 1 || (mp.second.left > 0 && mp.second.right > 0)) {
            is_impossible = false;
            break;
        }
    }

    if (is_impossible) {
        cout<<"impossible"<<endl;
        return 0;
    }

    // (N을 순회 돌면서 type 별로 한 종류씩 픽하기)
    // (N번째 양말을 픽할 때 지금까지 골랐던 종류를 바탕으로 짝이 구성이 안되는 경우)
    for(auto mp : m) {
        // any 를 하나라도 픽하게 되면, left, right 를 하나도 픽할 수 없음. 그러니까, type 중에서 left, right 중 큰 것부터 모두 골라야함
        socks type_socks = mp.second;

        int cnt = (type_socks.left > type_socks.right ? type_socks.left : type_socks.right);
        
        // left, right 가 없을 경우 어쩔 수 없이 any 양말 하나를 골라주자.

        if (cnt == 0 && type_socks.any) cnt = 1;

        mx_cnt += cnt;

        // 일단 적어도 이렇게 순회를 돌려도 됨. 왜냐하면 다른 타입은 영향을 안줌.
        // 일단 확실한건, any 는 절대로 2개 이상 픽할 수 없음.
    }
    
    // 짝이 안나오는 상황은 위에서 이미 처리했음.
    // 이 상황에서 하나의 나머지 양말만 픽하면 짝이 완성되므로 + 1을 답으로 출력
    cout<<mx_cnt + 1<<endl;
}