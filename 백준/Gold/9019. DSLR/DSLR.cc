#include <iostream>
#include <utility>
#include <string>
#include <deque>
#include <queue>
#include <cmath>

using namespace std;

short D(const short &n) {
	return (n * 2) % 10000; // max 19998
}

short S(const short &n) {
	return n-1 < 0 ? 9999 : n-1;
}

short L(const short &n) {
	return n % 1000 * 10 + n / 1000;
}

short R(const short &n) {
	return n % 10 * 1000 + n / 10;
}

string bfs(short a, short b) {
	queue<pair<string, short>> waitlist;
	deque<bool> visited(10000, 0);

	waitlist.push(make_pair("", a));
	visited[a] = 1;

	while (!waitlist.empty()) {
		auto top = waitlist.front();
		short result;
		waitlist.pop();

		if (top.second == b)
			return top.first;
		
		if (!visited[result = D(top.second)]) {
			waitlist.push(make_pair(top.first+'D', result));
			visited[result] = 1;
		}
		if (!visited[result = S(top.second)]) {
			waitlist.push(make_pair(top.first+'S', result));
			visited[result] = 1;
		}
		if (!visited[result = L(top.second)]) {
			waitlist.push(make_pair(top.first+'L', result));
			visited[result] = 1;
		}
		if (!visited[result = R(top.second)]) {
			waitlist.push(make_pair(top.first+'R', result));
			visited[result] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	while (n--) {
		short a, b;
		cin >> a >> b;
		cout << bfs(a, b) << '\n';
	}
}