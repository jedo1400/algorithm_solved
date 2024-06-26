#include <iostream>
#include <string>

using namespace std;

char caesar(char c, char key) {
    char encrypted = c-(key-96);
    return (encrypted < 97 ? encrypted + 26 : encrypted);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input, key, cipher;
    getline(cin, input);
    cin >> key;

    for (short i = 0; i < input.length(); ++i) {
        if (input[i] == ' ')
            cipher += ' ';
        else
            cipher += caesar(input[i], key[i%key.length()]);
    }

    cout << cipher;
}