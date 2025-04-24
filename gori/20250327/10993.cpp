/** 

메모장 

재귀를 쓰는건 맞는 거 같은데, 바깥에서부터 삼각형을 그려나가는 식으로 그려야할 것 같다.

바깥 삼각형의 크기(사실상 높이)는 (대각선의 별 개수) h = 2^n - 1 ye_n / 밑변의 크기 w = 2*h + 1 = xe_n

그러면, 오케이. 0 ~ 2^n - 1 어디서부터 어디까지 그려야할까? 는 xs : w/4 + 2 xe w/2 + w/4+ / ys ye 

여기서 ys, ye 중 윗쪽에 붙는지 안붙는지에 따라서, 1 과 w - 1을 번갈아서 하드코딩하면 됨. 나머지의 길이는

(이전 ys + 이전 ye) /2

중간 위치 : (이전 ys + 이전 ye) /2

*/

#include<bits/stdc++.h>
using namespace std;
#define fastio \
    ios_base::sync_with_stdio(false); \
    cin.tie(0); \
    cout.tie(0);
#define endl '\n'

char cvs[4000][4000];

void draw_tri(int x, int y, int n) {
    if (n == 1) {
        cvs[y][x] = '*';
        return;
    }

    int h = (int)pow(2, n) - 1;
    int w = 2*h - 1;

    for (int i=y; i<y + h; ++i) {
        for(int j=x; j<x + w; ++j) {
            if (!(n%2)) {
                if (j-x == i-y || j-x == w-(i-y)-1 || i-y == 0) cvs[i][j] = '*';
                else cvs[i][j] = ' ';
                
            }

            if (n%2) {
                if (j-x == w/2 + (i - y) || j-x == w/2 - (i - y) || i-y == h-1) cvs[i][j] = '*';
                else cvs[i][j] = ' ';
                
            }
        }
    }
    
    if (!(n%2)) {
        draw_tri(x + h/2 + 1,  y + 1, n-1);
    }
    else {
        draw_tri(x + h/2 + 1, y + h/2, n-1);
    }
}

int main(){
    fastio
    int n; cin>>n;
    if (n == 1) {
        cout<<"*";
        return 0;
    }

    int h = pow(2, n) - 1;
    int w = 2*h - 1;

    draw_tri(0, 0, n);

    for (int i=0; i<h; ++i) {
        for(int j=0; j<w; ++j) {
            if (!(n%2) && j >= w - i) break;
            if (n%2 && j >= h + i) break;
            cout<<cvs[i][j];
        }
        cout<<endl;
    }
    
}