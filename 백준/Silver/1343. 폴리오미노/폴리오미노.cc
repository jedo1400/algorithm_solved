#include <iostream>
#include <string>

using namespace std;

short parse(string& input, short idx) {
    short i;
    for (i = idx; i < input.length() && i < idx+4; ++i)
        if (input[i] != 'X') break;
    if (!((i-idx) % 2))
        return i-idx;
    return 0;
}

int main() {
    string input;
    string result;
    short memo;
    getline(cin, input);
    
    for (short i = 0; i < input.length();) {
        if (input[i] == '.') ++i, result.append(".");
        else {
            memo = parse(input, i), i += memo;;
            if (!memo) {
                cout << -1;
                return 0;
            }
            result.append(memo == 2 ? "BB" : "AAAA");
        }
    } cout << result;
}