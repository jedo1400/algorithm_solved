#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n;
    cin >> n;
    vector<short> queqe(n), wait;
    for (short i = n-1; i >= 0; --i)
        cin >> queqe[i];
    
    short current = 1;
    for (short i = 0; i < n; ++i) {
        if (current != queqe.back())
            wait.push_back(queqe.back());
        else {
            ++current;
            while (wait.size() && wait.back() == current) {
                wait.pop_back();
                ++current;
            }
        }
        queqe.pop_back();
    }

    while (wait.size() && wait.back() == current) {
        wait.pop_back();
        ++current;
    }
    cout << (!wait.size() ? "Nice" : "Sad");

}