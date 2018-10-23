#ifndef OPERATORS_H
#define OPERATORS_H

namespace operators {
    const char NEG{'~'};
    const char AND{'^'};
    const char OR{'V'};
    const char IMPL{'>'};
}

bool is_operand(char token);

bool is_operator(char token);

int op_priority(char op);

#endif
