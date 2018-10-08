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
