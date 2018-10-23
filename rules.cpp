#include "rules.h"

using namespace std;
using namespace operators;

bool check_validity(ProofLine *newline) {
    using namespace rule_literals;
    if (newline->rule_literal == PREM)
        return check_valid_prem(newline);
    else if (newline->rule_literal == AND_I)
        return check_valid_and_i(newline);
    else if (newline->rule_literal == AND_E1)
        return check_valid_and_e1(newline);
    else if (newline->rule_literal == AND_E2)
        return check_valid_and_e2(newline);
    else if (newline->rule_literal == OR_I1)
        return check_valid_or_i1(newline);
    else if (newline->rule_literal == OR_I2)
        return check_valid_or_i2(newline);
    else if (newline->rule_literal == IMPL_E)
        return check_valid_impl_e(newline);
    else if (newline->rule_literal == MT)
        return check_valid_mt(newline);
    else
        return false;
}

bool check_valid_prem(ProofLine *newline) {
    return !(newline->line1 or newline->line2);
}

bool check_valid_and_i(ProofLine *newline) {
    if (!newline->line1 or !newline->line1->is_valid_formula)
        return false;
    if (!newline->line2 or !newline->line2->is_valid_formula)
        return false;
    return newline->formula->left->get_inorder() == newline->line1->formula->get_inorder() and
           newline->formula->right->get_inorder() == newline->line2->formula->get_inorder();
}

bool check_valid_and_e1(ProofLine *newline) {
    if (newline->line2 or !newline->line1 or !newline->line1->is_valid_formula or newline->line1->formula->token != AND)
        return false;
    return newline->line1->formula->left->get_inorder() == newline->formula->get_inorder();
}

bool check_valid_and_e2(ProofLine *newline) {
    if (newline->line2 or !newline->line1 or !newline->line1->is_valid_formula or newline->line1->formula->token != AND)
        return false;
    return newline->line1->formula->right->get_inorder() == newline->formula->get_inorder();
}

bool check_valid_or_i1(ProofLine *newline) {
    if (newline->line2 or !newline->line1 or !newline->line1->is_valid_formula)
        return false;
    return newline->line1->formula->get_inorder() == newline->formula->left->get_inorder();
}

bool check_valid_or_i2(ProofLine *newline) {
    if (newline->line2 or !newline->line1 or !newline->line1->is_valid_formula)
        return false;
    return newline->line1->formula->get_inorder() == newline->formula->right->get_inorder();
}

bool check_valid_impl_e(ProofLine *newline) {
    if (!newline->line1 or !newline->line1->is_valid_formula)
        return false;
    if (!newline->line2 or !newline->line2->is_valid_formula)
        return false;
    if (newline->line1->formula->token != IMPL)
        return false;
    return newline->line1->formula->left->get_inorder() == newline->line2->formula->get_inorder() and
           newline->line1->formula->right->get_inorder() == newline->formula->get_inorder();
}

bool check_valid_mt(ProofLine *newline) {
    if (!newline->line1 or !newline->line1->is_valid_formula)
        return false;
    if (!newline->line2 or !newline->line2->is_valid_formula)
        return false;
    if (newline->line1->formula->token != IMPL)
        return false;
    if (newline->formula->token != NEG or newline->line2->formula->token != NEG)
        return false;
    return newline->line1->formula->left->get_inorder() == newline->formula->right->get_inorder() and
           newline->line1->formula->right->get_inorder() == newline->line2->formula->right->get_inorder();
}
