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

class Stack {
private:
    Node* top;
    int max_size;
    int current_size;

public:
    Stack(int size = 10) {
        top = nullptr;
        max_size = size;
        current_size = 0;
    }

    bool isFull() {
        return current_size == max_size;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(string name) {
        if (isFull()) {
            cout << "Stack is full. Cannot push '" << name << "'." << endl;
            return;
        }

        Node* new_node = new Node(name);
        new_node->next_ptr = top;
        top = new_node;
        current_size++;

        cout << "Pushed: " << name << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }

        Node* temp = top;
        cout << "Popped: " << temp->name << endl;
        top = top->next_ptr;
        delete temp;
        current_size--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to peek." << endl;
        } else {
            cout << "Top of stack: " << top->name << endl;
        }
    }

    void display_stack() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* current = top;
        cout << "Stack (top to bottom): ";
        while (current != nullptr) {
            cout << current->name;
            current = current->next_ptr;
            if (current != nullptr)
                cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    cout << "Stack Using Linked List" << endl;

    Stack stack(4); 

    stack.push("Qaman");
    stack.push("Hackyboi");
    stack.push("Ali");
    
    stack.peek();

    stack.display_stack();

    stack.pop();

    stack.peek();
    stack.display_stack();

    return 0;
}
