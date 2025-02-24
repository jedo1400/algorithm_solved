#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string haystack;
    getline(cin, haystack);

    string needle = "What is";
    for (int i{}; i < haystack.length() + needle.length(); ++i) {
        int comp{};
        for (int j{}; j < needle.length(); ++j)
            if (haystack[i+j] == needle[j])
                ++comp;
        
        // 질문 시작
        if (comp == needle.size()) {
            string out = "Forty-two is";
            i += needle.size();

            bool not_question{};
            while (haystack[i] != '?') {
                if (haystack[i] == '.') {
                    not_question = 1;
                    break;
                }
                out += haystack[i], ++i;
            }

            if (not_question) continue;
            
            --i, out.append(".");
            
            cout << out << '\n';
        }

    }
}