#include <iostream>
#include <string>

using namespace std;

int main() {
    int count = 1;
    string input;
    getline(cin, input);

    if (input[0] == ' ' && input.size() == 1) {
        cout << 0;
        return 0;
    }
    
    for (int i = 0; i < input.size(); ++i)
        if (input[i] == ' ' && (i != 0 && i != input.size()-1))
            ++count;
    cout << count;
}