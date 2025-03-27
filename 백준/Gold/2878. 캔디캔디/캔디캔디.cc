#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define ULL long long

int decision(vector<int> &v, int candy, int mid, bool apply = 0) {
	int i = v.size();

	while (--i >= 0 && v[i] >= mid) {
		candy -= v[i] - mid;
		if (apply)
			v[i] = mid;

		if (candy < 0) // 남은 사탕이 없어지면
			return 0;
	}
	
	if (apply)
		return candy;
	return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
	cin >> m >> n;
	vector<int> v(n);

	for (auto &i : v)
		cin >> i;

	sort(v.begin(), v.end());

	ULL l = 0, r = v.back();
	while (l <= r) {
		ULL mid = (l + r) / 2;

		if (decision(v, m, mid))
			r = mid - 1;
		else
			l = mid + 1;
	}

	int left = decision(v, m, l, 1); // 가장 분노가 큰 사람의 분노가 가장 작게 만들기, 남은 사탕 개수 받아와서 v의 끝->시작 탐색하며 빼주기
	
	for (int i = v.size()-1; left; --i)
		--v[i], --left;

	ULL result{};
	for (auto &i : v)
		result += (ULL)i * i; // unsigned 타입은 오버플로우 시 최대값(2^64 - 1)을 넘으면 0부터 다시 시작
	
	cout << result;
}