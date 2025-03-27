#include<iostream>
#include<stack>
#include<utility>
using namespace std;

char next_state[] = {
    'A',
    's',
    'k',
    'e',
    'e',
    'p'
};

int main() {
    cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    int n; cin>>n;
    string s; cin>>s;
 
    // int skeep = 0; // s = 1 sk = 2, ske = 3 ...
    stack<pair<char, int>> st;
    
    int zips = 0;
    st.push(make_pair('\0', 0));

    for(int i=0; i<(int)s.length(); ++i) {
        pair<char, int> last = st.top();
        if (s[i] == 's') st.push(make_pair('s', 1));
        else if (next_state[last.second + 1] == s[i]) {
            st.push(make_pair(s[i], last.second + 1));
        }
        else st.push(make_pair(s[i], 0));

        while(st.top().second == 5) {
            pair<char, int> skeep = st.top();
            zips++;
            for(int i=0; i<5; ++i) st.pop(); // s k e e p
            if (st.top().second) {
                st.push(make_pair(next_state[st.top().second], st.top().second + 1));
            }
        }
    }

    cout<<zips;
}

// sssskskeepskeskeepskeep
// sssskskeepskeskeskeepepskeep

// sskeepskeepeep