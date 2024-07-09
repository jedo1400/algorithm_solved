#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    while(!cin.eof()) {
        getline(cin, s);
        while(s.find("BUG") != string::npos)
            s.replace(s.find("BUG"), 3, "");
        cout << s << '\n';
    }
}