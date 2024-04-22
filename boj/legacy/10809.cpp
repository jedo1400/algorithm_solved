#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    vector<short> count(26, -1);
    for (short i = 0; i < S.size(); ++i)
        if (count[(int)S[i]-97] == -1) count[(int)S[i]-97] = i;
    
    for (short i = 0; i < 26; ++i)
        cout << count[i] << ' ';
}