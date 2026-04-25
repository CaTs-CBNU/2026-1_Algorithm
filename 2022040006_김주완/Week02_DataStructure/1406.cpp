#include <iostream>
#include <list>
using namespace std;

int main() {

    string s;
    cin >> s;

    list<char> lst(s.begin(), s.end());
    // string s의 문자들을 하나씩 list에 넣음
    // 즉, a b c d가 각각 노드

    auto cursor = lst.end();
    // 처음엔 맨 뒤에 커서 있음: abcd<-

    int M;
    cin >> M;

    while (M--) {                   // 명령을 하나씩 처리

        char cmd;
        cin >> cmd;

        if (cmd == 'L') {
            // 커서를 왼쪽으로 이동

            if (cursor != lst.begin())
                // 커서가 맨 앞이 아니면
                cursor--;
            // 커서를 왼쪽으로 한 칸 이동
        }

        else if (cmd == 'D') {
            // 커서를 오른쪽으로 이동

            if (cursor != lst.end())
                // 커서가 맨 뒤가 아니면
                cursor++;
            // 커서를 오른쪽으로 이동
        }

        else if (cmd == 'B') {
            // 커서 왼쪽 문자 삭제

            if (cursor != lst.begin()) {
                // 맨 앞이면 삭제 불가

                cursor--;
                // 먼저 "삭제할 문자 위치"로 이동

                cursor = lst.erase(cursor);
                // erase는 삭제 후 다음 위치를 반환
            }
        }

        else if (cmd == 'P') {
            // 문자 삽입

            char x;
            cin >> x;

            lst.insert(cursor, x);
            // 커서 앞에 문자 삽입
        }
    }

    for (char c : lst) {
        cout << c;
    }

    return 0;
}