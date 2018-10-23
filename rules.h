#include <string>
#include "operators.h"
#include "task2.h"

namespace verbs{
    const char INTRO = 'i';
    const char ELIM = 'e';
}

namespace rule_literals{
    using namespace operators;
    const std::string PREM {"P"};
    const std::string AND_I {AND, verbs::INTRO};
    const std::string AND_E1 {AND, verbs::ELIM, '1'};
    const std::string AND_E2 {AND, verbs::ELIM, '2'};
    const std::string OR_I1 {OR, verbs::INTRO, '1'};
    const std::string OR_I2 {OR, verbs::INTRO, '2'};
    const std::string IMPL_E {IMPL, verbs::ELIM};
    const std::string MT {"MT"};
}

bool check_validity(ProofLine* newline);
bool check_valid_prem(ProofLine* newline);
bool check_valid_and_i(ProofLine* newline);
bool check_valid_and_e1(ProofLine* newline);
bool check_valid_and_e2(ProofLine* newline);
bool check_valid_or_i1(ProofLine* newline);
bool check_valid_or_i2(ProofLine* newline);
bool check_valid_impl_e(ProofLine* newline);
bool check_valid_mt(ProofLine* newline);
