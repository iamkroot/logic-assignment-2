#include <stack>
#include <string>
#include "task1.h"
#include "operators.h"

using namespace std;

string infix_to_postfix(string infix_exp){
    stack<char> op_stack;
    string postfix;
    for(char token:infix_exp){
        if(is_operand(token)){
            postfix.push_back(token);
        }
        else if(is_operator(token)){
            while(!op_stack.empty() && 
                  op_priority(op_stack.top())>op_priority(token) &&
                  op_stack.top()!='('){
                postfix.push_back(op_stack.top());
                op_stack.pop();
            }
            op_stack.push(token);
        }
        else if(token=='('){
            op_stack.push(token);
        }
        else if(token==')'){
            while(op_stack.top()!='('){
                postfix.push_back(op_stack.top());
                op_stack.pop();
            }
            op_stack.pop();
        }
    }
    while(!op_stack.empty()){
        postfix.push_back(op_stack.top());
        op_stack.pop();
    }
    return postfix;
}

BTree* postfix_to_parse_tree(string *postfix){
    char last_token = postfix->back();
    postfix->resize(postfix->length() - 1);
    if(is_operand(last_token))
        return new BTree(last_token);
    else {
        BTree* current = new BTree(last_token);
        BTree* right = postfix_to_parse_tree(postfix);
        current->add_right_child(right);
        if(last_token != operators::NEG){
            BTree* left = postfix_to_parse_tree(postfix);
            current->add_left_child(left);
        }
        return current;
    }
}

string parse_tree_to_infix(BTree* root){
    if(!root->left and !root->right)
        return string(&(root->data));
    string expr;
    if(root->data != operators::NEG)
        expr.push_back('(');
    if(root->left)
        expr.append(parse_tree_to_infix(root->left));
    expr.push_back(root->data);
    if(root->right)
        expr.append(parse_tree_to_infix(root->right));
    if(root->data != operators::NEG)
        expr.push_back(')');
    return expr;
}
