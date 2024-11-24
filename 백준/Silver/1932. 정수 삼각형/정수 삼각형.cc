#include <algorithm>
#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> before(n), cur(n);
	cin >> before[0];

	if (n == 1) {
		cout << before[0];
		return 0;
	}

	for (int i = 1; i < n; ++i) {
		for (int j{}; j <= i; ++j)
			cin >> cur[j];

		for (int j{}; j <= i; ++j) {
			int left = j-1, right = j;
			if (left >= 0 && right < i)
				cur[j] = max(before[left] + cur[j], before[right] + cur[j]);
			else if (!j)
				cur[j] = cur[j] + before[right];
			else
				cur[j] = cur[j] + before[left];
		}

		before = cur;
	}

	int largest{};
	for (auto &i : cur)
		largest = max(largest, i);
	
	cout << largest;
}