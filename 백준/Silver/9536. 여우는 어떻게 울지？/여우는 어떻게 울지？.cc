#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
using namespace std;

int main(){
    fastio
    int T; cin>>T;
    string line;

    set<string> sounds;

    cin.ignore();

    while(T--) {
        getline(cin, line);
        string animals;
        string token;
        while (animals != "what does the fox say?") {
            getline(cin, animals);
            stringstream animalss(animals);
            animalss >> token;
            animalss >> token;
            animalss >> token;
            sounds.insert(token);
        }
        
        stringstream ss(line);

        while(ss >> token) {
            if (sounds.find(token) != sounds.end()) {
                continue;
            }
            cout<<token<<' ';
        }

    }

}   