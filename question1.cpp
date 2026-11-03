
#include <iostream>
using namespace std;

// DOUBLY LINKED LIST
class DoublyList {
    struct Node {
        int data;
        Node *prev, *next;

        Node(int x) {
            data = x;
            prev = next = NULL;
        }
    };

    Node *head;

public:
    DoublyList() {
        head = NULL;
    }

    void insert(int x, int choice, int key = 0) {
        Node *n = new Node(x);

        if (choice == 1 || head == NULL) {
            n->next = head;

            if (head != NULL)
                head->prev = n;

            head = n;
            return;
        }

        Node *temp = head;

        if (choice == 2) {
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = n;
            n->prev = temp;
            return;
        }

        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Node not found!\n";
            delete n;
            return;
        }

        if (choice == 3) {
            n->next = temp->next;
            n->prev = temp;

            if (temp->next != NULL)
                temp->next->prev = n;

            temp->next = n;
        }
        else if (choice == 4) {
            n->next = temp;
            n->prev = temp->prev;

            if (temp->prev != NULL)
                temp->prev->next = n;
            else
                head = n;

            temp->prev = n;
        }
    }

    void deleteNode(int x) {
        Node *temp = head;

        while (temp != NULL && temp->data != x)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Node not found!\n";
            return;
        }

        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        delete temp;
        cout << "Node deleted.\n";
    }

    void search(int x) {
        Node *temp = head;
        int pos = 1;

        while (temp != NULL) {
            if (temp->data == x) {
                cout << "Found at position " << pos << endl;
                return;
            }

            temp = temp->next;
            pos++;
        }

        cout << "Node not found!\n";
    }

    void display() {
        Node *temp = head;

        cout << "DLL: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

// CIRCULAR LINKED LIST
class CircularList {
    struct Node {
        int data;
        Node *next;

        Node(int x) {
            data = x;
            next = NULL;
        }
    };

    Node *head;

public:
    CircularList() {
        head = NULL;
    }

    void insert(int x, int choice, int key = 0) {
        Node *n = new Node(x);

        if (head == NULL) {
            head = n;
            n->next = head;
            return;
        }

        Node *temp = head;

        if (choice == 1) {
            while (temp->next != head)
                temp = temp->next;

            n->next = head;
            temp->next = n;
            head = n;
            return;
        }

        if (choice == 2) {
            while (temp->next != head)
                temp = temp->next;

            temp->next = n;
            n->next = head;
            return;
        }

        do {
            if (temp->data == key)
                break;

            temp = temp->next;
        } while (temp != head);

        if (temp->data != key) {
            cout << "Node not found!\n";
            delete n;
            return;
        }

        if (choice == 3) {
            n->next = temp->next;
            temp->next = n;
        }
        else if (choice == 4) {
            if (temp == head) {
                while (temp->next != head)
                    temp = temp->next;

                n->next = head;
                temp->next = n;
                head = n;
            }
            else {
                Node *prev = head;

                while (prev->next != temp)
                    prev = prev->next;

                prev->next = n;
                n->next = temp;
            }
        }
    }

    void deleteNode(int x) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node *temp = head;
        Node *prev = NULL;

        do {
            if (temp->data == x)
                break;

            prev = temp;
            temp = temp->next;
        } while (temp != head);

        if (temp->data != x) {
            cout << "Node not found!\n";
            return;
        }

        if (temp->next == temp) {
            head = NULL;
        }
        else if (temp == head) {
            Node *last = head;

            while (last->next != head)
                last = last->next;

            head = head->next;
            last->next = head;
        }
        else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Node deleted.\n";
    }

    void search(int x) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node *temp = head;
        int pos = 1;

        do {
            if (temp->data == x) {
                cout << "Found at position " << pos << endl;
                return;
            }

            temp = temp->next;
            pos++;
        } while (temp != head);

        cout << "Node not found!\n";
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node *temp = head;

        cout << "CLL: ";

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

int main() {
    DoublyList dll;
    CircularList cll;

    int type, choice, x, key;

    while (true) {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Doubly Linked List\n";
        cout << "2. Circular Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> type;

        if (type == 3)
            break;

        if (type != 1 && type != 2) {
            cout << "Invalid choice!\n";
            continue;
        }

        cout << "\n1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a node\n";
        cout << "4. Insert before a node\n";
        cout << "5. Delete a node\n";
        cout << "6. Search a node\n";
        cout << "7. Display\n";
        cout << "8. Back to main menu\n";

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 8)
            continue;

        switch (choice) {
            case 1:
            case 2:
                cout << "Enter value: ";
                cin >> x;

                if (type == 1)
                    dll.insert(x, choice);
                else
                    cll.insert(x, choice);
                break;

            case 3:
            case 4:
                cout << "Enter specific node: ";
                cin >> key;

                cout << "Enter new value: ";
                cin >> x;

                if (type == 1)
                    dll.insert(x, choice, key);
                else
                    cll.insert(x, choice, key);
                break;

            case 5:
                cout << "Enter value to delete: ";
                cin >> x;

                if (type == 1)
                    dll.deleteNode(x);
                else
                    cll.deleteNode(x);
                break;

            case 6:
                cout << "Enter value to search: ";
                cin >> x;

                if (type == 1)
                    dll.search(x);
                else
                    cll.search(x);
                break;

            case 7:
                if (type == 1)
                    dll.display();
                else
                    cll.display();
                break;

            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}
