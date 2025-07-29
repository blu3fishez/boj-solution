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

int main(){
    fastio
    
    while(1) {
        string input; cin>>input;
        
        if (input == "#") break;

        int whites = 0, blacks = 0, greys = 0;

        string guess; cin>>guess;

        vector<bool> masks(input.size(), false);
        int count[26] = {0,};

        for(int i=0; i<input.length(); ++i) {
            count[input[i] - 'A']++;
        }

        for (int i=0; i<guess.length(); ++i) {
            if (guess[i] == input[i]) {
                blacks++;
                masks[i] = true;
                count[input[i] - 'A']--;
            }
        }

        for (int i=0; i<guess.length(); ++i) {
            if (guess[i] == input[i]) continue;
            
            if (i > 0 && guess[i] == input[i-1] && !masks[i-1]) {
                greys++;
                masks[i-1] = true;
                count[input[i-1] - 'A']--;
            }
            else if (i<guess.length() - 1 && guess[i] == input[i + 1] && !masks[i+1]) {
                greys++;
                masks[i+1] = true;
                count[input[i+1] - 'A']--;
            }
        }

        for(int i=0; i<guess.length(); ++i) {
            if (!masks[i] && count[guess[i] - 'A']) {
                whites++;
                count[guess[i] - 'A']--;
            }
        } 

        cout<<guess<<": "<<blacks<<" black, "<<greys<<" grey, "<<whites<<" white"<<endl;
    }
    
    
}