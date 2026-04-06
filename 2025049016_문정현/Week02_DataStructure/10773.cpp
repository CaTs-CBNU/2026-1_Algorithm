#include <iostream>
#include <stack>

using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> stack;
    int k;
    int n;
    int sum;
    sum = 0;
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> n;
        if (n != 0) stack.push(n);
        else stack.pop();
    }

    while (!stack.empty()) {
        sum += stack.top();
        stack.pop();
    }

    cout << sum;
}