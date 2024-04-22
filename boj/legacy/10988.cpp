#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;

    if (input.size() == 1) {
        cout << 1;
        return 0;
    }
    
    for (short i = 0; i < input.size()/2 - (input.size()%2 == 0 ? 0 : 1); ++i)
        if (input[i] != input[input.size()-1-i]) {
            cout << 0;
            return 0;
        }
    cout << 1;
}