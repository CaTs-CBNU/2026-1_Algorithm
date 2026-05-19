#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());

    int answer = 0;
    int left = 0;
    int right = people.size() - 1;

    while (left <= right) {
        if (people[left] + people[right] <= limit) {
            left++;
        }

        right--;
        answer++;
    }

    return answer;
}

int main() {
    vector<int> people = { 70, 50, 80, 50 };
    int limit = 100;

    cout << solution(people, limit);

    return 0;
}