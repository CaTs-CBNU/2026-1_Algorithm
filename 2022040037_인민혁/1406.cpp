#include <iostream>
#include <string>

using namespace std;

struct Node {
  char value;
  Node* prev;
  Node* next;

  Node(char value, Node* prev = nullptr, Node* next = nullptr) : value(value), prev(prev), next(next) {}
};
class Editor {
  Node* head;
  Node* tail;
  Node* curr;
public:
  Editor() {
    head = new Node('\0');
    tail = new Node('\0');
    head->next = tail;
    tail->prev = head;
    curr = tail;
  }
  ~Editor() {
    Node* current = head;
    while(current != nullptr) {
      Node* nextNode = current->next;
      delete current;
      current = nextNode;
    }
  }
  void insert(char value);
  void remove();
  void cursor_left();
  void cursor_right();
  void display();
};
void Editor::insert(char value) {
  Node* newNode = new Node(value, curr->prev, curr);

  curr->prev->next = newNode;
  curr->prev = newNode;
}
void Editor::remove() {
  if (curr->prev == head) return;
  Node* temp = curr->prev;
  temp->prev->next = curr;
  curr->prev = temp->prev;
  delete temp;
}
void Editor::cursor_left() {
  if (curr->prev == head) return;
  curr = curr->prev;
}
void Editor::cursor_right() {
  if (curr == tail) return;
  curr = curr->next;
}
void Editor::display() {
  Node* current = head->next;
  while (current != tail) {
    cout << current->value;
    current = current->next;
  }
  cout << '\n';
}

int main() {
  Editor e;
  string str;
  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    e.insert(str[i]);
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char cmd;
    cin >> cmd;
    if (cmd == 'P') {
      char ch;
      cin >> ch;
      e.insert(ch);
    } else if (cmd == 'L') {
      e.cursor_left();
    } else if (cmd == 'D') {
      e.cursor_right();
    } else if (cmd == 'B') {
      e.remove();
    } else {
      break;
    }
  }
  e.display();
}