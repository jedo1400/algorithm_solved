#include <iostream>
#include <utility>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

bool isCompleted(deque<deque<bool>> &array) {
	bool first = array[0][0];
	for (auto &i : array)
		for (auto &j : i)
			if (j != first)
				return 0;
	return 1;
}

short bin_to_int(deque<deque<bool>> &array) {
	short result{}, multi = 256;

	for (auto &i : array)
		for (auto &j : i)
			result += multi*j, multi /= 2;
	
	return result;
}

short bfs(deque<deque<bool>> &array) {
	queue<pair<deque<deque<bool>>, short>> waitlist; // 배열, 이동횟수
	deque<bool> visited(513, 0); // 2^9 000000000~111111111

	waitlist.push(make_pair(array, 0));
	visited[bin_to_int(array)] = 1;

	while (!waitlist.empty()) {
		auto top = waitlist.front();
			if (isCompleted(top.first))
				return top.second;
		waitlist.pop();

		vector<deque<deque<bool>>> modified(4);
		modified[0] = top.first
		, modified[1] = top.first
		, modified[2] = top.first
		, modified[3] = top.first; // 가로, 세로, 대각선(좌), 대각선(우)

		for (short i = 0; i < 3; ++i) {
			modified[2][i][i] = !modified[2][i][i]
			, modified[3][i][2-i] = !modified[3][i][2-i];

			for (short j = 0; j < 3; ++j) {
				modified[0][i][j] = !modified[0][i][j]
				, modified[1][j][i] = !modified[1][j][i];
			}

			for (short j = 0; j < 2; ++j) { // 가로, 세로
				int num = bin_to_int(modified[j]);
				if (!visited[num]) {
					waitlist.push(make_pair(modified[j], top.second+1));
					visited[num] = 1;
				}
			}

			modified[0] = top.first, modified[1] = top.first;
		}

		for (short i = 2; i < 4; ++i) {
			int num = bin_to_int(modified[i]);
			if (!visited[num]) {
				waitlist.push(make_pair(modified[i], top.second+1));
				visited[num] = 1;
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	short t;
	cin >> t;
	deque<deque<bool>> array(3, deque<bool>(3, 0));

	while (t--) {
		for (auto &i : array)
			for (auto &j : i) {
				char tmp;
				cin >> tmp;
				j = (tmp == 'H' ? 0 : 1);
			}
		cout << bfs(array) << '\n';
	}
}