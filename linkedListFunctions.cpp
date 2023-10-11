#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void traverse() {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
} 

void insertBeginning(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteBeginning() {
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        cout << "List is empty. Cannot delete." << endl;
    }
}

void deleteEnd() {
    if (head != nullptr) {
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    } else {
        cout << "List is empty. Cannot delete." << endl;
    }
}

void updateBeginning(int newValue) {
    if (head != nullptr) {
        head->data = newValue;
    } else {
        cout << "List is empty. Cannot update." << endl;
    }
}

void updateEnd(int newValue) {
    if (head != nullptr) {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->data = newValue;
    } else {
        cout << "List is empty. Cannot update." << endl;
    }
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    
    traverse();

    insertBeginning(5);
    insertBeginning(15);

    traverse();

    deleteBeginning();
    deleteEnd();

    traverse();

    updateBeginning(25);
    updateEnd(40);

    traverse();

    return 0;
}
 
