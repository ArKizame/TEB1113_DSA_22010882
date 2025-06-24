#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node(string data) {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add(string data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    void deleteByValue(string value) {
        if (!head) return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (!head) tail = nullptr;
            return;
        }

        Node* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }

        if (current->next) {
            Node* temp = current->next;
            current->next = temp->next;
            if (temp == tail) tail = current;
            delete temp;
        }
    }

    Node* getHead() {
        return head;
    }
};

int main() {
    LinkedList list;

    list.add("Ali");
    list.add("Bob");
    list.add("Cade");

    cout << "Before deletion: ";
    list.display();

    list.deleteByValue("Bob");

    cout << "After deletion: ";
    list.display();

    Node* current = list.getHead();
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
