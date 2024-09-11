#include <iostream>
#include <map>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    string url;
    map<string, string> passwords;
    cin >> n >> m;

    while (n--) {
        string pass;
        cin >> url >> pass;
        passwords.insert({url, pass});
    }

    while (m--) {
        cin >> url;
        cout << passwords.find(url) -> second << '\n';
    }
}