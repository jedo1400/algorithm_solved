#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> crain(n);
	
	for (auto &i : crain)
		cin >> i;

	sort(crain.begin(), crain.end(), greater<int>());

	int m;
	cin >> m;
	vector<int> box(m);

	for (auto &i : box)
		cin >> i;

	sort(box.begin(), box.end(), greater<int>());

	if (box[0] > crain[0]) {
		cout << -1;
		return 0;
	}

	int result = 0;

	while (box.size()) {
		++result;

		for (auto &i : crain)
			for (int j = 0; j < box.size(); ++j)
				if (i >= box[j]) {
					box.erase(box.begin() + j);
					break;
				}
	}

	cout << result;
}