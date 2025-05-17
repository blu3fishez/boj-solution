// 단순 BFS 문제입니다.
// 숨바꼭질 2 문제가 더 어렵기 때문에 2를 아신다면 문제없습니다.

#include<iostream>
#include<queue>
#include<utility>
using namespace std;

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> pq;
bool visit[100001];

int main() {
	int N, K; cin >> N >> K;
	pq.push(make_pair(0, K)); // we should to N
	visit[K] = true;
	while (!pq.empty()) {
		int cur = pq.top().second;
		int time = pq.top().first;  pq.pop();
		if (cur == N) {
			cout << time;
			break;
		}
		visit[cur] = true;
		if (!(cur % 2) && !visit[cur / 2]) {
			pq.push(make_pair(time, cur / 2));
		}
		if (!visit[cur + 1]) pq.push(make_pair(time + 1, cur + 1));
		if (cur > 0 && !visit[cur - 1]) pq.push(make_pair(time + 1, cur - 1));
	}
}