#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "task1.h"
using namespace std;

typedef struct Rule{
    string op;
    string verb;
    int line1, line2;
    Rule(string r, string l1, string l2){
        op.push_back(r[0]);
        verb.push_back(r[1]);
        verb.push_back(r[2]);
        line1=stoi(l1);
        line2=stoi(l2);
    }
}rule;

typedef struct Statement{
    BTree* root;
    bool is_valid;
    int line_no;
    struct Rule* rule;
    Statement(int i, string exp, string r, string l1, string l2){
        string postfx=infix_to_postfix(exp);
        root=postfix_to_parse_tree(&postfx);
        is_valid=false;
        line_no=i;
        rule=new Rule(r,l1,l2);
    }
}statement;

statement* make_statement(string s, int i){
    s.push_back('/');
    string token;
    vector <string> tmp;
    istringstream iss(s);
    while(getline(iss, token, '/')){
        tmp.push_back(token);
    }
    if(tmp.size()==2){
        tmp.push_back("-1"); //"-1" would mean uninitialized
    }
    if(tmp.size()==3){
        tmp.push_back("-1");    
    }
    statement* s1=new statement(i, tmp[0], tmp[1], tmp[2], tmp[3]);
    return s1;
}