#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

bool isAlreadyExistWord(const string &word, const unordered_map<string, bool> &words) {
    for (short i = 0; i < word.length(); ++i) {
        short j = i;
        string comp;
        do {
            ++j
            , j %= word.length()
            , comp += word[j];
        } while (j != i);
        if (words.find(comp) != words.end())
            return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n, result{};
    cin >> n;
    unordered_map<string, bool> words;
    
    while (n--) {
        string word;
        cin >> word;

        if (!isAlreadyExistWord(word, words)) {
            ++result;
            words.insert({word, 1});
        }
    }

    cout << result;
}