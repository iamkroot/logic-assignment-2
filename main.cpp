#include <iostream>
#include <stack>
#include <string>
#include <map>

namespace operators {
    const char NEG = '~';
    const char AND = '^';
    const char OR = 'V';
    const char IMPL = '>';
}

using namespace std;


class BTree{
    char data;
    BTree* left;
    BTree* right;

public:
    BTree(char data, BTree* left=NULL, BTree* right=NULL){
        this->data = data;
        this->left = left;
        this->right = right;
    }
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
    string inorder() const{
        string expr;
        if(left)
            expr.append(left->inorder());
        expr.push_back(data);
        if(right)
            expr.append(right->inorder());
        return expr;
    }
};


bool is_operand(char token){
    // Assumes operands are lowercase alphabets
    if(token>='a'&&token<='z')
        return true;
    return false;
}

bool is_operator(char token){
    using namespace operators;
    const char VALID_OPERATORS[] = {NEG, AND, OR, IMPL};
    for(char op: VALID_OPERATORS)
        if(token==op)
            return true;
    return false;
}

int op_priority(char op){
    using namespace operators;
    switch (op){
        case NEG: return 4;
        case AND:
        case OR: return 3;
        case IMPL: return 2;
        default: return -1;
    }
}

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

int main(){
    string pf = infix_to_postfix("~~p^q>~(rVp)>~qVp");
    cout<<pf<<endl;
    BTree* root = postfix_to_parse_tree(&pf);
    cout<<root->inorder();
    return 0;
}
