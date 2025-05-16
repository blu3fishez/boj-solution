#include <iostream>
#include <utility>
using namespace std;

typedef pair<int, int> pii;
int N, M;
pii hole;
int** board;
int dir[] = {-1, 1, -1, 1};

pii tilt_ball(int d, pii ball, pii other) {
    pii next_ball;
    next_ball = ball;
    if(other == hole) {
        other.first = other.second = 0;
    }
    if (d < 2) {
        for (int i = next_ball.first + dir[d]; 0 <= i && i < N;
             i = next_ball.first + dir[d]) {
            if (board[i][next_ball.second] == 2 ||
                other == make_pair(i, next_ball.second)) {
                break;
            }
            next_ball.first += dir[d];
            if (board[next_ball.first][next_ball.second] == 1) break;
        }
    } else {
        for (int i = next_ball.second + dir[d]; 0 <= i && i < M;
             i = next_ball.second + dir[d]) {
            if (board[next_ball.first][i] == 2 ||
                other == make_pair(next_ball.first, i)) {
                break;
            }
            next_ball.second += dir[d];
            if (board[next_ball.first][next_ball.second] == 1) break;
        }
    }

    return next_ball;
}

int solve(pii red, pii blue, int depth, int predir) {
    if(depth > 10) {
        return -1;
    }
    if (blue == hole) {
        return -1;
    }
    if (red == hole) {
        return depth;
    }

    pii next_red, next_blue;
    int tmpdepth, next_depth = -1;
    if (predir != 0) {
        if (red.first < blue.first) {
            next_red = tilt_ball(0, red, blue);
            next_blue = tilt_ball(0, blue, next_red);
        } else {
            next_blue = tilt_ball(0, blue, red);
            next_red = tilt_ball(0, red, next_blue);
        }
        tmpdepth = solve(next_red, next_blue, depth + 1, 0);
        if (next_depth == -1 || (tmpdepth != -1 && next_depth > tmpdepth)) next_depth = tmpdepth;
    }
    if (predir != 1) {
        if (red.first > blue.first) {
            next_red = tilt_ball(1, red, blue);
            next_blue = tilt_ball(1, blue, next_red);
        } else {
            next_blue = tilt_ball(1, blue, red);
            next_red = tilt_ball(1, red, next_blue);
        }
        tmpdepth = solve(next_red, next_blue, depth + 1, 1);
        if (next_depth == -1 || (tmpdepth != -1 && next_depth > tmpdepth)) next_depth = tmpdepth;
    }
    if (predir != 2) {
        if (red.second < blue.second) {
            next_red = tilt_ball(2, red, blue);
            next_blue = tilt_ball(2, blue, next_red);
        } else {
            next_blue = tilt_ball(2, blue, red);
            next_red = tilt_ball(2, red, next_blue);
        }
        tmpdepth = solve(next_red, next_blue, depth + 1, 2);
        if (next_depth == -1 || (tmpdepth != -1 && next_depth > tmpdepth)) next_depth = tmpdepth;
    }
    if (predir != 3) {
        if (red.second > blue.second) {
            next_red = tilt_ball(3, red, blue);
            next_blue = tilt_ball(3, blue, next_red);
        } else {
            next_blue = tilt_ball(3, blue, red);
            next_red = tilt_ball(3, red, next_blue);
        }
        tmpdepth = solve(next_red, next_blue, depth + 1, 3);
        if (next_depth == -1 || (tmpdepth != -1 && next_depth > tmpdepth)) next_depth = tmpdepth;
    }

    return next_depth;
}

int main() {
    string inputbuf;
    cin >> N >> M;
    pii red, blue;

    board = new int*[N];
    for (int i = 0; i < N; ++i) board[i] = new int[M];

    for (int i = 0; i < N; ++i) {
        cin >> inputbuf;
        for (int j = 0; j < M; ++j) {
            switch (inputbuf[j]) {
                case '#':
                    board[i][j] = 2;
                    break;
                case 'R':
                    red.first = i;
                    red.second = j;
                    break;
                case 'B':
                    blue.first = i;
                    blue.second = j;
                    break;
                case 'O':
                    board[i][j] = 1;
                    hole.first = i;
                    hole.second = j;
                    break;
                case '.':
                    break;
            }
        }
    }
    cout << solve(red, blue, 0, -1);

    for (int i = 0; i < N; ++i) delete[] board[i];
    delete[] board;
    return 0;
}