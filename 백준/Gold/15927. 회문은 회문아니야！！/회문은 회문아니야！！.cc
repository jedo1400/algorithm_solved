#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	string str;
	cin >> str;

	bool palindrome = 1, single_letter = 1;
	int half = str.length() / 2;

	for (int i{}; i < half; ++i) {
		if (str[i] != str[0] || str[str.length() - 1 - i] != str[0])
			single_letter = 0;
		if (str[i] != str[str.length() - 1 - i])
			palindrome = 0;
	}

	if (str.length() % 2 && str[half] != str[0])
		single_letter = 0;

	// 경우 1: 주어진 문자열이 펠린드롬이 아닌 경우
	if (!palindrome) cout << str.length();
	// 경우 2: 주어진 문자열이 펠린드롬이고 한 글자로만 이루어져있지 않은 경우
	else if (palindrome && !single_letter) cout << str.length()-1;
	// 경우 3: 주어진 문자열이 펠린드롬이고 한 글자로만 이루어진 경우
	else cout << -1;
}