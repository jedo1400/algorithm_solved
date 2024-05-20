#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n, count_removed = 0;
    string name, filtered;
    map<char, bool> alphabet;
    cin >> n >> name;
    for (short i = 0; i < name.length(); ++i)
        if (!alphabet[name[i]])
            filtered += name[i], alphabet[name[i]] = 1;
        else 
            ++count_removed;
    filtered += to_string(count_removed + 4);
    filtered.insert(0, to_string(n+1906));

    name = "";
    for (short i = filtered.length()-1; i != -1; --i)
        name += filtered[i];
    cout << "smupc_" << name;
}