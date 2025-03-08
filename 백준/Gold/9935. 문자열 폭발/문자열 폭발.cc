#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string haystack, needle;
    cin >> haystack >> needle;

    string result;
    for (auto &i : haystack) {
        result.push_back(i);

        if (result.length() >= needle.length()) {
            int cnt{};

            for (int i = 0; i < needle.length(); ++i)
                if (result[result.length()-i-1] == needle[needle.length()-i-1])
                    ++cnt;

            if (cnt == needle.length())
                for (int i = 0; i < needle.length(); ++i)
                    result.pop_back();
        }
    }

    cout << (result.length() ? result : "FRULA");
}