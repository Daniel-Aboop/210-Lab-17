#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
Node * deletenode(Node * head, int entry);
Node * insertnode(Node * head, int entry);
Node * deletelist(Node * head);



int main() {
    Node *head = nullptr;
    
    int entry;
    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);

    // deleting a node
    
    cout << "Which node to delete? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    head=deletenode(head,entry);
    output(head);

    // insert a node
    Node * current = head;
    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;
    head=insertnode(head,entry);
    output(head);

    // deleting the linked list
    head=deletelist(head);
    output(head);
    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}
Node * deletenode(Node * head,int entry){
 // traverse that many times and delete that node
    Node * current = head;
    Node *prev = nullptr;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0){
            prev=current;
            current = current->next;
        }
        else {
            prev = prev->next;
            current = current->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    return head;
}
Node * insertnode(Node * head, int entry){
    Node * prev=nullptr;
    Node * current=head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            prev=current;
        else {
            prev = prev->next;
            current = current->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    if(prev){
        prev->next=newnode;
    }
    else{
        head=newnode;
    }
    return head;
}
Node * deletelist(Node * head){

    Node * current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    return head;
}