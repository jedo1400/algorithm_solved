#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    short count = 0;

    cin >> input;

    for (short i = 0; i < input.size(); ++i) {
        if ((input[i] == 'c' || input[i] == 's' || input[i] == 'z') && input[i+1] == '=')
            count++, i++;
        else if ((input[i] == 'c' || input[i] == 'd') && input[i+1] == '-')
            count++, i++;
        else if ((input[i] == 'l' || input[i] == 'n') && input[i+1] == 'j')
            count++, i++;
        else if (input[i] == 'd' && input[i+1] == 'z' && input[i+2] == '=')
            count++, i += 2;
        else
            count++;
    } cout << count;
}