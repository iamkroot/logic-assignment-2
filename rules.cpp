#include "rules.h"
#include <string>

using namespace std;
bool check_valid_and_i(ProofLine* newline){
    if(!newline->line1 or !newline->line2)
        return false;
    if(!newline->line1->is_valid_formula or !newline->line2->is_valid_formula)
        return false;
    return newline->formula->left->get_inorder() == newline->line1->formula->get_inorder() and
           newline->formula->right->get_inorder() == newline->line2->formula->get_inorder();
}

bool check_valid_and_e1(ProofLine* newline){
    if(newline->line2 or !newline->line1 or !newline->line1->is_valid_formula)
        return false;
    return newline->line1->formula->left->get_inorder() == newline->formula->get_inorder();
}
