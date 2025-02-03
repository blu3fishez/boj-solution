#include<iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n; cin>>n;
    while(n--) {
        string t;
        cin>>t;
        if (t.length() <= 2) {
            cout<<t<<'\n';
            continue;
        }
        bool rising = true;
        bool canFix = false;
        char largestFix = '0';
        for(int i=1; i<t.length(); ++i) {
            if (rising && t[i-1] > t[i]) {
                rising = false;
            }
            if (!rising) {
                if (!canFix && t[i-1] < t[i]) {
                    t[i] = t[i-1];
                    canFix = true;
                    largestFix = t[i];
                }
                if (canFix) {
                    t[i] = largestFix;
                }
            }
        }
        cout<<t<<'\n';
    }
}