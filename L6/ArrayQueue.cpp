//ID:22010882
//Name:Aliff Haiqal
//Lab:G1

#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
    static const int SIZE = 100; // Maximum queue size
    string arr[SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(string name) {
        if (rear == SIZE - 1) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        arr[rear] = name;
        cout << "Enqueued: " << name << endl;
    }

    void dequeue() {
        if (is_empty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    void display_queue() {
        if (is_empty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue (front to rear): ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i];
            if (i != rear) cout << " -> ";
        }
        cout << " -> NULL" << endl;
    }

    bool is_empty() {
        return front == -1 || front > rear;
    }
};

int main() {
    cout << "Queue Using Array" << endl;

    Queue q;

    // Enqueue names as requested
    q.enqueue("Qaman");
    q.enqueue("Hackyboi");
    q.enqueue("Ali");

    q.display_queue();

    q.dequeue();

    cout << "After Dequeue:" << endl;
    q.display_queue();

    return 0;
}
