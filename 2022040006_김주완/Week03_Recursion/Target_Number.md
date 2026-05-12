# Target Number (C++ DFS 풀이)

## 코드

```cpp
#include <iostream>
#include <vector>
using namespace std;

int answer = 0;

// DFS 함수: 현재 인덱스와 누적 합을 받아 탐색
void dfs(const vector<int>& numbers, int target, int index, int current_sum) {
    // 모든 숫자를 다 사용했을 때
    if (index == numbers.size()) {
        if (current_sum == target) {
            answer++; // 타겟과 같으면 경우의 수 증가
        }
        return;
    }
    // 현재 숫자를 더하는 경우
    dfs(numbers, target, index + 1, current_sum + numbers[index]);
    // 현재 숫자를 빼는 경우
    dfs(numbers, target, index + 1, current_sum - numbers[index]);
}

// solution 함수: DFS를 시작하고 결과 반환
int solution(vector<int> numbers, int target) {
    answer = 0; // 초기화
    dfs(numbers, target, 0, 0); // 인덱스 0부터 시작, 누적합 0
    return answer;
}

int main() {
    vector<int> numbers1 = {1, 1, 1, 1, 1};
    int target1 = 3;
    cout << solution(numbers1, target1) << endl; // 출력: 5

    vector<int> numbers2 = {4, 1, 2, 1};
    int target2 = 4;
    cout << solution(numbers2, target2) << endl; // 출력: 2

    return 0;
}
