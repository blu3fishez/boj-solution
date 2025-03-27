#include<iostream>
#include<stack>
using namespace std;

int main() {
    cout.tie(0); cin.tie(0)->sync_with_stdio(0);
    int n = 1;
    while(1) {
        string line; cin>>line;
        bool is_and = false;
        stack<char> st;
        if (line == "()") {
            return 0;
        }

        int depth = 0;
        int height = 0;

        for(char t : line) {
            if (t == '(') depth++;
            if (t == ')') depth--;
            height = depth > height ? depth : height;
        }
        
        if (!(height%2)) is_and = !is_and;

        for(char t : line) {
            if (t == '(') {
                is_and = !is_and;
                st.push('('); // (
                continue;
            }
            
            if (t == ')') {
                bool buf = is_and;
                while(!st.empty() && st.top() != '(') {
                    char top = st.top();
                    st.pop();
                    buf = is_and ? (buf && top == 'T') : (buf || top == 'T');
                }
                is_and = !is_and;
                st.pop();
                st.push(buf ? 'T' : 'F');
            }
            else st.push(t);
        }
        
        cout<<n++<<". "<< (st.top() == 'T' ? "true" : "false") << '\n';
    }
}