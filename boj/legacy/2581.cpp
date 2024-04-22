#include <iostream>
#include <vector>

using namespace std;

bool isPrime(short input) {
    if (input == 1)
        return 0;
    for (short i = 2; i < input; ++i)
        if (!(input % i))
            return 0;
    return 1;
}

int main() {
    short m, n, firstIndex = -1;
    int result = 0;
    cin >> m >> n;
    vector<bool> array(n+1, 1);
    array[1] = 0;

    for (short i = 2; i <= n; ++i)
        if (array[i] && !isPrime(i))
            for (short j = 1; i*j <= n; ++j)
                array[i*j] = 0;
    
    for (short i = m; i <= n; ++i)
        if (array[i]) {
            result += i;
            if (firstIndex == -1) firstIndex = i;
        }
    if (result > 0)
        cout << result << endl;
    cout << firstIndex;
}