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
using ll = long long;


// 처음엔 단계를 복잡하게 나눠야할 거 같아서 너무 고민을 많이 했음
// 그냥 닫는게 연속적으로 많아지면 그게 정답인걸 깨달음
// 근데 한가지 간과한게 있음
// 

// (()(())())(()()())
// 이 경우의 정답은 13인데, 12로 나옴 
// 중간에 몇번의 중첩이 생겼는지 기록을 해주지 않아서 생긴 문제임
// 따라서 "이 괄호" 를 닫기 전에 최대 몇중첩이 일어났는지 알아야함 

// 문제는 이 괄호 라는게 언제 닫히는지를 모른다는 문제가 있음
// 닫히는 범위를 체크해서 그 범위 사이에서 닫힌 최대 값을 알아야 그에 걸맞는 괄호레벨을 부여할 수 있음


int main(){
    fastio

    string input;

    getline(cin, input);


    ll ans = 0;
    
    stack<ll> st; // 최대 레벨과 괄호 여는 부분을 넣기


    for(char t : input) {
        if (t == ' ') continue;
        if (t == '(') {
            st.push(-1);
        }
        if (t == ')') {
            ll level = 0;
            
            while(!st.empty() && st.top() != -1) {
                level = level < st.top() ? st.top() : level;
                st.pop();
            }

            ans += (level + 1);
            st.pop(); // -1 제거
            st.push(level + 1);
        }
    }

    cout<<ans<<endl;
}