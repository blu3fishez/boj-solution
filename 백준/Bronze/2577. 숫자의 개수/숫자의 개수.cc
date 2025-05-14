#include<iostream>
using namespace std;

int numeric[10];

int main() {
	int a, b, c; cin >> a >> b >> c;
	a *= b;
	a *= c;

	while (a) {
		numeric[a % 10]++;
		a /= 10;
	}
	for (int t : numeric) {
		cout << t << '\n';
	}
}