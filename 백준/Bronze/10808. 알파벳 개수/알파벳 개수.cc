#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short alphabet[26]{0,};
    string input;
    cin >> input;

    for (auto &i : input)
        ++alphabet[i-97];
    
    for (short i = 0; i < 26; ++i)
        cout << alphabet[i] << ' ';
}