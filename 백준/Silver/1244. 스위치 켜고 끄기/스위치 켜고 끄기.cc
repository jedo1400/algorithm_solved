#include <iostream>
#include <deque>

using namespace std;

int main() {
    short n, m;
    short sex, num;
    bool tmp;

    cin >> n;
    deque<bool> switches(n+1);
    for (short i = 1; i <= n; ++i)
        cin >> switches[i];

    cin >> m;
    for (short i = 0; i < m; ++i) {
        cin >> sex >> num;
        if (sex == 1)
            for (short i = num; i <= n; i += num)
                switches[i] = !switches[i];
        else {
            short w = 0;
            while (num+w <= n && num-w >= 1 && switches[w+num] == switches[num-w])
                ++w;

            for (short j = num-w+1; j <= num+w-1; ++j)
                switches[j] = !switches[j];
        }
    }

    for (short i = 1; i <= n; ++i) {
        cout << switches[i] << ' ';
        if (!(i % 20))
            cout << '\n';
    }
}