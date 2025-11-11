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

int main() {
    fastio
    
    map<char, pair<int, int>> m = {
        {'a', {1, 0}},
        {'b', {2, 4}},
        {'c', {2, 2}},
        {'d', {1, 2}},
        {'e', {0, 2}},
        {'f', {1, 3}},
        {'g', {1, 4}},
        {'h', {1, 5}},
        {'i', {0, 7}},
        {'j', {1, 6}},
        {'k', {1, 7}},
        {'l', {1, 8}},
        {'m', {2, 6}},
        {'n', {2, 5}},
        {'o', {0, 8}},
        {'p', {0, 9}},
        {'q', {0, 0}},
        {'r', {0, 3}},
        {'s', {1, 1}},
        {'t', {0, 4}},
        {'u', {0, 6}},
        {'v', {2, 3}},
        {'w', {0, 1}},
        {'x', {2, 1}},
        {'y', {0, 5}},
        {'z', {2, 0}}
    };

    pair<int, int> left_hand, right_hand;

    char l, r; cin>>l>>r;
    left_hand = m[l];
    right_hand = m[r];

    string t; cin>>t;

    int ans = 0;

    for (char c : t) {
        if (m[c].second >= 5 || (m[c].second == 4 && m[c].first == 2)) {
            ans += abs(right_hand.first - m[c].first) + abs(right_hand.second - m[c].second);
            right_hand = m[c];
        }
        else {
            ans += abs(left_hand.first - m[c].first) + abs(left_hand.second - m[c].second);
            left_hand = m[c];
        }
        ans++;
    }
    cout<<ans<<'\n';
}