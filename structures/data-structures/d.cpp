#include <iostream>
#include <string>

using namespace std;

struct Node {
    int priority;
    string name;
    Node* next;
};

typedef Node* Queue;

void Insert(int priority, string name, Queue& head) {
    Queue task = new Node;
    task->priority = priority;
    task->name = name;
    task->next = nullptr;

    if (head == nullptr || head->priority > priority) {
        task->next = head;
        head = task;
    } else {
        Queue current = head;
        while (current->next != nullptr && current->next->priority <= priority) {
            current = current->next;
        }
        task->next = current->next;
        current->next = task;
    }
}

Queue Pop(Queue& head) {
    Queue task = head;
    head = head->next;
    return task;
}

int main() {
    int n;
    cin >> n;

    Queue head = nullptr;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "IN") {
            int priority;
            string name;
            cin >> priority >> name;

            Insert(priority, name, head);
        } else if (command == "OUT") {
            Queue task = Pop(head);
            cout << task->priority << ' ' << task->name << endl;

            delete task;
        }
    }

    return 0;
}
