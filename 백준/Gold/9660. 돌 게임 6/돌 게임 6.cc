#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long n;
	cin >> n;

	if (!(n % 7) || n % 7 == 2)
		cout << "CY";
	else
		cout << "SK";
}