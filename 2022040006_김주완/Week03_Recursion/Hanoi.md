# 하노이 탑 (Tower of Hanoi) - C++ 풀이

## 코드

```cpp
#include <iostream>
#include <vector>
using namespace std;

// 이동 과정을 저장할 벡터
vector<vector<int>> result;

// 하노이 탑 재귀 함수
void hanoi(int n, int from, int to, int via) {
    if (n == 1) {
        // 원판 하나를 목적지로 옮김
        result.push_back({from, to});
        return;
    }
    // 1. 위의 n-1개를 보조 기둥으로 옮김
    hanoi(n - 1, from, via, to);
    // 2. 가장 큰 원판을 목적지로 옮김
    result.push_back({from, to});
    // 3. 보조 기둥에 있던 n-1개를 목적지로 옮김
    hanoi(n - 1, via, to, from);
}

vector<vector<int>> solution(int n) {
    result.clear();
    hanoi(n, 1, 3, 2); // 1번에서 3번으로 옮기기 시작
    return result;
}

int main() {
    int n = 2;
    vector<vector<int>> moves = solution(n);

    for (auto &step : moves) {
        cout << "[" << step[0] << ", " << step[1] << "]" << endl;
    }

    return 0;
}
