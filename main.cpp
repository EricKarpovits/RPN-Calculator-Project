/// Eric Karpovits - ICS4U - October 18 2020 - RPN Calculator
/// My version of the RPN calculator is fully functioning with a lot of operatations
/// - Straight forward, easy to use UI
/// - Valid input checks, so that program runs smoothly and never crashes
/// - Program is not case sensitive
/// - Dynamic memory allocation using linked lists
/// - Coloured text for an enhanced user experience

#include "declarations.h"

int main() {

    // Declare variables, object, and enum
    string userInput;
    Operations calculator;
    MODE currentMode;

    /// Introduction
    cout << "Welcome to Eric Karpovits's calculator program" << endl;
    printCalculator(calculator);
    // Added colour to text for an enhanced user experience
    cout << yellow << "The operations avaiable are: '+' '-' '*' '/' '^' ('c' or 'clear') ('q' or 'quit') ('s' or 'swap') ('m' or 'mod')" << endl;
    cout << yellow <<"Note: This program is not case sensitive" << endl << white;

    /// Loops until user quits
    bool continueOperating = true;
    while (continueOperating) {

        cout << endl << "Type a number or an operation followed by enter" << endl << endl << ">>";
        cin >> userInput;

        // Checks for which kind of input and if it is valid
        currentMode = checkValidInput(userInput);

        // Push a number mode. If the user selected a number, by using the method push, and then print the calculator for user
        if (currentMode == PUSH) {

            calculator.push(stof(userInput));
            printCalculator(calculator);

        // Operation mode
        } else if (currentMode == OPERATE) {

            // Checks the there are atleast two nodes in order to operate
            if (!calculator.isEmpty(TWO_NODES)) {
                calculator.operate(userInput[0]);
                printCalculator(calculator);
            } else {
                // Informs the user that there must be atleast two numbers/nodes
                cout << red << endl <<"There must be atleast two different numbers in order to operate" << endl << white;
            }

        // Clear the calculator mode
        } else if (currentMode == CLEAR) {

            // Deletes all the nodes
            calculator.clearList();
            printCalculator(calculator);
            // Informs the user that the calculator is clear
            cout << green << endl <<"Sucessfully cleared the whole calculator" << endl << white;

        // Quit the program mode
        } else if (currentMode == QUIT) {

            continueOperating = false;
            cout << yellow << endl << "Thank you for using Eric Karpovits's Calculator." << endl << "Have a great day!" << endl << white;
        }
    }
    return 0;
}


