//id:22010882
//name:muhammad Aliff Haiqal 
//G1


#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    string email;
    string phone;
};

int main() {
    Student students[5];

    for (int i = 0; i < 5; ++i) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> students[i].id;
        cin.ignore();
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "Email: ";
        getline(cin, students[i].email);
        cout << "Phone: ";
        getline(cin, students[i].phone);
    }

    cout << "\nStudent Information:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "----------------------\n";
        cout << "Student " << i + 1 << endl;
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Email: " << students[i].email << endl;
        cout << "Phone: " << students[i].phone << endl;
    }

    return 0;
}
