#include <iostream>

using namespace std;

int main() {
    long long n;

    while (1) {
        long long sum = 0;
        short largest = -1;
        for (short i = 0; i < 3; ++i) {
            cin >> n;
            sum += n * n;
            if (n > largest)
                largest = n;
        } sum -= largest * largest;

        if (!sum)
            break;
        cout << (sum == largest*largest ? "right" : "wrong") << '\n';
    }
}