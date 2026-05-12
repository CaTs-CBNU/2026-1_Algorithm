#include <iostream>
#include <vector>
using namespace std;

int answer = 0;

void dfs(const vector<int>& numbers, int target, int index, int current_sum) {

    if (index == numbers.size()) {
        if (current_sum == target) {
            answer++;
        }
        return;
    }
    dfs(numbers, target, index + 1, current_sum + numbers[index]);
    dfs(numbers, target, index + 1, current_sum - numbers[index]);
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    dfs(numbers, target, 0, 0);
    return answer;
}

int main() {
    vector<int> numbers1 = { 1, 1, 1, 1, 1 };
    int target1 = 3;
    cout << solution(numbers1, target1) << endl;

    vector<int> numbers2 = { 4, 1, 2, 1 };
    int target2 = 4;
    cout << solution(numbers2, target2) << endl;

    return 0;
}
