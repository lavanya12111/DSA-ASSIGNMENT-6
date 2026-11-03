#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *prev, *next;
};

bool isPalindrome(Node *head) {
    if (head == NULL)
        return true;

    Node *left = head;
    Node *right = head;

    while (right->next != NULL)
        right = right->next;

    while (left != right && left->prev != right) {
        if (left->data != right->data)
            return false;

        left = left->next;
        right = right->prev;
    }

    return true;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    Node *head = NULL;
    Node *tail = NULL;

    for (char ch : s) {
        Node *n = new Node{ch, tail, NULL};

        if (head == NULL)
            head = n;
        else
            tail->next = n;

        tail = n;
    }

    if (isPalindrome(head))
        cout << "True";
    else
        cout << "False";

    return 0;
}
