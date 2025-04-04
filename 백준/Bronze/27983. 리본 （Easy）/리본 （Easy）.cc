#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int abs(int &n) {
	return n < 0 ? -n : n;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; // n <= 1000
	cin >> n;
	vector<tuple<int, int, char>> ribbon(n);

	for (auto &i : ribbon)
		cin >> get<0>(i);
	for (auto &i : ribbon)
		cin >> get<1>(i);
	for (auto &i : ribbon)
		cin >> get<2>(i);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (i != j) {
				auto &[xi, li, ci] = ribbon[i];
				auto &[xj, lj, cj] = ribbon[j];
				
				if (abs(xi-xj) <= li+lj && ci != cj) {
					cout << "YES" << '\n' << i+1 << ' ' << j+1;
					return 0;
				}
			}
	
	cout << "NO";
}