#include "declarations.h"

void Operations::operate(char operation) {

    // Delcare variable
    float temp = 0;

    // Try for exception - would never happen more for learning
    try {
        // Switch the user operation choice and makes all chars uppercase
        switch(toupper(operation)) {

            // Addition
            case '+':
                push(pop() + pop());
                break;

            // Subtraction
            case '-':
                temp = pop();
                push(pop() - temp);
                break;

            // Multiplication
            case '*':
                push(pop() * pop());
                break;

            // Division
            case '/':
                temp = pop();
                if (temp != 0){
                    push(pop() / temp);
                } else {
                    cout << red << endl << "CANNOT DIVIDE BY ZERO" << endl << white;
                    push(temp);
                }
                break;

            // Exponent / power
            case '^':
                temp = pop();
                push(pow(pop(), temp));
                break;

            // Swap
            case 'S': { // Needed to add curly brackets as there is a variable being declared
                temp = pop();
                float tempSwap = pop();
                push(temp);
                push(tempSwap);
                break;
            }

            // Modulus
            case 'M':
                temp = pop();
                if (temp != 0){
                    // fmodf allows for float modulus
                    push(fmodf(pop(), temp));
                } else {
                    cout << red << endl << "MOD 0 IS UNDEFINED" << endl << white;
                    push(temp);
                }
                break;

            // Default - It would never get here as it checks valid input before going into the method
            // However it is just an extra layer of protection
            default:
                cout << red << endl << "Please select a valid opperation" << endl << white;
            break;
        }
    // Catch exceptions so that the program would not end - however would not ever end up here, just extra layer of protection
    } catch(char const* error) {
        cout << red << endl << "Error caught: " << error << endl << white;
    }
}

