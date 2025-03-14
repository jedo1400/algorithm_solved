#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#define INF (unsigned int)(1 << 31) - 1

bool installRouter(vector<int> &house, int router, int dist) {
	int cnt = 1 // 원점에 가장 가까운 집에는 설치하는게 무조건 이득
		, before = house[0];
	
	int stack{};
	for (int i = 1; i < house.size(); ++i) {
		stack += house[i]-before;

		if (stack >= dist) {
			stack = 0;
			if (++cnt == router)
				return 1;
		}
			
		before = house[i];
	}

	return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, c;
	cin >> n >> c;
	vector<int> house(n);

	int l = 1, r{};
	for (auto &i : house) {
		cin >> i;
		r = max(r, i);
	}

	sort(house.begin(), house.end());

	while (l <= r) {
		int mid = (l + r) / 2;
		if (installRouter(house, c, mid))
			l = mid+1;
		else
			r = mid-1;
	}

	cout << r;
}