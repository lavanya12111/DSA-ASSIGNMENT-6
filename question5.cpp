#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

bool isCircular(Node *head) {
    if (head == NULL)
        return false;

    Node *temp = head->next;

    while (temp != NULL && temp != head)
        temp = temp->next;

    return temp == head;
}

int main() {
    Node *head = new Node{2, NULL};
    Node *second = new Node{4, NULL};
    Node *third = new Node{6, NULL};
    Node *fourth = new Node{7, NULL};
    Node *fifth = new Node{5, NULL};

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Make list circular
    fifth->next = head;

    if (isCircular(head))
        cout << "True";
    else
        cout << "False";

    return 0;
}
