#include <iostream>
#define MAX_DIGIT 4 // 1~1000

using namespace std;

int main() {
    short n, result{};
    cin >> n;

    for (short i = 1; i <= n; ++i) {
        if (i < 100)
            ++result;

        else { // i가 3자리 이상이면
            short p[MAX_DIGIT], size{}; 
            for (short j = i; j; j /= 10, ++size)
                p[size] = j % 10;

            short interval = p[1] - p[0];
            bool flag{};
            for (short j = 2; j < size; ++j)
                if (p[j] != p[j-1] + interval) {
                    flag = 1;
                    break;
                }
            
            if (!flag)
                ++result;
        }
    }

    cout << result;
}