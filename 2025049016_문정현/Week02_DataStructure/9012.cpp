#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        stack<char>stack;
        bool Flag = true;

        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '(') {
                stack.push(s[j]);
            }
            else {
                if (stack.size() == 0) {
                    Flag = false;
                    break;
                }
                stack.pop();
            }
        }

        if (Flag and stack.size() == 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
            
    }
}