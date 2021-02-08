#include "declarations.h"

// Check if users input is valid and returns the mode for the program/calculator
MODE checkValidInput(string userInput) {

    // Declaring variables and enum
    int stringLength = userInput.length();
    char firstCharacter = userInput[0];
    int decimalPointCount = 0;
    MODE currentMode;

    // Check for pushing a number mode first character can be a digit, '.' or '-'
    if (firstCharacter == '.' || isdigit(firstCharacter) || (firstCharacter == '-' && stringLength != 1)) {

        // Need to keep count of how many decimal points there are as you cannot have more than 1
        if (firstCharacter == '.') {
            decimalPointCount++;
        }

        for (int i = 1; i < stringLength; i++) {
            // Increase decimal point count
            if (userInput[i] == '.' ) {
                decimalPointCount++;
            }
            // If requires for a number is not met than mode is nothing and informs user
            if (decimalPointCount > 1 || (!isdigit(userInput[i]) && userInput[i] != '.')) {
                // Error
                cout << red << endl << "Please enter a VALID float number" << endl << white;
                return NOTHING;
            }
        }
        // If all the requirements were met for each character then the mode is PUSH and informs user
        cout << green << endl << "Pushing a number into the calculator" << endl << white;
        return PUSH;

    // Any other mode other than PUSH
    } else if (stringLength == 1){

        switch (toupper(firstCharacter)) { // Puts characters in upper case so that program is not case sensitive
            case '+': // Subtraction
            case '-': // Addition
            case '*': // Multiplication
            case '/': // Division
            case '^': // Exponent
            case 'S': // Swap
            case 'M': // Mod
                // OPERATE mode
                cout << green << endl << "Going to perform an operation" << endl << white;
                return OPERATE;
                break;
            case 'Q':
                // QUIT mode
                cout << green << endl << "Quitting the program" << endl << white;
                return QUIT;
                break;
            case 'C':
                // CLEAR mode
                cout << green << endl << "Clearing the calculator" << endl << white;
                return CLEAR;
                break;
            default:
                break;
        }
    }
    // NOTHING mode
    cout << red << endl << "Please enter a VALID operation or number" << endl << white;
    return NOTHING;
}

// Print the calculator function
void printCalculator(Operations &calculator) {

    cout << " _____________________________ " << endl;

    for (int i = 4; i > 0; i--) {
        cout << "|  _________________________  |" << endl;

        // Print the info of the node if it exists
        if(!calculator.isEmpty(i)) {
            cout << "| |" << setw(24) << calculator.getValue(i - 1) << " | |" << endl;
        } else {
            cout << "| |                         | |" << endl;
        }
        cout << "| |_________________________| |" << endl;
    }
    cout << "|  ___ ___ ___   ___ _______| |" << endl;
    cout << "| | 7 | 8 | 9 | | + | Quit  | |" << endl;
    cout << "| |___|___|___| |___|_______| |" << endl;
    cout << "| | 4 | 5 | 6 | | - | Clear | |" << endl;
    cout << "| |___|___|___| |___|_______| |" << endl;
    cout << "| | 1 | 2 | 3 | | * | Swap  | |" << endl;
    cout << "| |___|___|___| |___|_______| |" << endl;
    cout << "| | . | 0 | ^ | | / |  Mod  | |" << endl;
    cout << "| |___|___|___| |___|_______| |" << endl;
    cout << "|_____________________________|" << endl;
}
