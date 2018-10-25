#include <iostream>
#include <stack>
#include "operators.h"
#include "task1.h"

using namespace std;

string infix_to_postfix(string infix_exp) {
    stack<char> op_stack;  // Stack to store the operators during conversion
    string postfix;
    for (char token:infix_exp) {  // for-each loop
        if (is_operand(token)) {
            postfix.push_back(token);  // push operand directly to output string 
        } else if (is_operator(token)) {
            while (!op_stack.empty() &&
                   op_priority(op_stack.top()) > op_priority(token) &&
                   op_stack.top() != '(') {
                postfix.push_back(op_stack.top());  // push lower priority operators to output string
                op_stack.pop();
            }
            op_stack.push(token);
        } else if (token == '(') {
            op_stack.push(token);
        } else if (token == ')') {
            while (op_stack.top() != '(') {
                postfix.push_back(op_stack.top());  // keep popping operators till next open parenthesis
                op_stack.pop();
            }
            op_stack.pop();
        }
    }
    while (!op_stack.empty()) {  // push all remaining operators to output string
        postfix.push_back(op_stack.top());
        op_stack.pop();
    }
    return postfix;
}

BTree *postfix_to_parse_tree(string *postfix) {
    // Build the parse tree in a top-down manner, with the last character of postfix acting as root node of its subtree
    if (postfix->empty()) {  // Should recieve a non-empty string
        std::cout << "\nNot a well formed formula!\n";
        exit(1);
    }
    char last_token = postfix->back();
    postfix->resize(postfix->length() - 1);  // Remove the last character from the postfix expression
    if (is_operand(last_token))
        return new BTree(last_token);  // operand can't have subtrees, so we terminate the recursion here
    else {
        auto current = new BTree(last_token);
        BTree *right = postfix_to_parse_tree(postfix);  // parse the remaining postfix expression to get subtree
        current->add_right_child(right);
        if (last_token != operators::NEG) {
            BTree *left = postfix_to_parse_tree(postfix);
            current->add_left_child(left);
        }
        return current;
    }
}

string parse_tree_to_infix(BTree *root) {
    // use inorder traversal to generate the infix formula
    if (!root->left and !root->right)
        return string(&(root->token));
    string expr;
    if (root->token != operators::NEG)
        expr.push_back('(');  // since NEG is a unary operator, it doesn't need surrounding parentheses. Eg: ~p^q instead of (~p)^q
    if (root->left)
        expr.append(parse_tree_to_infix(root->left));  // get infix of left subtree
    expr.push_back(root->token);
    if (root->right)
        expr.append(parse_tree_to_infix(root->right)); // get infix of right subtree
    if (root->token != operators::NEG)
        expr.push_back(')');
    return expr;
}
