#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<tuple<int, int, int>> bus(n), result;

	for (auto &[s, e, c] : bus)
		cin >> s >> e >> c;
	
	sort(bus.begin(), bus.end());

	int cs = get<0>(bus[0])
		, ce = get<1>(bus[0])
		, min_c = get<2>(bus[0]);

	for (int i = 1; i < n; ++i) {
		auto &[s, e, c] = bus[i];

		if (s <= ce) // 이전 노선과 겹치는 경우
			min_c = min(min_c, c), ce = max(ce, e);
		else {
			result.push_back({cs, ce, min_c});
			cs = s, ce = e, min_c = c;
		}
	}

	result.push_back({cs, ce, min_c});

	cout << result.size() << '\n';
	for (auto &[s, e, c] : result)
		cout << s << ' ' << e << ' ' << c << '\n';
}