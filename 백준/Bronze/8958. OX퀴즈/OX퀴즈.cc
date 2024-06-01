#include <iostream>
#include <string>

using namespace std;

short getScore(const string &s) {
    short combo = 0, score = 0;

    for (short i = 0; i < s.length(); ++i)
        if (s[i] == 'O')
            score += ++combo;
        else
            combo = 0;

    return score;
}

int main() {
    int n;
    cin >> n;

    string s;
    for (short i = 0; i < n; ++i) {
        cin >> s;
        cout << getScore(s) << '\n';
    }
}