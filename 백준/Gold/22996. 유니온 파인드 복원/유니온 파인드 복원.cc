#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

void restore(vector<vector<int>> &v, vector<pair<int, int>> &r, int n) {
	// 좌표압축에 영향을 받지 않도록 역순으로, 루트 노드와 가까운 노드부터 병합하기
	for (auto &i : v[n]) {
		r.push_back({i, n});

		if (!v[i].empty())
			restore(v, r, i);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q, m; // 원소 개수, 질의 개수, 2번 질의 개수
	cin >> n >> q;
	vector<vector<int>> con(n+1);
	vector<int> root;
	
	for (int i = 1; i <= n; ++i) {
		int t;
		cin >> t;
		if (t == i) // 자기 자신이 부모라면
			root.push_back(i);
		else
			con[t].push_back(i);
	}

	cin >> m;
	queue<int> q2; // 2번 질의
	for (int i = 0; i < m; ++i) {
		int t;
		cin >> t;
		q2.push(t);
	}

	cout << n << ' ' << q << '\n';

	while (!q2.empty()) {
		cout << "2 " << q2.front() << '\n';
		q2.pop();
	}

	vector<pair<int, int>> q1;
	for (auto &i : root)
		restore(con, q1, i);

	q -= m + q1.size();

	while (q--) // 질문이 아직 남았다면 아무거나 출력해서 질문 개수 채우기
		cout << "1 1 1\n"; // 1번 질의에서 u와 v는 같을 수 있다.
	
	while (!q1.empty()) {
		cout << "1 " << q1.back().first << ' ' << q1.back().second << '\n';
		q1.pop_back();
	}
}