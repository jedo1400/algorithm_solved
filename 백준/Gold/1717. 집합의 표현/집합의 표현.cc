#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct disjoint_set {
	vector<int> parent;

	disjoint_set(int size) {
		parent = vector<int>(size+1);
		for (int i{}; i < parent.size(); ++i) // init
			parent[i] = i;
	}

	int find_parent(int n) {
		if (parent[n] == n)
			return n;

		return parent[n] = find_parent(parent[n]); // 경로압축
	}

	void union_sets(int n, int m) {
		n = find_parent(n)
		, m = find_parent(m);

		if (n != m) // 서로 부모가 다르면
			parent[n] = m; // 병합
	}

	bool is_union(int n, int m) {
		return find_parent(n) == find_parent(m);
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	disjoint_set ds(n);

	while (m--) {
		bool cmd;
		int p1, p2;
		cin >> cmd >> p1 >> p2;

		if (cmd)
			cout << (ds.is_union(p1, p2) ? "YES" : "NO") << '\n';
		else
			ds.union_sets(p1, p2);
	}
}