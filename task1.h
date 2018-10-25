#include "BTree.h"

#ifndef TASK1_H
#define TASK1_H

/**
 * @brief Converts the infix expression to postfix
 * @details Complexity: O(number of characters in infix expression)
 * @param infix_exp The user-given string expression in infix form
 * @return A string in postfix form
 */
std::string infix_to_postfix(std::string infix_exp);

/**
 * @warning This function modifies the postfix string it takes as argument!
 * @brief Generates a binary tree using given postfix expression
 * @details Complexity: O(number of characters in postfix expression)
 * @param postfix Postfix expression which we want to parse
 * @return Root of the binary tree generated
 */
BTree *postfix_to_parse_tree(std::string *postfix);

/**
 * @brief Traverses a given tree to produce corresponding infix expression
 * @details Complexity: O(number of nodes in parse tree)
 * @param root Root of binary tree to be traversed
 * @return A string of infix expression of binary tree
 */
std::string parse_tree_to_infix(BTree *root);

#endif
