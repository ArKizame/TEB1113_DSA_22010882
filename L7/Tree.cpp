//ID:22010882
//Name:Aliff Haiqal
//Lab:G1

#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string name) {
        this->name = name;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    void add_root(string name) {
        if (root == nullptr) {
            root = new Node(name);
            cout << "Added root: " << name << endl;
        } else {
            cout << "Root already exists." << endl;
        }
    }

    void add_left(Node* parent, string name) {
        if (parent->left == nullptr) {
            parent->left = new Node(name);
            cout << "Added left child " << name << " to " << parent->name << endl;
        } else {
            cout << "Left child already exists for " << parent->name << endl;
        }
    }

    void add_right(Node* parent, string name) {
        if (parent->right == nullptr) {
            parent->right = new Node(name);
            cout << "Added right child " << name << " to " << parent->name << endl;
        } else {
            cout << "Right child already exists for " << parent->name << endl;
        }
    }

    Node* find(Node* current, string name) {
        if (!current) return nullptr;
        if (current->name == name) return current;

        Node* leftResult = find(current->left, name);
        if (leftResult) return leftResult;

        return find(current->right, name);
    }

    void add_left_by_name(string parentName, string childName) {
        Node* parent = find(root, parentName);
        if (parent) {
            add_left(parent, childName);
        } else {
            cout << "Parent " << parentName << " not found." << endl;
        }
    }

    void add_right_by_name(string parentName, string childName) {
        Node* parent = find(root, parentName);
        if (parent) {
            add_right(parent, childName);
        } else {
            cout << "Parent " << parentName << " not found." << endl;
        }
    }

    void display(Node* node, int depth = 0) {
        if (!node) return;
        display(node->right, depth + 1);
        for (int i = 0; i < depth; i++) cout << "  ";
        cout << node->name << endl;
        display(node->left, depth + 1);
    }
};

int main() {
    Tree tree;

    
    tree.add_root("Qaman");
    tree.add_left_by_name("Qaman", "Hackyboi");
    tree.add_right_by_name("Qaman", "Ali");

   
    tree.add_left_by_name("Hackyboi", "LeftChild1");
    tree.add_right_by_name("Hackyboi", "RightChild1");

    
    cout << "\nTree Structure:\n";
    tree.display(tree.root);

    return 0;
}
