#include <iostream>
#include <array>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    array<int, 12> array = {0, 1, 2, 4};
	for (short i = 4; i <= 11; ++i)
		array[i] = array[i-1] + array[i-2] + array[i-3];
	int n;
	cin >> n;
	while (n--) {
		short m;
		cin >> m;
		cout << array[m] << '\n';
	}

}