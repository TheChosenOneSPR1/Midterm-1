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

        if (temp->prev) // if there is a node before it it delets
            temp->prev->next = temp->next; // link it
        else
            head = temp->next; // if its the first node it updates the head and moves it forward

        if (temp->next)
            temp->next->prev = temp->prev; // link it
        else
            tail = temp->prev; // if its the last node it updates the tail and moves it back

        delete temp; // this just deletes the node
    }

    void delete_pos(int pos) { // this deletes the node by its position on the list
        if (!head) { // this checks if the list is empty
            cout << "List is empty." << endl;
            return;
        }
    
        if (pos == 1) { // this is the if you are deleteing the first node
            pop_front(); // this calls the pop front
            return;
        }
    
        Node* temp = head; // this starts at the head
    
        for (int i = 1; i < pos; i++){ // make the position move foward to the position
            if (!temp) { // if it reaches the end
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next; // goes to the next
        }
        if (!temp) { // if it reaches the end and is invalid
            cout << "Position doesn't exist." << endl;
            return;
        }
    
        if (!temp->next) { // if its the last node
            pop_back(); //this calls the pop front
            return;
        }
    
        Node* tempPrev = temp->prev; // it fixes the node before the one being deleted
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp; // this deletes the node
    }

    void push_back(int v) { // this adds a new node to the end of the list
        Node* newNode = new Node(v); // makes a new node
        if (!tail) // if the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode; // links the old tail to the new node
            newNode->prev = tail; // liks the new node back to the old tail
            tail = newNode; // moves the tail to the new node
        }
    }
    
    void push_front(int v) { // this adds a new node to the start/front of the list
        Node* newNode = new Node(v); // makes a new node
        if (!head) // if it is a empty list
            head = tail = newNode;
        else {
            newNode->next = head;// links the old head to the new node
            head->prev = newNode;// liks the new node back to the old head
            head = newNode;// moves the head to the new node
        }
    }
    
    void pop_front() { // this deletes the first node 

        if (!head) { // if its empty
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head; // this just stores the old head

        if (head->next) {
            head = head->next; // moves it forward
            head->prev = nullptr; // removes the old one
        }
        else
            head = tail = nullptr; // if it is the only node it makes it empty
        delete temp; // deletes the node
    }

    void pop_back() { // this deletes the last node
        if (!tail) { // if its empty
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail; // this just stores the old tail

        if (tail->prev) {
            tail = tail->prev; // moves it back
            tail->next = nullptr; // removes the old one
        }
        else
            head = tail = nullptr; // if it is the only node it makes it empty
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