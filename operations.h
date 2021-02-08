#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include "stack.h"

class Operations : public Stack {

    public:
        // Constructor
        Operations(){};
        // Destructor
        ~Operations(){};
        // Method
        void operate(char operation);
};

#endif // CALCULATOR_H_INCLUDED
