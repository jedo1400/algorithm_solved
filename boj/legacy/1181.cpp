#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool compare(string a, string b) {
    if (a.length() < b.length() || (a.length() == b.length() && a < b))
        return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string temp;
    cin >> n;
    map<string, bool> array;

    for (int i = 0; i < n; ++i) {
        cin >> temp;
        array[temp] = 1;
    }

    vector<string> array_2;
    for (auto i : array)
        array_2.push_back(i.first);
    map<string, bool>().swap(array);

    // for (int i = array_2.size()-1; i > 0; --i)
    //     for (int j = 0; j < i; ++j) {
    //         if (array_2[j].length() > array_2[j+1].length()
    //         || (array_2[j].length() == array_2[j+1].length() && array_2[j] > array_2[j+1]))
    //             temp = array_2[j]
    //             , array_2[j] = array_2[j+1]
    //             , array_2[j+1] = temp;
    //     }

    sort(array_2.begin(),array_2.end(),compare);

    for (int i = 0; i < array_2.size(); ++i)
        cout << array_2[i] << '\n';
}