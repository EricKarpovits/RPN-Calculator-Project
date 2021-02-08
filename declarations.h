#ifndef DECLARATIONS_H_INCLUDED
#define DECLARATIONS_H_INCLUDED

// Libraries
#include <iostream>
#include <math.h>
#include <iomanip>
#include <string.h>
#include <windows.h>

using namespace std;

// Header files
#include "operations.h"
#include "stack.h"
// Text color header file - not mine but I modified it
#include "consoleColor.h"

// Program modes
enum MODE {
    OPERATE,
    PUSH,
    QUIT,
    CLEAR,
    NOTHING
};

// Prototypes
MODE checkValidInput(string userInput);
void printCalculator(Operations &calculator);

// Constants
const int ONE_NODE = 1;
const int TWO_NODES = 2;

#endif // DECLARATIONS_H_INCLUDED

