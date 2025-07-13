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

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(string name) {
        Node* new_node = new Node(name);

        if (!front) {
            front = rear = new_node;
        } else {
            rear->next_ptr = new_node;
            rear = new_node;
        }

        cout << "Enqueued: " << name << endl;
    }

    void dequeue() {
        if (!front) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        Node* temp = front;
        front = front->next_ptr;
        cout << "Dequeued: " << temp->name << endl;
        delete temp;

        if (!front) {
            rear = nullptr; // Queue is now empty
        }
    }

    void display_queue() {
        if (!front) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = front;
        cout << "Queue (front to rear): ";
        while (current != nullptr) {
            cout << current->name;
            current = current->next_ptr;
            if (current != nullptr)
                cout << " <- ";
        }
        cout << " <- NULL" << endl;
    }
};

int main() {
    cout << "Queue Using Linked List" << endl;
    Queue q;

    // Enqueue names
    q.enqueue("Qaman");
    q.enqueue("Hackyboi");
    q.enqueue("Ali");

    // Display queue
    q.display_queue();

    // Dequeue one item
    q.dequeue();

    // Display after dequeue
    cout << "After dequeueing:" << endl;
    q.display_queue();

    return 0;
}
