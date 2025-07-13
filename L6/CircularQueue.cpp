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
            rear->next_ptr = front;
        } else {
            rear->next_ptr = new_node;
            rear = new_node;
            rear->next_ptr = front;
        }

        cout << "Enqueued: " << name << endl;
    }

    void dequeue() {
        if (!front) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        Node* temp = front;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next_ptr;
            rear->next_ptr = front;
        }

        cout << "Dequeued: " << temp->name << endl;
        delete temp;
    }

    void display_queue() {
        if (!front) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = front;
        cout << "Queue (front to rear): ";
        do {
            cout << current->name;
            current = current->next_ptr;
            if (current != front)
                cout << " <- ";
        } while (current != front);
        cout << " <- (circular)" << endl;
    }
};

int main() {
    cout << "Circular Queue Using Linked List" << endl;
    Queue q;

    q.enqueue("Qaman");
    q.enqueue("Hackyboi");
    q.enqueue("Ali");

    q.display_queue();

    q.dequeue();

    cout << "After Dequeue:" << endl;
    q.display_queue();

    return 0;
}
