#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool cmp(char &a, char &b) {
    int as, bs; // 1 = 소문자, 0 = 대문자, -1 = 숫자
    if (a >= 'a' && a <= 'z') as = 1;
    else if (a >= 'A' && a <= 'Z') as = 0;
    else                      as = -1;

    if (b >= 'a' && b <= 'z') bs = 1;
    else if (b >= 'A' && b <= 'Z') bs = 0;
    else                      bs = -1;    

    if (as ^ bs)
        return as < bs ? 0 : 1;
    return a < b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    while (1) {
        cin >> str;
        if (str.length() == 1 && str[0] == '#')
            return 0;

        sort(str.begin(), str.end(), cmp);
        cout << str << '\n';   
    }
}