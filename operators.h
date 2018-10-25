#ifndef OPERATORS_H
#define OPERATORS_H

/**
 * Defining operators using namespace to make it easy for changing input syntax as and when required
 */
namespace operators {
    const char NEG{'~'};
    const char AND{'^'};
    const char OR{'V'};
    const char IMPL{'>'};
}

/**
 * A function to check whether token is operand or not
 * @param token The character which is to be checked
 * @return true if token is an operand else false
 */
bool is_operand(char token);

/**
 * A function to check whether token is operator or not
 * @param token The character which is to be checked
 * @return true if token is an operator else false
 */
bool is_operator(char token);

/**
 * A function to determine the priority(precedence) of the input character
 * @param op The character whose priority is to be determined
 * @return The corresponding priority integer
 */
int op_priority(char op);

#endif
