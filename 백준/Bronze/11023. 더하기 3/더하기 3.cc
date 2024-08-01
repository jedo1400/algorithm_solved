#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input, buffer;
    int result{};

    getline(cin, input);
    
    for (auto &i : input) {
        if (i == ' ') {
            result += stoi(buffer);
            buffer.clear();
        } else
            buffer += i;
    }

    cout << result + stoi(buffer);
}