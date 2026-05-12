\# 하노이 탑 (Tower of Hanoi) - C++ 풀이



\## 코드



```cpp

\#include <iostream>

\#include <vector>

using namespace std;



// 이동 과정을 저장할 벡터

vector<vector<int>> result;



// 하노이 탑 재귀 함수

void hanoi(int n, int from, int to, int via) {

&#x20;   if (n == 1) {

&#x20;       // 원판 하나를 목적지로 옮김

&#x20;       result.push\_back({from, to});

&#x20;       return;

&#x20;   }

&#x20;   // 1. 위의 n-1개를 보조 기둥으로 옮김

&#x20;   hanoi(n - 1, from, via, to);

&#x20;   // 2. 가장 큰 원판을 목적지로 옮김

&#x20;   result.push\_back({from, to});

&#x20;   // 3. 보조 기둥에 있던 n-1개를 목적지로 옮김

&#x20;   hanoi(n - 1, via, to, from);

}



vector<vector<int>> solution(int n) {

&#x20;   result.clear();

&#x20;   hanoi(n, 1, 3, 2); // 1번에서 3번으로 옮기기 시작

&#x20;   return result;

}



int main() {

&#x20;   int n = 2;

&#x20;   vector<vector<int>> moves = solution(n);



&#x20;   for (auto \&step : moves) {

&#x20;       cout << "\[" << step\[0] << ", " << step\[1] << "]" << endl;

&#x20;   }



&#x20;   return 0;

}



