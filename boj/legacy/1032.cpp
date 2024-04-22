#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n;
    cin >> n;

    string input, mask;
    for (short i = 0; i < n; ++i) {
        cin >> input;
        if (i == 0) mask = input;
        else
            for (int j = 0; j < input.length(); ++j)
                if (input[j] != mask[j])
                    mask[j] = '?';
    }

    cout << mask;

}