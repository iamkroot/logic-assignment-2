#include <string>
#include <vector>
#include <sstream>
#include "task1.h"
#include "task2.h"
#include "rules.h"

using namespace std;

ProofLine::ProofLine(int line_num, vector<string> parts, vector<ProofLine *> prev_lines) {
    this->line_num = line_num;
    if (parts.size() > 0) {
        string postfix = infix_to_postfix(parts[0]);
        formula = postfix_to_parse_tree(&postfix);
    }
    if (parts.size() > 1)
        rule_literal = parts[1];
    int line_num1, line_num2;
    if (parts.size() > 2 and line_num >= (line_num1 = stoi(parts[2])))
        line1 = prev_lines[line_num1 - 1];
    else
        line1 = NULL;
    if (parts.size() > 3 and prev_lines.size() >= (line_num2 = stoi(parts[3])))
        line2 = prev_lines[line_num2 - 1];
    else
        line2 = NULL;
    check_validity();
}

void ProofLine::check_validity(){
    if(rule_literal == rule_literals::PREM){
        is_valid_formula = true;
    }
    else if(rule_literal == rule_literals::AND_I){
        is_valid_formula = check_valid_and_i(this);
    }
    else if(rule_literal == rule_literals::AND_E1){
        is_valid_formula = check_valid_and_e1(this);
    }
    else{
        is_valid_formula = false;
    }
}

ProofLine* parse_line(string s, int line_num, vector<ProofLine*> prev_lines){
    s.push_back('/');
    string token;
    vector <string> tmp;
    istringstream iss(s);
    while(getline(iss, token, '/')){
        tmp.push_back(token);
    }
    return new ProofLine(line_num, tmp, prev_lines);
}
