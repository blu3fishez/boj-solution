#include<iostream>
#include<stack>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0)->sync_with_stdio(0);
	int n = 1;
	while (true) {
		string buf;
		cin >> buf;
		if (buf[0] == '(' && buf[1] == ')') break;
		stack<char> st;
		int level = 0;
		int max_level = 0;
		for (char t : buf) {
			if (t == '(') {
				level++;
				max_level = level > max_level ? level : max_level;
			}
			if (t == ')') level--;
		}

		int deg = (int) ((max_level+1)%2); // 레벨 1은 AND

		for (char t : buf) {
			if (t == ')') {
				bool result = deg%2;
				while (st.top() != '(') {
					char top = st.top();
					if (top == 'T' && !(deg%2)) {
						result = true;
					}
					else if(top == 'F' && deg%2) {
						result = false;
					}
					st.pop();
				}
				st.pop();
				deg--;
				if (result) st.push('T');
				else st.push('F');
			}
			else {
				if (t == '(') deg++;
				st.push(t);
			}
		}
		if (st.top() == 'F') cout << n << ". false\n";
		else if(st.top() == 'T') cout << n << ". true\n";
		n++;
	}
}