#include <iostream>

using namespace std;

const int kDeadPerson = 0;
const int kAlivePerson = 1;

typedef struct Node {
    int value;
    Node* next;
    Node* prev;
}* List;

void PushFront(List& head, List& tail, int value) {
    List front = new Node;
    front->value = value;
    front->next = head;
    front->prev = nullptr;
    if (head != nullptr) {
        head->prev = front;
    }
    head = front;
    if (tail == nullptr) {
        tail = front;
    }
}

void PushBack(List& head, List& tail, int value) {
    List back = new Node;
    back->value = value;
    back->next = nullptr;
    back->prev = tail;
    if (tail != nullptr) {
        tail->next = back;
    }
    tail = back;
    if (head == nullptr) {
        head = back;
    }
}

int PopFront(List& head, List& tail) {
    if (head == nullptr)
        return -1;
    List front = head;
    int value = front->value;
    head = front->next;
    if (head != nullptr)
        head->prev = nullptr;
    else
        tail = nullptr;
    delete front;
    return value;
}

int PopBack(List& head, List& tail) {
    if (tail == nullptr)
        return -1;
    List back = tail;
    int value = back->value;
    tail = back->prev;
    if (tail != nullptr)
        tail->next = nullptr;
    else
        head = nullptr;
    delete back;
    return value;
}

bool Empty(List head) {
    return head == nullptr;
}

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    List head = nullptr, tail = nullptr;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        PushBack(head, tail, a);
    }

    return 0;
}
