#include "prefix.h"

//-----------------------------------------------------------------------------
// constructor
// initialize the array to the empty string,
// char arrays end with '\0' (null character) so operator<< works properly

Prefix::Prefix() {
    expr[0] = '\0';
}

//-----------------------------------------------------------------------------
// setPrefix
// Set a prefix expression made of single digit operands, operators +,-,*,/
// and no blanks or tabs contained in a file. The expression is valid in
// that each valid operator has two valid operands.

void Prefix::setPrefix(ifstream& infile) {
    infile >> expr;
}

//-----------------------------------------------------------------------------
// evaluatePrefix 
// Evaluate a prefix expr made of single digit operands and operators +,-,*,/
// Return the answer (integer arithmetic).

int Prefix::evaluatePrefix() const {
    if (expr[0] == '\0')                          // empty string
        return 0;

    int index = -1;                               // to walk through expr
    return evaluatePrefixHelper(index);
}

//-----------------------------------------------------------------------------
// evaluatePrefixHelper 
// Helper function for recursive evaluatePrefix

int Prefix::evaluatePrefixHelper(int& index) const {
    char symbol = expr[++index];

    if (isdigit(symbol)) return symbol - '0';

    int a = evaluatePrefixHelper(index);
    int b = evaluatePrefixHelper(index);
    
    switch (symbol) {
        case '+': return a + b;
        case '-': return a - b;
        case '/': return a / b;
        case '*': return a * b;
    }
    return -1;
}

//-----------------------------------------------------------------------------
// outputAsPostfix
// Convert prefix expression to postfix and output

void Prefix::outputAsPostfix(ostream& out) const {
    if (expr[0] == '\0')                      // empty string
        return;

    int index = -1;                           // to walk through expr
    int count = -1;                           // used to build postfix array
    char postfix[MAXSIZE + 1];                  // holds postfix expression
    toPostfix(index, postfix, count);
    postfix[++count] = '\0';
    out << postfix;
}

//-----------------------------------------------------------------------------
// toPostfix
// Convert prefix expression to postfix

void Prefix::toPostfix(int& index, char postfix[], int& count) const {
    char symbol = expr[++index];

    if (isdigit(symbol)) postfix[++count] = symbol;
    else {
        toPostfix(index, postfix, count);
        toPostfix(index, postfix, count);
        postfix[++count] = symbol;
    }
}

//-----------------------------------------------------------------------------
// operator<<
// display prefix expression as a string (char array)

ostream& operator<<(ostream& output, const Prefix& expression) {
    output << expression.expr;
    return output;
}
