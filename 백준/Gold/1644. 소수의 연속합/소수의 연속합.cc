#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 4000000

bool prime[MAX+1]{0,};
vector<int> p;

int two_pointer(int n) {
    int l = 0, r = 1;
    long sum = p[l] + p[r];
    int count = 0;

    while (l < r && r < p.size()) {
        if (sum < n)
            sum += p[++r];

        else if (sum >= n) {
            if (sum == n)
                ++count;
            sum -= p[l++];
        }
    }

    return count + prime[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&prime[2], &prime[MAX+1], 1);

    for (int i = 1; i <= MAX; ++i)
        if (prime[i])
            for (int j = i*2; j <= MAX; j += i)
                prime[j] = 0;

    for (int i = 1; i <= MAX; ++i)
        if (prime[i])
            p.push_back(i);

    int n;
    cin >> n;
    cout << two_pointer(n);
}