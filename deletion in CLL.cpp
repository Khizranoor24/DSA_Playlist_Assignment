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

   
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == head) {  
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

    
    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cll.insert(40);

   
    cout << "Original List: ";
    cll.display();

   cll.deleteFromBeginning();

  
    cout << "After deleting first node: ";
    cll.display();

    return 0;
}


