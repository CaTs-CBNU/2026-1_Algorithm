#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int results[100];

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        results[i] = a + b;
    }

    for (int i = 0; i < n; i++) {
        cout << results[i] << '\n';
    }

    return 0;
}