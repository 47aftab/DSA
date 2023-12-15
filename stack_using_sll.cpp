#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

class sll {
public:
    node* head = NULL;

    void push(int d) {
        node* n1 = new node(d);
        n1->next = head;
        head = n1;
    }

    void pop() {
        if (head == NULL) {
            cout << "Empty List!!";
            return;
        }

        node* temp = head;
        head = head->next;
        cout << "Deleted element is : " << temp->data << endl;
        delete temp;
    }

    void search(int num) {
        int loc = 1;
        node* temp = head;
        while (temp->data != num) {
            temp = temp->next;
            loc++;
        }

        cout << "The searched element is: " << temp->data << " at location: " << loc;
    }

    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }

    void peek() {
        if (head == NULL) {
            cout << "List is empty:";
            return;
        }
        cout << "Top element is: " << head->data;
    }

    bool isempt() {
        if (head == NULL) {
            cout << "List is empty! ";
            return true;
        }
        else {
            cout << "Stack is not empty";
            return false;
        }
    }

    void reversed_list() {
        node* prev = NULL;
        node* curr = head;
        while (curr != NULL) {
            node* next1 = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next1;
        }
        head = prev;
    }
};

int main() {
    sll myList;
    int choice, value;

    do {
        cout << "\n----- Singly Linked List Menu -----\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Peek\n";
        cout << "6. Check if Empty\n";
        cout << "7. Reverse List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            myList.push(value);
            break;

        case 2:
            myList.pop();
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            myList.search(value);
            break;

        case 4:
            myList.display();
            break;

        case 5:
            myList.peek();
            break;

        case 6:
            myList.isempt();
            break;

        case 7:
            myList.reversed_list();
            break;

        case 8:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}
