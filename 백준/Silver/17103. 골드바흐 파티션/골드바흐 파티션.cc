#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;

int getCase(deque<bool> &prime, int m) {
    int result = 0;
    for (int i = 2; i < m; ++i) {
        if (prime[m-i] && prime[i]) {
            ++result;
            if (m - i == i) // 8-4 = 4
                ++result;
        }
    }
    return result/2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    deque<bool> prime(1000001, 1);
    prime[1] = 0;

    for (int i = 2; i * i <= 1000000; ++i)
        if (prime[i]) 
            for (int j = i*2; j <= 1000000; j += i)
                prime[j] = 0;
    
    int t;
    cin >> t;
    vector<int> array(t);

    for (int i = 0; i < t; ++i)
        cin >> array[i];
    
    for (int i = 0; i < t; ++i)
        cout << getCase(prime, array[i]) << '\n';
}