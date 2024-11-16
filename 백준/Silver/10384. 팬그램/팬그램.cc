#include <iostream>
#include <string>

using namespace std;

int isPangram(string &str) {
    bool flag[3] = { 1, 1, 1 }; // 1, 2, 3
    int alphabet[26]{0,};

    for (auto &i : str)
        if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122))
            ++alphabet[i >= 97 ? i - 97 : i - 65];

    for (int i{}; i < 26; ++i) {
        // cout << alphabet[i] << ' ';
        if (alphabet[i] < 3) flag[2] = 0;
        if (alphabet[i] < 2) flag[1] = 0;
        if (alphabet[i] < 1) flag[0] = 0;
    }

    for (int i = 2; i >= 0; --i)
        if (flag[i])
            return i+1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();
    
    for (int i = 1; i <= n; ++i) {
        string str;
        getline(cin, str);
        cout << "Case " << i;
        switch (isPangram(str)) {
            case 3: cout << ": Triple pangram!!!";
                break;
            case 2: cout << ": Double pangram!!";
                break;
            case 1: cout << ": Pangram!";
                break;
            case 0: cout << ": Not a pangram";
        }

        cout << '\n';
    }
}