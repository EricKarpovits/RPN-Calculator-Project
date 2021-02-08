#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

class Stack {

    // Had to make the properties protected so the inherent classes can acess/modify them
    protected:
        // Node struct
        struct Node {
            float info;
            Node *next;
        };
        // Node pointer head
        Node *head;

    public:
        // Constructor
        Stack();
        // Destructor
        ~Stack();
        // Methods
        void push(float number);
        float pop();
        bool isEmpty(int numberOfNodes);
        float getValue(int whichValue);
        void clearList();
};

#endif // LINKEDLIST_H_INCLUDED
