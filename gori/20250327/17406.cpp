/** 

메모장 

5 6 1
1 2 3 4 5 6
7 8 9 10 11 12 
13 14 15 16 17 18
19 20 21 22 23 24
25 26 27 28 29 30
3 3 2

돌리면 이렇게 되어야함
07 01 02 03 04 06
13 14 08 09 05 12 
19 20 15 10 11 18 (14)
25 21 22 16 17 24
26 27 28 29 23 30
*/

#include<bits/stdc++.h>
using namespace std;
#define fastio \
    ios_base::sync_with_stdio(false); \
    cin.tie(0); \
    cout.tie(0);
#define endl '\n'

int n, m, k;
int arr[50][50];
bool visited[6];
int rcs[6][3]; // rcs[][0] = r rcs[][1] = c rcs[][2] = s

int solve(int arr_cur[][50], int left) {

    int arr_after[50][50];

    int mx = -1;
    
    for(int i=0; i<n; ++i) {
        int sum = 0;
        for(int j=0; j<m; ++j) {
            sum += arr_cur[i][j];
            arr_after[i][j] = arr_cur[i][j];
            cout<<arr_after[i][j]<<' ';
        }
        cout<<endl;
        mx = mx < sum ? sum : mx;
    }

    if (left == 0) return mx; // 배열을 돌리지 않아야하므로

    int changed_mx = 0;
    for(int i=0; i<k; ++i) {
        if (visited[i]) continue;
        int r = rcs[i][0] - 1;
        int c = rcs[i][1] - 1;
        int s = rcs[i][2];
        // change
        for(int l=1; l<=c; ++l) {
            int left_up = arr_after[r-l][c-l];
            int right_up = arr_after[r-l][c+l];
            int left_down = arr_after[r+l][c-l];
            int right_down = arr_after[r+l][c+l];

            for (int j=-l+1; j<=l; ++j) {
                arr_after[r-l][c+j] = arr_after[r-j][c+j-1];
            }

            arr_after[r-l+1][c+l] = right_up;
            for (int j=-l+2; j<=l; ++j) {
                arr_after[r-l][c+l]= arr_after[r-l][c+l];
            }

            arr_after[r+l][c+l-1] = right_down;
            for(int j=l-2; j>=-l; --j) {
                arr_after[r+l][c+j] = arr_after[r+l][c+j+1];
            }

            arr_after[r+l-1][c-l] = left_down;
            for(int j=l-2; j>=-l; --j) {
                arr_after[r+j][c-l] = arr_after[r+j+1][c-l];
            }
        }
        visited[i] = true;
        solve(arr_after, left - 1);
        visited[i] = false;
    }

    return mx > changed_mx ? mx : changed_mx;
}

int main() {
    fastio;
    cin>>n>>m>>k;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<k; ++i) {
        cin>>rcs[i][0]>>rcs[i][1]>>rcs[i][2];
    }

    cout<<solve(arr, k)<<endl;
}