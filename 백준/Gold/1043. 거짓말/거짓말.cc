#include <iostream>
#include <vector>

using namespace std;

#define MAX 50

struct disjoint_set {
	vector<int> parent;

	disjoint_set(int size) {
		parent = vector<int>(size);
		for (int i{}; i < size; ++i)
			parent[i] = i;
	}

	int find_parent(int n) {
		if (parent[n] == n) return n;

		return parent[n] = find_parent(parent[n]);
	}

	void union_sets(int n, int m) {
		n = find_parent(n)
		, m = find_parent(m);

		parent[max(n, m)] = min(n, m);
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
	disjoint_set ds(n + 1);

	int o;
	cin >> o;
	while (o--) {
		int p;
		cin >> p;
		ds.parent[p] = 0; // 진실을 아는 사람은 0번 그룹에 속하게 함
	}

	vector<vector<int>> party(m, vector<int>());

	for (auto &i : party) {
		int p;
		cin >> p;
		
		int p_node = MAX;
		while (p--) {
			int q;
			cin >> q;
			i.push_back(q);
		}

		for (int j{}; j < i.size() - 1; ++j)
			ds.union_sets(i[j], i[j+1]);
	}

	int result{};
	for (auto &i : party)
		if (ds.find_parent(i[0]))
			++result;

	cout << result;
}