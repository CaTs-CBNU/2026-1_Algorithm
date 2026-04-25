#include <iostream>
#include <stack>
using namespace std;

int main() {
    int K;
    cin >> K;

    stack<int> st;

    for (int i = 0; i < K; i++) {
        int num;
        cin >> num;

        if (num == 0) {
            st.pop();
        }
        else {
            st.push(num);
        }
    }

    long long sum = 0;

    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }

    cout << sum << '\n';

    return 0;
}