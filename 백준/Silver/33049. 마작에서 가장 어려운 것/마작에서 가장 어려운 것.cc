#include<iostream>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
using namespace std;

int main(){
    fastio
    int want_3, want_4, anything;
    int team_3 = 0, team_4 = 0;
    cin>>want_3>>want_4>>anything;
    while(want_3%3) {
        if (!anything) {
            cout<<-1;
            return 0;
        }
        anything--;
        want_3++;
    }
    team_3 = want_3/3;
    while(want_4%4) {
        if (!anything) {
            cout<<-1;
            return 0;
        }
        anything--;
        want_4++;
    }
    team_4 = want_4/4;
    
    int any_3 = 0;
    int any_4 = 0;
    while(anything) {
        if (anything < 4) {
            if (!any_4) {
                if (anything == 3) {
                    any_3++;
                    anything -= 3;
                    continue;
                }
                cout<<-1;
                return 0;
            }
            any_4--; any_3++;
            anything++;
            continue;
        }
       
        any_4++;
        anything -= 4;
    }

    team_3 += any_3;
    team_4 += any_4;

    cout<<team_3<<' '<<team_4;
}