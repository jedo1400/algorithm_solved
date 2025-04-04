#include <iostream>

using namespace std;

bool including(int num, int &k) {
	if (num < 10 && !k) // 만약 num이 한자리 수 인데 k가 0인 경우
		return 1; // 앞 자리 수가 제로필 되어있으므로 무조건 참

	while (num) {
		if (num % 10 == k)
			return 1;
		num /= 10;
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	int result = 0;
	// 24 * 59 * 59 * 2 = 167,088
	for (int h = 0; h <= n; ++h) {
		bool hs = including(h, k);

		for (int m = 0; m < 60; ++m) {
			bool ms = including(m, k);

			for (int s = 0; s < 60; ++s) {
				if (hs || ms || including(s, k))
					++result;
			}
		}
	}

	cout << result;
}