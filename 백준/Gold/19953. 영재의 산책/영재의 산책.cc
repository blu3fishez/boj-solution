#include<iostream>
#include<utility>
using namespace std;

// 처음엔 역시 직접 집계해보는게 낫다...

// m의 1의 자리수가 0~9 인 경우 + v의 1의 자리수가 0~9 인경우
// 0 -> 계속 0
// v 1 / m 1 -> 계속 1
// v 1 / m 2 -> 2 -> 4 -> 8 -> 6 -> 2
// v 1 / m 3 -> 3 -> 9 -> 7 -> 1 -> 3
// v 1 / m 4 -> 4 -> 8 -> 6 -> 4
// v 1 / m 5 -> 

// int main() {
//     for (int v=0; v<10; ++v) {
//         for (int m=0; m<10; ++m) {
//             int veloc = v;
//             int cycled = -1;
//             bool shown[10] = { 0,};
//             printf("v %d m %d : ", v, m);
//             for (int i=0; i<10; ++i) {
//                 printf("%d -> ", veloc);
//                 shown[veloc] = true;
//                 veloc *= m;
//                 veloc %= 10;
//                 if (cycled == -1 && shown[veloc]) {
//                     cycled = i + 1;
//                 }
//             }

//             printf("\ncycle makes when %d\n", cycled);
//         }
//     }
// }

int rad[][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

pair<int, int> loc = {0, 0};
int cur_dir = 0;
int veloc;
int m, t;

int veloc_cache[5] = {0,};

int main() {
    cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin>>veloc>>m>>t;

    // 사이클이 이루어지면, 남아있는 t초만큼은 수학식으로 계산
    // 5번 작업 이후에는 무조건 사이클이 생기므로 

    for(int i=0; i<5 && t>0; ++i) {
        loc.first += veloc*rad[cur_dir][0];
        loc.second += veloc*rad[cur_dir][1];

        veloc_cache[cur_dir] = (veloc)%10;
        
        veloc = (veloc*m)%10;
        cur_dir = (cur_dir + 1)%4;
        t--;
    }
    
    for (int i=0; i<4 && t>=4; ++i) {
        loc.first += (t/4)*veloc_cache[cur_dir]*rad[cur_dir][0];
        loc.second += (t/4)*veloc_cache[cur_dir]*rad[cur_dir][1];
        cur_dir = (cur_dir + 1)%4;
    }

    t = t%4;


    while(t > 0) {
        loc.first += veloc*rad[cur_dir][0];
        loc.second += veloc*rad[cur_dir][1];

        veloc = (veloc*m)%10;
        cur_dir = (cur_dir + 1)%4;
        t--;
    }

    cout<<loc.second<<' '<<loc.first<<'\n';
}