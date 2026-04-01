#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < 10; i++) {
		int s = n * i;
		cout << n << " * " << i << " = " << s << '\n';
	}
	return 0;
	
}