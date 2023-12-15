#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class sll
{
public:
    node* head  = NULL;
    node* head1 = NULL;
    node* head2 = NULL;

    void insert_AT_HEAD(int d)
    {
        node *n1 = new node(d);
        n1->next = head;
        head = n1;
    }

    void insert_AT_END(int d)
    {
        node *n1 = new node(d);
        if (head == NULL)
        {
            head = n1;
        }

        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n1;
    }

    void search()
    {
        int x;
        cout << "Enter the element";
        cin >> x;
        int loc = 1;
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == x)
            {
                cout << "The element is present at loc" <<loc<< endl;
                return;
            }
            temp = temp->next;
            loc++;
        }
        cout << "The element is not present" << endl;
    }

    void reverse()
    {
        node *prev = NULL;
        node *curr = head;
        while (curr != NULL)
        {
            node *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head = prev;
    }

    void merge(){

        int arr1 [] = {12,13,15,17};
        int arr2 [] = {1,2,3,4,5};
        for(int i = 0; i < 4; i++){
            insert_AT_END(arr1[i]);
        }
         for(int i = 0; i < 5; i++){
            insert_AT_END(arr2[i]);
        }
        node* ptr1 = head1;
        node* ptr2 = head2;
        node* dummy = new node(-1);
        node* ptr3 = dummy;
        while(ptr1 != NULL && ptr2 != NULL){
            if(ptr1 -> data <= ptr2 -> data){
                ptr3 -> next = ptr1;
                ptr1 = ptr1 -> next;
                }
            else{
                ptr3 -> next = ptr2;
                ptr2 = ptr2 -> next;
            }
            ptr3 = ptr3->next;
        }

        while(ptr1 != NULL){
            ptr3 -> next = ptr1;
            ptr1 = ptr1 -> next;
            ptr3 = ptr3 -> next;
        }

         while(ptr2 != NULL){
            ptr3 -> next = ptr2;
            ptr2 = ptr2 -> next;
            ptr3 = ptr3 -> next;
        }
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }
};
int main()
{
    sll a1;
    a1.insert_AT_HEAD(4);
    a1.insert_AT_HEAD(3);
    a1.insert_AT_HEAD(2);
    a1.insert_AT_HEAD(1);
    a1.display();
    cout<<endl;
    a1.search();
    cout<<endl;
    a1.reverse();
    a1.merge();
    a1.display();
    return 0;
}