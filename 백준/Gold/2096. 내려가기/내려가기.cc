#include <algorithm>
#include <iostream>
#include <limits.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
	cin >> n;

	vector<int> dp_max(3), dp_min(3);
	cin >> dp_max[0] >> dp_max[1] >> dp_max[2];
	dp_min = dp_max; // init

	vector<int> cur(3), changed(3);
	for (int i = 1; i < n; ++i) {
		cin >> cur[0] >> cur[1] >> cur[2];

		changed[0] = min(cur[0] + dp_min[0], cur[0] + dp_min[1])
		, changed[1] = min(min(cur[1] + dp_min[0], cur[1] + dp_min[1]), cur[1] + dp_min[2])
		, changed[2] = min(cur[2] + dp_min[1], cur[2] + dp_min[2])
		, dp_min = changed

		, changed[0] = max(cur[0] + dp_max[0], cur[0] + dp_max[1])
		, changed[1] = max(max(cur[1] + dp_max[0], cur[1] + dp_max[1]), cur[1] + dp_max[2])
		, changed[2] = max(cur[2] + dp_max[1], cur[2] + dp_max[2])
		, dp_max = changed;
	}

	int rst_min = INT_MAX, rst_max = 0;

	for (auto &i : dp_min) rst_min = min(rst_min, i);
	for (auto &i : dp_max) rst_max = max(rst_max, i);

	cout << rst_max << ' ' << rst_min;
}