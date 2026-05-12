#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> result;

void hanoi(int n, int from, int to, int via) {
    if (n == 1) {
        result.push_back({ from, to });
        return;
    }
    hanoi(n - 1, from, via, to);
    result.push_back({ from, to });
    hanoi(n - 1, via, to, from);
}

vector<vector<int>> solution(int n) {
    result.clear();
    hanoi(n, 1, 3, 2);
    return result;
}

int main() {
    int n = 2;
    vector<vector<int>> moves = solution(n);

    for (auto& step : moves) {
        cout << "[" << step[0] << ", " << step[1] << "]" << endl;
    }

    return 0;
}
