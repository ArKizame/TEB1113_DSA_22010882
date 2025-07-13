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
    Node* prev_ptr;

    Node(string name) {
        this->name = name;
        this->next_ptr = nullptr;
        this->prev_ptr = nullptr;
    }
};

class DoublyCircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyCircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Add new node at the end
    void add_element(string name) {
        Node* new_node = new Node(name);

        if (!head) {
            head = tail = new_node;
            new_node->next_ptr = new_node;
            new_node->prev_ptr = new_node;
        } else {
            new_node->next_ptr = head;
            new_node->prev_ptr = tail;
            tail->next_ptr = new_node;
            head->prev_ptr = new_node;
            tail = new_node;
        }
    }

    // Display list forward
    void display_forward() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->name << " <-> ";
            current = current->next_ptr;
        } while (current != head);
        cout << "(back to head: " << head->name << ")" << endl;
    }

    // Display list backward
    void display_backward() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = tail;
        do {
            cout << current->name << " <-> ";
            current = current->prev_ptr;
        } while (current != tail);
        cout << "(back to tail: " << tail->name << ")" << endl;
    }

    // Delete node by name
    void delete_by_value(string val) {
        if (!head) return;

        Node* current = head;
        Node* to_delete = nullptr;

        do {
            if (current->name == val) {
                to_delete = current;
                break;
            }
            current = current->next_ptr;
        } while (current != head);

        if (!to_delete) return;

        // Only one node
        if (head == tail && head->name == val) {
            delete head;
            head = tail = nullptr;
            return;
        }

        // Remove links
        to_delete->prev_ptr->next_ptr = to_delete->next_ptr;
        to_delete->next_ptr->prev_ptr = to_delete->prev_ptr;

        // Update head or tail if needed
        if (to_delete == head) head = to_delete->next_ptr;
        if (to_delete == tail) tail = to_delete->prev_ptr;

        delete to_delete;
    }
};

int main() {
    cout << "Doubly Circular Linked List" << endl;
    DoublyCircularLinkedList list;

    list.add_element("Qaman");
    list.add_element("Hackyboi");
    list.add_element("Ali");

    cout << "Forward display: ";
    list.display_forward();

    cout << "Backward display: ";
    list.display_backward();

    list.delete_by_value("Hackyboi");
    cout << "After deleting 'Hackyboi': ";
    list.display_forward();

    return 0;
}
