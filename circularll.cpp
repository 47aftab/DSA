// #include <iostream>
// using namespace std;
 
// class node{
//     public:
//         int data;
//         node*next;
//         node(int val){
//             data=val;
//             next = NULL;
//         }
// };

// class sll { 
//     public:
//         node*head = NULL;

//         void insert_AT_head(int d){
//             node*n = new node(d);

//             if(head==NULL){
//                 n->next = n;
//                 head = n;
//                 return;
//             }

//             node*temp = head;
//             while(temp->next != head){
//                 temp = temp->next;
//             } 
//             temp->next = n;
//             n->next = head;
//             head = n; 
//         }
//         void insert_AT_tail(int d){
//             if(head == NULL){
//                 insert_AT_head(d);
//                 return;
//             }
//             node*n = new node(d);
//             node*temp = head;
//             while(temp->next != head){
//                 temp = temp->next;
//             }
//             temp->next = n;
//             n->next = head;
//         }

//         void display(){
//             node* temp = head;
//             do{
//                 cout<< temp->data <<" ";
//                 temp = temp->next; 
//             }
//             while(temp != head);
//         }
// };
// int main() {
//     sll a1;
//     a1.insert_AT_head(4);
//     a1.insert_AT_head(3);
//     a1.insert_AT_head(2);
//     a1.insert_AT_head(1);
//     a1.display();
//     return 0;
// }



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

    void insert_AT_head(int d) {
        node* n = new node(d);

        if (head == NULL) {
            n->next = n;
            head = n;
            return;
        }

        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
        head = n;
    }

    void insert_AT_tail(int d) {
        if (head == NULL) {
            insert_AT_head(d);
            return;
        }
        node* n = new node(d);
        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
    }

    void insert_at_position(int d, int position) {
        if (position <= 0) {
            cout << "Invalid position" << endl;
            return;
        }

        if (position == 1) {
            insert_AT_head(d);
            return;
        }

        node* n = new node(d);
        node* temp = head;
        for (int i = 1; i < position - 1; i++) {
            if (temp == NULL) {
                cout << "Position out of bounds" << endl;
                return;
            }
            temp = temp->next;
        }

        n->next = temp->next;
        temp->next = n;
    }

    void delete_at_position(int position) {
        if (position <= 0 || head == NULL) {
            cout << "Invalid position" << endl;
            return;
        }

        node* temp = head;
        if (position == 1) {
            head = temp->next;
            delete temp;
            return;
        }

        for (int i = 1; i < position - 1; i++) {
            if (temp == NULL || temp->next == head) {
                cout << "Position out of bounds" << endl;
                return;
            }
            temp = temp->next;
        }

        node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void display() {
        node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    sll a1;
    int choice, data, position;

    do {
        cout << "\n1. Insert at head";
        cout << "\n2. Insert at tail";
        cout << "\n3. Insert at any position";
        cout << "\n4. Delete at any position";
        cout << "\n5. Display";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                a1.insert_AT_head(data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                a1.insert_AT_tail(data);
                break;
            case 3:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter position: ";
                cin >> position;
                a1.insert_at_position(data, position);
                break;
            case 4:
                cout << "Enter position: ";
                cin >> position;
                a1.delete_at_position(position);
                break;
            case 5:
                cout << "Linked List: ";
                a1.display();
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 0);

    return 0;
}
