#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = NULL;
    }

    // Function to insert a node at the end
    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Function to delete a node from the beginning
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == head) {  // Only one node
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        Node* last = head;
        
        while (last->next != head) {
            last = last->next;
        }
        
        head = head->next;
        last->next = head;
        delete temp;
    }

    // Function to display the circular linked list
    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(Head)\n";
    }
};

int main() {
    CircularLinkedList cll;

    // Insert elements into the circular linked list
    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cll.insert(40);

    // Display the list before deletion
    cout << "Original List: ";
    cll.display();

    // Perform deletion from the beginning
    cll.deleteFromBeginning();

    // Display the list after deletion
    cout << "After deleting first node: ";
    cll.display();

    return 0;
}


