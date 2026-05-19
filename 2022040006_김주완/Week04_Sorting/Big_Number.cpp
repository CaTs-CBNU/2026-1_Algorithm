#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> arr;

    for (int num : numbers) {
        arr.push_back(to_string(num));
    }

    sort(arr.begin(), arr.end(), compare);

    string answer = "";

    for (string s : arr) {
        answer += s;
    }

    if (answer[0] == '0') {
        return "0";
    }

    return answer;
}

int main() {
    vector<int> numbers = { 3, 30, 34, 5, 9 };

    cout << solution(numbers);

    return 0;
}