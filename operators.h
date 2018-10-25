#ifndef OPERATORS_H
#define OPERATORS_H

/**
 * Defining operators using namespace to make it easy for changing input syntax as and when required
 */
namespace operators {
    const char NEG{'~'}; /**< Defines NEGATION */
    const char AND{'^'}; /**< Defines AND */
    const char OR{'V'}; /**< Defines OR */
    const char IMPL{'>'}; /**< Defines IMPLICATION */
}

/**
 * @brief Checks whether token is an operand
 * @details Complexity: O(1)
 * @param token Character which is to be checked
 * @return true if token is an operand else false
 */
bool is_operand(char token);

/**
 * @brief Checks whether token is an operator
 * @details Complexity: O(number of valid operators)
 * @param token Character which is to be checked
 * @return true if token is an operator else false
 */
bool is_operator(char token);

/**
 * @brief Assigns priority(precedence) to op
 * @details Assigns integer priority using the following order:
 *          NEG(4) > AND(3) = OR(3) > IMPL(2)
 *          with default being -1<br>
 *          Complexity: O(1)
 * @param op Character whose priority is to be determined
 * @return Corresponding priority integer
 */
int op_priority(char op);

#endif
