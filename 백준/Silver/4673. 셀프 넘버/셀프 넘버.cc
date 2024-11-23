#include <iostream>
#include <deque>
#define endl '\n'

using namespace std;

int d(int n) {
	int result = n, len{};
	for (len = 1; n / len >= 10; len *= 10)
		continue;

	while (len) {
		result += n/len
		, n %= len
		, len /= 10;
	}

	return result;
}

int main(){
	deque<bool> mask(10001, 0);

	for (int i = 1; i <= 10000; ++i)
		mask[d(i)] = 1;
	
	for (int i = 1; i <= 10000; ++i)
		if (!mask[i])
			cout << i << endl;
}