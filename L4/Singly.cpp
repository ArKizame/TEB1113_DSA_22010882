//ID:22010882
//Name:Aliff Haiqal
//Lab:G1

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(string name) {
        this->name = name;
        this->next_ptr = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Add new node at the end
    void add_element(string name) {
        Node* new_node = new Node(name);

        if (!head) {
            head = tail = new_node;
            tail->next_ptr = head; // Circular link
        } else {
            tail->next_ptr = new_node;
            tail = new_node;
            tail->next_ptr = head;
        }
    }

    // Display the circular linked list
    void display_list() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->name << " -> ";
            current = current->next_ptr;
        } while (current != head);
        cout << "(head: " << head->name << ")" << endl;
    }

    // Delete node by name
    void delete_by_value(string val) {
        if (!head)
            return;

        // If deleting head node
        if (head->name == val) {
            if (head == tail) {
                delete head;
                head = tail = nullptr;
                return;
            } else {
                Node* temp = head;
                head = head->next_ptr;
                tail->next_ptr = head;
                delete temp;
                return;
            }
        }

        // Traverse to find the node before the target
        Node* current = head;
        while (current->next_ptr != head && current->next_ptr->name != val) {
            current = current->next_ptr;
        }

        // Node found
        if (current->next_ptr->name == val) {
            Node* temp = current->next_ptr;
            current->next_ptr = temp->next_ptr;

            if (temp == tail) {
                tail = current; // Update tail if last node deleted
            }

            delete temp;
        }
    }
};

int main() {
    cout << "Singly Circular Linked List Example" << endl;

    CircularLinkedList list;

    // Add elements
    list.add_element("Ali");
    list.add_element("Ahmed");
    list.add_element("Qaman");
    list.add_element("HackyBoi");

    // Display
    cout << "Initial List: ";
    list.display_list();

    // Delete a node
    list.delete_by_value("Ahmed");
    cout << "After deleting 'Ahmed': ";
    list.display_list();

    return 0;
}

