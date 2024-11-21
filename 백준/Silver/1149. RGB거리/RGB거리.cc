#include <algorithm>
#include <iostream>
#include <limits.h>

using namespace std;

int main() {
    int n;
	cin >> n;

	vector<int> before(3), cur(3);
	cin >> before[0] >> before[1] >> before[2];
	for (int i = 1; i < n; ++i) {
		cin >> cur[0] >> cur[1] >> cur[2];
		cur[0] = min(cur[0] + before[1], cur[0] + before[2])
		, cur[1] = min(cur[1] + before[0], cur[1] + before[2])
		, cur[2] = min(cur[2] + before[0], cur[2] + before[1]);
		before = cur;
	}

	int min = INT_MAX;
	for (auto &i : cur)
		if (i < min)
			min = i;
	cout << min;
}