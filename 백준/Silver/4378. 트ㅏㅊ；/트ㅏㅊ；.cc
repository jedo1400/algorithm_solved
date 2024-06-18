#include <iostream>
#include <string>

using namespace std;

string ctostr(char c) {
    string rst(1, c);
    return rst;
}

int main() {
    string result, qwerty = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

    while (!cin.eof()) {
        string input;
        getline(cin, input);
        
        for (int i = 0; i < input.size(); ++i)
            if (input[i] == 32)
                result.append(" ");
            else
                result.append(ctostr(qwerty[qwerty.find(input[i])-1]));
        result.append("\n");
    }

    cout << result;
}