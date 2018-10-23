#include "rules.h"
#include <string>

using namespace std;
using namespace operators;
bool check_valid_and_i(ProofLine* newline){
    if(!newline->line1 or !newline->line2)
        return false;
    if(!newline->line1->is_valid_formula or !newline->line2->is_valid_formula)
        return false;
    return newline->formula->left->get_inorder() == newline->line1->formula->get_inorder() and
           newline->formula->right->get_inorder() == newline->line2->formula->get_inorder();
}

bool check_valid_and_e1(ProofLine* newline){
    if(newline->line2 or !newline->line1 or !newline->line1->is_valid_formula or !(newline->line1->formula->data == AND))
        return false;
    return newline->line1->formula->left->get_inorder() == newline->formula->get_inorder();
}

bool check_valid_and_e2(ProofLine* newline){
    if(newline->line2 or !newline->line1 or !newline->line1->is_valid_formula or !(newline->line1->formula->data == AND))
        return false;
    return newline->line1->formula->right->get_inorder() == newline->formula->get_inorder();
}

bool check_valid_or_i1(ProofLine* newline){
    if(newline->line2 or !newline->line1 or !newline->line1->is_valid_formula)
        return false;
    return newline->line1->formula->get_inorder() == newline->formula->left->get_inorder();
}

bool check_valid_or_i2(ProofLine* newline){
    if(newline->line2 or !newline->line1 or !newline->line1->is_valid_formula)
        return false;
    return newline->line1->formula->get_inorder() == newline->formula->right->get_inorder()
}

bool check_valid_impl_e(ProofLine* newline){
    if(!newline->line2 or !newline->line1 or !newline->line1->is_valid_formula or !newline->line2->is_valid_formula or !(newline->line1->formula->data == IMPL))
        return false;
    return newline->line1->left->get_inorder() == newline->line2->formula->get_inorder() and
           newline->line1->right->get_inorder() == newline->formula->get_inorder();
}

bool check_valid_mt(ProofLine* newline){
    if(!newline->line2 or !newline->line1 or !newline->line1->is_valid_formula or !newline->line2->is_valid_formula or !(newline->line1->formula->data == IMPL))
        return false;
    if(newline->formula->data != NEG or newline->line2->formula->data != NEG)
        return false;
    return newline->line1->formula->left->get_inorder() == newline->formula->right->get_inorder() and
           newline->line1->formula->right->get_inorder() == newline->line2->formula->->right->get_inorder();

}