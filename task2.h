#include "BTree.h"
#include <vector>
#ifndef TASK2_H
#define TASK2_H

class ProofLine{
public:
    int line_num;
    BTree* formula;
    std::string rule_literal;
    ProofLine* line1;
    ProofLine* line2;
    bool is_valid_formula;
    ProofLine(int line_num, std::vector<std::string> parts, std::vector<ProofLine*> prev_lines);
};

ProofLine* parse_line(std::string s, int line_num, std::vector<ProofLine*> prev_lines);
void validate_proof();

#endif
