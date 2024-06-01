#include <iostream>

using namespace std;

void printComponents(int n) {
    int len;
    short cnt[10] = {0,};
    for (len = 1; len*10 <= n; len *= 10)
        continue;
    
    for (int i = len; i >= 1; i /= 10) {
        ++cnt[n/i];
        n %= i;
    }

    for (short i = 0; i <= 9; ++i)
        cout << cnt[i] << '\n';
    return;
}

int main() {
    short n = 0;
    int multi;
    for (short i = 0; i < 3; ++i) {
        cin >> n;
        if (i == 0) multi = n;
        else multi *= n;
    } 
    printComponents(multi);
}