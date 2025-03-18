#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n;
	while (cin >> n && n) {
		static int board[1000][1000];
		bool is_homogeneous = 1;

		for (int i{}; i < n; ++i)
			for (int j{}; j < n; ++j)
				cin >> board[i][j];

		if (n >= 2) { 
			for (int i = 1; i < n; ++i) {
				int diff = board[i][0] - board[0][0];
				for (int j = 1; j < n; ++j)
					if (board[i][j] - diff != board[0][j])
						is_homogeneous = 0;
			}
		}

		cout << (is_homogeneous ? "homogeneous" : "not homogeneous") << '\n';
	}
}