#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);

    int n; cin>>n;
    int cursor = 1;
    stack<int> st;
    vector<int> v; 

    for(int i=1; i<=n; ++i) {
        int t; cin>>t;
        
        while (t >= cursor) {   
            st.push(cursor++);
            v.push_back(1);
        }

        if (!st.empty() && st.top() == t) {
            st.pop();
            v.push_back(0);
            continue;
        }

        cout<<"NO";
        return 0;
    }

    for (int t : v) {
        cout<<(t == 1 ? '+' : '-')<<'\n';
    }
}