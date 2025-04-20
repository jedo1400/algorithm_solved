#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 200

int find(int* parent, int n) {
	return parent[n] = parent[n] == n ? n : find(parent, parent[n]);
}

void merge(int* parent, int a, int b) {
	a = find(parent, a)
	, b = find(parent, b);
	
	if (a != b)
		parent[a] = parent[b];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int parent[MAX + 1];
	for (int i = 0; i <= MAX; ++i) // init
		parent[i] = i;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			bool o;
			cin >> o;

			if (o)
				merge(parent, i, j);
		}

	bool result = 1;
	int cenancestor;
	for (int i = 0; i < m; ++i) {
		int o;
		cin >> o;

		if (!i)
			cenancestor = find(parent, o);
		else if (result && find(parent, o) != cenancestor)
			result = 0;
	}

	cout << (result ? "YES" : "NO");
}