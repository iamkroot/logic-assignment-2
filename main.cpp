#include <iostream>
#include <stack>
#include <string>
#include <map>
#include "operators.h"

using namespace std;


struct BTree{
    char data;
    BTree* left;
    BTree* right;

    BTree(char data, BTree* left=NULL, BTree* right=NULL)
    : data(data), left(left), right(right) {}
    ~BTree(){
        delete left;
        delete right;
    }
    void add_left_child(char data){
        this->left = new BTree(data);
    }
    void add_left_child(BTree* left){
        this->left = left;
    }
    void add_right_child(char data){
        this->right = new BTree(data);
    }
    void add_right_child(BTree* right){
        this->right = right;
    }
};


string infix_to_postfix(string infix_exp){
    stack<char> op_stack;
    string postfix="";
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


int main(){
    string pf = infix_to_postfix("~~p^q>~(rVp)>~qVp");
    cout<<pf<<endl;
    BTree* root = postfix_to_parse_tree(&pf);
    cout<<parse_tree_to_infix(root);
    return 0;
}
