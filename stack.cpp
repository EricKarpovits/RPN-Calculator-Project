#include "declarations.h"

// Constructor
Stack::Stack(){

    head = NULL;
}

// Destructor - Deletes all the reamining linked lists if there are any remaining
Stack::~Stack(){

    clearList();
}

// Push a number by creating a new node
void Stack::push(float userNum) {

    // Creating a new node and setting info equal to the data
    Node *newnode = new Node;
    newnode->info = userNum;
    newnode->next = head;
    // Head will always be the new node
    head = newnode;
}

// Pop a number out of the linked list
float Stack::pop() {

    // Check if there is atleast 1 not to pop a number from
    if (!isEmpty(ONE_NODE)) {
        float value = head->info;
        Node *temp = head;
        head = head->next;
        // Deletes the node to release memory
        delete temp;
        // Make head point to next node
        return value;
    // I played around with throwing exceptions for a learning experience but the method has to return something but cannot
    // return a number as it would cause bugs. Therefore normall is empty is checked before calling the method pop(), but if
    // it is called it will throw an exception instead of returning a number
    } else {
        cout << red << "The link list is empty, cannot pop" << endl << white;
        throw "Invalid pop() operation";
    }
}

// Checks if the linked list is empty based on the number of nodes as the arguement
bool Stack::isEmpty(int numberOfNodes) {

    Node *temp = head;
    for(int i = 0; i < numberOfNodes; i++) {
        if(temp == NULL) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Gets the info of the node based on which index
float Stack::getValue(int index) {

    Node *temp = head;
    float info;

    for (int i = 0; i <= index; i++) {
        if (temp == NULL) {
            // Once again the method throws and exception instead of returing a number as it would cause bugs; basically just
            // an extra layer of protection
            throw "Invalid index for getValue()";
        } else {
            if (i == index){
                info = temp->info;
            }
            temp = temp->next;
        }
    }
    return info;
}

// Method which clears the linked list - used by the destructor too
void Stack::clearList() {

    // Create node pointer that iterates through each node and deletes them
    Node* node = head;
    while (node != NULL) {
        Node* temp = node->next;
        delete node;
        node = temp;
    }
    head = NULL;
}


