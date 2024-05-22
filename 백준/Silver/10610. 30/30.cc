#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool cmp(const char &a, const char &b) {
    return a > b;
}

bool isComposable(const string &m) {
    int sum = 0;
    for (auto &iter : m)
        sum += iter-48;
    if (!(sum % 3) && !(m[m.length()-1]-48))
        return 1;
    return 0;
}

string thirty(string m) {
    sort(m.begin(), m.end(), cmp);
    if (isComposable(m))
        return m;
    else 
        return "-1";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;
    cout << thirty(input);
}