#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

int sizeDLL(Node *head) {
    int count = 0;

    while (head != NULL) {
        count++;
        head = head->next;
    }

    return count;
}

int sizeCLL(Node *head) {
    if (head == NULL)
        return 0;

    int count = 0;
    Node *temp = head;

    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

int main() {
    // Doubly Linked List: 10 <-> 20 <-> 30

    Node *d1 = new Node{10, NULL, NULL};
    Node *d2 = new Node{20, d1, NULL};
    Node *d3 = new Node{30, d2, NULL};

    d1->next = d2;
    d2->next = d3;

    // Circular Linked List: 5 -> 15 -> 25 -> back to 5

    Node *c1 = new Node{5, NULL, NULL};
    Node *c2 = new Node{15, NULL, NULL};
    Node *c3 = new Node{25, NULL, NULL};

    c1->next = c2;
    c2->next = c3;
    c3->next = c1;

    cout << "Size of DLL: " << sizeDLL(d1) << endl;
    cout << "Size of CLL: " << sizeCLL(c1) << endl;

    return 0;
}
