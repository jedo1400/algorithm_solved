#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k; 
	cin >> n >> k;
	vector<char> result;

	for (int i = 0; i < n; ++i) {
		char m;
		cin >> m;

		while (!result.empty() && m > result.back() && k > 0) {
			result.pop_back();
			--k;
		}

		result.push_back(m);
	}

	// 만약 k개만큼 지우지 못한 경우 -> 배열은 내림차순 정렬되어있으므로 k만큼 덜 출력하면 됨
	for (int i = 0; i < result.size()-k; ++i)
		cout << result[i];
}