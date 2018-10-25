#include "operators.h"

bool is_operand(char token) {
    // Assumes operands are lowercase alphabets
    return token >= 'a' && token <= 'z';
}

bool is_operator(char token) {
    using namespace operators;
    const char VALID_OPERATORS[] = {NEG, AND, OR, IMPL};
    for (char op: VALID_OPERATORS)
        if (token == op)
            return true;
    return false;
}

int op_priority(char op) {
    using namespace operators;
    switch (op) {
        case NEG:
            return 4;
        case AND:
        case OR:
            return 3;
        case IMPL:
            return 2;
        default:
            return -1; // Give lowest priority to invalid operators
    }
}
