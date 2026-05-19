#include <iostream>
#include <string>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int remove = k;

    for (char c : number) {
        while (!answer.empty() && remove > 0 && answer.back() < c) {
            answer.pop_back();
            remove--;
        }
        answer.push_back(c);
    }

    while (remove > 0) {
        answer.pop_back();
        remove--;
    }

    return answer;
}

int main() {
    string number = "4177252841";
    int k = 4;

    cout << solution(number, k);

    return 0;
}