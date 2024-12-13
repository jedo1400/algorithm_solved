#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, largest{};
    cin >> n;
    vector<int> result;

    for (int i = 1; i <= n; ++i) {
        static int j;
        vector<int> array = { n, i };

        while ((j = array[array.size()-2] - array.back()) >= 0)
            array.push_back(j);

        if (array.size() > largest)
            result = array, largest = array.size();
    }

    cout << largest << '\n';
    for (auto &i : result)
        cout << i << ' ';
}