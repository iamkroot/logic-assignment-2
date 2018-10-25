#include <string>
#include "operators.h"
#include "task2.h"

/**
 * Defining verbs for ease of making changes if required
 */
namespace verbs {
    const char INTRO{'i'}; /**<  Defines INTRODUCTION */
    const char ELIM{'e'}; /**<  Defines ELIMINATION */
}

/**
 * Defining types of rules for ease of making changes if required
 */
namespace rule_literals {
    using namespace operators; /**< Enables us to use AND, OR, IMPL, NEG */
    const std::string PREM{"P"}; /**< Defines PREMISE */
    const std::string AND_I{AND, verbs::INTRO}; /**< Defines AND INTRODUCTION */
    const std::string AND_E1{AND, verbs::ELIM, '1'}; /**< Defines AND ELIMINATION 1 */
    const std::string AND_E2{AND, verbs::ELIM, '2'}; /**< Defines AND ELIMINATION 2 */
    const std::string OR_I1{OR, verbs::INTRO, '1'}; /**< Defines OR INTRODUCTION 1 */
    const std::string OR_I2{OR, verbs::INTRO, '2'}; /**< Defines OR INTRODUCTION 2 */
    const std::string IMPL_E{IMPL, verbs::ELIM}; /**< Defines IMPLIES ELIMINATION */
    const std::string MT{"MT"}; /**< Defines MODUS TOLLENS */
}

/**
 * @brief Checks validity of given ProofLine
 * @details Complexity: O(1)
 * @param newline Pointer to ProofLine to be validated
 * @return true if the ProofLine is valid else false
 */
bool check_validity(ProofLine *newline);

/**
 * @brief Checks validity of given premise ProofLine
 * @details Complexity: O(1)
 * @param newline Pointer to the premise ProofLine
 * @return true if ProofLine is a premise else false
 */
bool check_valid_prem(ProofLine *newline);

/**
 * @brief Checks validity of given ^i ProofLine
 * @details Complexity: O(1)
 * @param newline Pointer to the ^i ProofLine
 * @return true if the ProofLine is valid else false
 */
bool check_valid_and_i(ProofLine *newline);

/**
 * @brief Checks validity of given ^e1 ProofLine
 * @details Complexity: O(1)
 * @param newline Pointer to the ^e1 ProofLine
 * @return true if the ProofLine is valid else false
 */
bool check_valid_and_e1(ProofLine *newline);

/**
 * @brief Checks validity of given ^e2 ProofLine
 * @details Complexity: O(1)
 * @param newline Pointer to the ^ie2 ProofLine
 * @return true if the ProofLine is valid else false
 */
bool check_valid_and_e2(ProofLine *newline);

/**
 * @brief Checks validity of given Vi1 ProofLine
 * @details Complexity: O(1)
 * @param newline Pointer to the Vi1 ProofLine
 * @return true if the ProofLine is valid else false
 */
bool check_valid_or_i1(ProofLine *newline);

/**
 * @brief Checks validity of given Vi2 ProofLine
 * @details Complexity: O(1)
 * @param newline Pointer to the Vi2 ProofLine
 * @return true if the ProofLine is valid else false
 */
bool check_valid_or_i2(ProofLine *newline);

/**
 * @brief Checks validity of given >e ProofLine
 * @details Complexity: O(1)
 * @param newline Pointer to the >e ProofLine
 * @return true if the ProofLine is valid else false
 */
bool check_valid_impl_e(ProofLine *newline);

/**
 * @brief Checks validity of given MT ProofLine
 * @details Complexity: O(1)
 * @param newline Pointer to the MT ProofLine
 * @return true if the ProofLine is valid else false
 */
bool check_valid_mt(ProofLine *newline);
