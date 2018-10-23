#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "rules.h"
#include "task1.h"
#include "task2.h"

using namespace std;

ProofLine::ProofLine(int line_num, vector<string> parts, vector<ProofLine *> prev_lines) {
    this->line_num = line_num;
    if (!parts.empty()) {
        string postfix = infix_to_postfix(parts[0]);
        formula = postfix_to_parse_tree(&postfix);
    }
    if (parts.size() > 1)
        rule_literal = parts[1];
    int line_num1, line_num2;
    if (parts.size() > 2 and line_num > (line_num1 = stoi(parts[2])))
        line1 = prev_lines[line_num1 - 1];
    else
        line1 = nullptr;
    if (parts.size() > 3 and line_num > (line_num2 = stoi(parts[3])))
        line2 = prev_lines[line_num2 - 1];
    else
        line2 = nullptr;
    is_valid_formula = check_validity(this);
}

ProofLine *parse_line(string s, int line_num, vector<ProofLine *> prev_lines) {
    s.push_back('/');
    string token;
    vector<string> tmp;
    istringstream iss(s);
    while (getline(iss, token, '/')) {
        tmp.push_back(token);
    }
    return new ProofLine(line_num, tmp, prev_lines);
}

void validate_proof() {
    int n;
    cout << "Enter number of lines in proof: ";
    cin >> n;
    vector<ProofLine *> proof;
    cout << "Enter the lines of the proof: \n";
    cin.ignore(1);
    for (int i = 1; i <= n; i++) {
        string line;
        cout << i << ": ";
        getline(cin, line);
        proof.push_back(parse_line(line, i, proof));
    }
    for (auto proofline: proof) {
        if (!(proofline->is_valid_formula)) {
            cout << "Invalid proof. Line number: " << proofline->line_num << '\n';
            return;
        }
    }
    cout << "Valid proof\n";
}
