#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char a;
    cin >> a;
    if (a == 'n' || a == 'N')
        cout << "Naver D2";
    else
        cout << "Naver Whale";
}