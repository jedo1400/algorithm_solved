#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i{}; i < 2; ++i) {
        int t, f, s, p, c;
        cin >> t >> f >> s >> p >> c;
        cout << t*6 + f*3 + s*2 + p + c*2 << '\n';
    }    
}
