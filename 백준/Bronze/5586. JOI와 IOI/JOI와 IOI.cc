#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	string needle[2] = { "JOI", "IOI" };
	int ptr[2] = { 0, 0 };

	int JOI = 0, IOI = 0;
	for (auto &i : str) {
		if (i == needle[0][ptr[0]]) { // 만약 JOI의 요소를 포함하고 있다면
			++ptr[0];
			if (ptr[0] == needle[0].length())
				++JOI, ptr[0] = 0;
		}
		else
			ptr[0] = (i == needle[0][0] ? 1 : 0); // 아니라면 초기화

		if (i == needle[1][ptr[1]]) {
			++ptr[1];
			if (ptr[1] == needle[1].length())
				++IOI, ptr[1] = 1;
		}
		else
			ptr[1] = (i == needle[1][0] ? 1 : 0);
	}

	cout << JOI << ' ' << IOI;
}