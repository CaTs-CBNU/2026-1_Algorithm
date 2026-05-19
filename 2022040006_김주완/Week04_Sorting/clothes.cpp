#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    vector<int> realLost;
    vector<int> realReserve;

    for (int l : lost) {
        if (find(reserve.begin(), reserve.end(), l) == reserve.end()) {
            realLost.push_back(l);
        }
    }

    for (int r : reserve) {
        if (find(lost.begin(), lost.end(), r) == lost.end()) {
            realReserve.push_back(r);
        }
    }

    int answer = n - realLost.size();

    for (int r : realReserve) {
        for (int i = 0; i < realLost.size(); i++) {
            if (realLost[i] == r - 1 || realLost[i] == r + 1) {
                answer++;
                realLost[i] = -1;
                break;
            }
        }
    }

    return answer;
}

int main() {
    vector<int> lost = { 2, 4 };
    vector<int> reserve = { 1, 3, 5 };

    cout << solution(5, lost, reserve);

    return 0;
}