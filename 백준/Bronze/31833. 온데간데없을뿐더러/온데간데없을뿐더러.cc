#include <iostream>

using namespace std;

#define LL long long

LL intlen(int n) {
	LL len = 1;

	while (n)
		len *= 10, n /= 10;

	return len;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	LL a{}, b{};
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;
		a *= intlen(m), a += m;
	}

	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;
		b *= intlen(m), b += m;
	}
	
	cout << (a > b ? b : a);
}