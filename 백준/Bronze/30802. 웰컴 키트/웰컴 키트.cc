#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t, p;
    vector<int> t_size(6);

    cin >> n;
    for (short i = 0; i < 6; ++i)
        cin >> t_size[i];
    cin >> t >> p;

    int min_t = 0;
    for (short i = 0; i < 6; ++i)
        min_t += t_size[i]/t + (t_size[i]%t ? 1 : 0);
    
    cout << min_t << '\n' << n/p << ' ' << n%p;
    return 0;
}