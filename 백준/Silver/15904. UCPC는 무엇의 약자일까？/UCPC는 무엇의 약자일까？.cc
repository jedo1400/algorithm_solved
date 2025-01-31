#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string haystack;
    getline(cin, haystack);

    int ptr{};
    string needle = "UCPC";
    for (auto &i : haystack)
        if (needle[ptr] == i)
            ++ptr;
    
    cout << (ptr == 4 ? "I love UCPC" : "I hate UCPC");
}