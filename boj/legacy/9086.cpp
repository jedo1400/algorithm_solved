#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    short t;
    cin >> t;

    vector<string> input(t);
    for (short i = 0; i < t; ++i)
        cin >> input[i];
    
    for (short i = 0; i < t; ++i)
        cout << input[i][0] << input[i][input[i].size()-1] << endl;
}
