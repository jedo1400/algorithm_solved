#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    int n, m, cnt = 0;
    
    cin >> n >> m >> input;
    
    n *= 2, ++n;
    
    for (int i = 0; i <= m-n; ++i) {
        int j;
        for (j = i; i <= i+n; ++j) {
            if ((j-i) % 2 && input[j] == 'O') continue;
            else if (!((j-i) % 2) && input[j] == 'I') continue;
            else break;
        }
        if (j >= i+n) ++cnt;
    } cout << cnt;
}