#ifndef OPERATORS_H
#define OPERATORS_H

/**
 * Defining operators using namespace to make it easy for changing input syntax as and when required
 */
namespace operators {
    const char NEG{'~'}; /**< Defines NEG to char '~' */
    const char AND{'^'}; /**< Defines AND to char '^' */
    const char OR{'V'}; /**< Defines OR to char 'V' */
    const char IMPL{'>'}; /**< Defines IMPL to char '>' */
}

/**
 * @brief Checks whether token is an operand
 * @param token Character which is to be checked
 * @return true if token is an operand else false
 */
bool is_operand(char token);

/**
 * @brief Checks whether token is an operator
 * @param token Character which is to be checked
 * @return true if token is an operator else false
 */
bool is_operator(char token);

/**
 * @brief Assigns priority(precedence) to op
 * @details Assigns integer priority using the following order:
 *          NEG(4) > AND(3) = OR(3) > IMPL(2)
 *          with default being -1
 * @param op Character whose priority is to be determined
 * @return Corresponding priority integer
 */
int op_priority(char op);

#endif
