#include <iostream>
#include <deque>

using namespace std;

void append(deque<bool> &array, int &size) {
    int cnt{};
    while (array[cnt])
        array[cnt++] = 0, --size;
    ++size, array[cnt] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, size{};
    cin >> n >> k;
    deque<bool> exist(25, 0); // 2^24 = 16,777,216

    for (int i{}; i < n; ++i) {
        append(exist, size);
    }

    int extra_bottles{};
    while (size > k) {
        append(exist, size);
        ++extra_bottles;
    }
    
    cout << extra_bottles;
}