#include<iostream>
#include<stack>
#include<utility>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);

    stack<pair<string, string>> st;
    string dir;
    string street;

    cin>>dir;
    st.push({"HOME", dir});

    while (1) {
        cin>>street;

        if (street == "SCHOOL") break;
        
        cin>>dir;
        
        st.push({street, dir});
    }
    
    while(!st.empty()) {
        pair<string, string> stmt = st.top();
        st.pop();
        if (stmt.first == "HOME") {
            cout<<"Turn "<<(stmt.second == "R" ? "LEFT" : "RIGHT")<<" into your HOME.";
        }
        else cout<<"Turn "<<(stmt.second == "R" ? "LEFT" : "RIGHT")<<" onto "<<stmt.first<<" street.\n";
    }
}