#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string result;

    while(!cin.eof()) {
        getline(cin, result);
        cout << result << endl;
    }
}