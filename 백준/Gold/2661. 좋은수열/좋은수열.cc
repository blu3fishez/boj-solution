#include<bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
using namespace std;

string answer;

bool backtrack(int n, int i, string answer_cand, string cand) {
    if (n + 1 == i) {
        answer = answer_cand;
        cout<<answer;
        exit(0);
    }

    bool success = true;

    answer_cand += cand;
    
    for(int j=1; j<=i/2; ++j) {
        // n - j to n / n - 2j to n - j
        string a = answer_cand.substr(i-j, j);
        string b = answer_cand.substr(i-2*j, j);
        // cout<<"comparing between "<<a<<" and "<<b<<endl;

        if (a == b) {
            success = false;
            break;
        }
    }

    if (!success) return false;

    if (backtrack(n, i+1, answer_cand, "1")) return true;
    if (backtrack(n, i+1, answer_cand, "2")) return true;
    if (backtrack(n, i+1, answer_cand, "3")) return true;

    return false;
}

int main(){
    fastio
    int n; cin>>n;
    string answer_cand = "";
    backtrack(n, 1, answer_cand, "1");
    backtrack(n, 1, answer_cand, "2");
    backtrack(n, 1, answer_cand, "3");
}