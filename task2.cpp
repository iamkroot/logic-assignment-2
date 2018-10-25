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
    if (!parts.empty()) {  // Convert first part to parse tree
        string postfix = infix_to_postfix(parts[0]);
        formula = postfix_to_parse_tree(&postfix);
    }
    if (parts.size() > 1)
        rule_literal = parts[1];
    int line_num1, line_num2;
    if (parts.size() > 2 and line_num > (line_num1 = stoi(parts[2])))
        line1 = prev_lines[line_num1 - 1];  // store the reference to previous ProofLine mentioned in new line
    else
        line1 = nullptr;  // in case the rule doesn't require reference to previous line
    if (parts.size() > 3 and line_num > (line_num2 = stoi(parts[3])))
        line2 = prev_lines[line_num2 - 1];
    else
        line2 = nullptr;
    is_valid_formula = check_validity(this);
}

ProofLine *parse_line(string s, int line_num, vector<ProofLine *> prev_lines) {
    s.push_back('/');
    string part;
    vector<string> parts;
    istringstream iss(s);
    while (getline(iss, part, '/')) {  // keep reading parts of the input string separated by a '/'
        parts.push_back(part);
    }
    return new ProofLine(line_num, parts, prev_lines);
}

void validate_proof() {
    int n;
    cout << "Enter number of lines in proof: ";
    cin >> n;
    vector<ProofLine *> proof;
    cout << "Enter the lines of the proof: \n";
    cin.ignore(1);  // ignore the newline of previous cout
    for (int i = 1; i <= n; i++) {
        string line;
        cout << i << ": ";
        getline(cin, line);
        {   // Removes spaces in the input string line
            int x = 0, y = 0;
            while (line[x]) { //iterates untill end of string(\0) is reached
                if (line[x]!=' ') // if iterator finds a space
                    line[y++]=line[x]; // increments y while swaping the space with prev non space char
                x++; // iterating to next char of string
            }
            line[y] = '\0'; //denotes the end of string
        }
        proof.push_back(parse_line(line, i, proof));
    }
    for (auto proofline: proof) {  // iterate through the prooflines to look for an invalid proofline
        if (!(proofline->is_valid_formula)) {
            cout << "Invalid proof. First error at line number " << proofline->line_num << '.\n';
            return;
        }
    }
    cout << "Valid proof\n";
}
