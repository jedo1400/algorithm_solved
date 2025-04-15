#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

#define MAX_N 10
#define MAX_M 1000000
#define PII pair<int, int>

int n, m;
bool a[MAX_N][MAX_M]{0,}, b[MAX_N][MAX_M]{0,}; // A 1, B 0
PII ac = {0, 0}, bc = {0, 0};

bool decision() {
	return ac.first + (ac.second ? ac.second-1 : 0)
		   <= bc.first + (bc.second ? bc.second-1 : 0);
}

void swap_card(int ax, int ay, int bx, int by) {
	if (a[ay][ax] ^ b[by][bx]) {
		if (!b[by][bx]) // b의 것과 바꾼 카드가 B인 경우
			n-1 == ay ? ++ac.second : ++ac.first;
		else // b의 것과 바꾼 카드가 A인 경우
			n-1 == ay ? --ac.second : --ac.first;
		
		if (a[ay][ax]) // a의 것과 바꾼 카드가 A인 경우
			n-1 == by ? ++bc.second : ++bc.first;
		else // a의 것과 바꾼 카드가 B인 경우
			n-1 == by ? --bc.second : --bc.first;
	}
	
	swap(a[ay][ax], b[by][bx]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			a[i][j] = c == 'A'; 
			
			if (!a[i][j]) {
				if (i == n-1)
					++ac.second;
				else 
					++ac.first;
			}
		}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			b[i][j] = c == 'A';
			if (b[i][j]) {
				if (i == n-1)
					++bc.second;
				else
					++bc.first;
			}
		}

	cout << (decision() ? "Alice" : "Bob") << '\n';

	int q;
	cin >> q;

	while (q--) {
		static int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		swap_card(c1-1, r1-1, c2-1, r2-1);

		cout << (decision() ? "Alice" : "Bob") << '\n';
	}
}