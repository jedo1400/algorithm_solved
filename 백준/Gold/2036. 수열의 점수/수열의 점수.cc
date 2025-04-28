#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define LL long long

int _abs(int &n) {
	return n < 0 ? -n : n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> pos, neg;

	while (n--) {
		int m;
		cin >> m;
		(m > 0 ? pos : neg).push_back(m);
	}

	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end(), greater<int>());

	LL result = 0;
	
	while (!pos.empty()) {
		if (pos.size() == 1)
			result += pos.back();

		else { // 2개 이상인 경우
			auto a = pos.end()-1
				, b = pos.end()-2;

			if (*a == 1 || *b == 1) // 두 수중 하나가 1이면 곱하는 것보다 서로 더한 값이 더 큼
				result += *a + *b;
			else
				result += (LL)*a * *b;

			pos.pop_back();
		}

		pos.pop_back();
	}

	while (!neg.empty()) {
		if (neg.size() == 1)
			result += neg.back();
		
		else {
			result += (LL)neg.back() * *(neg.end()-2);
			neg.pop_back();
		}

		neg.pop_back();		
	}

	cout << result;
}