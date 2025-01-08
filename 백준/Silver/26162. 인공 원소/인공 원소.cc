#include <iostream>
#include <vector>
#define MAX 119

using namespace std;

int main() {
    bool prime[MAX] = {0,};
    for (int i = 2; i < MAX; ++i) prime[i] = 1; // init

    for (int i = 2; i < MAX; ++i)
        if (prime[i])
            for (int j = i+i; j < MAX; j += i)
                prime[j] = 0;

    vector<int> prime_num;
    for (int i = 2; i < MAX; ++i)
        if (prime[i]) prime_num.push_back(i);

    int n;
    cin >> n;

    while (n--) {
        int a;
        cin >> a;

        bool flag{};
        for (auto &i : prime_num) {
            for (auto &j : prime_num) {
                if (i + j > a)
                    break;
                if (i + j == a) {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }

        cout << (flag ? "Yes" : "No") << '\n';
    }
}