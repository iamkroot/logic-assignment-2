#include "BTree.h"

#ifndef TASK1_H
#define TASK1_H

std::string infix_to_postfix(std::string infix_exp);

BTree *postfix_to_parse_tree(std::string *postfix);

std::string parse_tree_to_infix(BTree *root);

#endif
