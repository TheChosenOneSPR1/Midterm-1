#include <iostream> // This is for the input/output count and cin
using namespace std; // This is so we dont have to type std:: before every cout and cin in the code

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20; // This is the constant 

class DoublyLinkedList { // This is the class for the DoublyLinkedList
private: // This is so that only the class cna use these variables and functions
    struct Node { // This is the struct for the Node which holds the data and the pointers.
        int data; // Stores the value of the node
        Node* prev; // This is the pointer to the previous node so its going backwards
        Node* next; // This is the pointer to the next node so its going forwards
        Node(int val, Node* p = nullptr, Node* n = nullptr) { // This is the Constructor for the Node that sets the data and the pointers
            data = val; // stores the value of the node
            prev = p; // stores the pointer to the previous node
            next = n; // stores the pointer to the next node
        }
    };

    Node* head; // This is the pointer for the first node
    Node* tail; // This is the pointer for the last node

public: // This is so that the code under can be used anywhere
    DoublyLinkedList() { head = nullptr; tail = nullptr; } // This is the Constructor that makes the empty list

    void insert_after(int value, int position) { // This adds a new node after a certain position
        if (position < 0) { // makes sure that it is a postive and not a negative
            cout << "Position must be >= 0." << endl;
            return; // The exit
        }

        Node* newNode = new Node(value); // This makes the new node
        if (!head) { // If the list is empty
            head = tail = newNode; //makes the new node the head and tail
            return;
        }

        Node* temp = head; // this is the start for the head
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next; //makes it go to the right postion

        if (!temp) { // if the position is too far or large
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode; // deletes the new node
            return;
        }

        newNode->next = temp->next; // connects the new node to the middle of the list
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode; // This connect the back link
        else
            tail = newNode; // this updates the tail if it ends 
        temp->next = newNode; // This links the current node to the new node
    }

    void delete_val(int value) { // deletes a node by the value
        if (!head) return; // if there is nothing to delete it is empty

        Node* temp = head; // makes it start at the head
        
        while (temp && temp->data != value) // goes through until you find the node that goes with the value
            temp = temp->next; // goes to the next node

        if (!temp) return; // if nothing is found it just returns

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next; 

        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev; 

        delete temp;
    }

    void delete_pos(int pos) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
    
        if (pos == 1) {
            pop_front();
            return;
        }
    
        Node* temp = head;
    
        for (int i = 1; i < pos; i++){
            if (!temp) {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next;
        }
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }
    
        if (!temp->next) {
            pop_back();
            return;
        }
    
        Node* tempPrev = temp->prev;
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp;
    }

    void push_back(int v) {
        Node* newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(int v) {
        Node* newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void pop_front() {

        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head;

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) { 
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS;  // dummy statement to avoid compiler warning

    
    return 0;
}