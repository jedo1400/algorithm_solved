#include <iostream>
#include <map>
#include <string>

using namespace std;

bool isGroup(string input) {
    map<char, bool> used;
    char previousLetter;
    for (short i = 0; i < input.size(); ++i) {
        if (!used[input[i]])
            used[input[i]] = 1;
        else if (used[input[i]] && previousLetter != input[i])
            return 0;
        previousLetter = input[i];
    } return 1;
}

int main() {
    short line, count = 0;
    string input;
    cin >> line;
    for (short i = 0; i < line; ++i) {
        cin >> input;
        count += (isGroup(input) ? 1 : 0);
    } cout << count;
}