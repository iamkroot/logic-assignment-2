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
 * @relatesalso ProofLine
 * @brief Checks validity of given ProofLine
 * @details Complexity: O(1)
 * @param[in] newline Pointer to ProofLine to be validated
 * @return true if the ProofLine is valid else false
 */
bool check_validity(ProofLine *newline);

/**
 * @relatesalso ProofLine
 * @brief Checks validity of given PREMISE ProofLine
 * @details Complexity: O(1)
 * @param[in] newline Pointer to the PREMISE ProofLine
 * @return true if ProofLine is a PREMISE else false
 */
bool check_valid_prem(ProofLine *newline);

/**
 * @relatesalso ProofLine
 * @brief Checks validity of given AND INTRODUCTION ProofLine
 * @details Complexity: O(1)
 * @param[in] newline Pointer to the AND INTRODUCTION ProofLine
 * @return true if the ProofLine is valid else false
 */
bool check_valid_and_i(ProofLine *newline);

/**
 * @relatesalso ProofLine
 * @brief Checks validity of given AND ELIMINATION 1 ProofLine
 * @details Complexity: O(1)
 * @param[in] newline Pointer to the AND ELIMINATION 1 ProofLine
 * @return true if the ProofLine is valid else false
 */
bool check_valid_and_e1(ProofLine *newline);

/**
 * @relatesalso ProofLine
 * @brief Checks validity of given AND ELIMINATION 2 ProofLine
 * @details Complexity: O(1)
 * @param[in] newline Pointer to the AND ELIMINATION 2 ProofLine
 * @return true if the ProofLine is valid else false
 */
bool check_valid_and_e2(ProofLine *newline);

/**
 * @relatesalso ProofLine
 * @brief Checks validity of given OR INTRODUCTION 1 ProofLine
 * @details Complexity: O(1)
 * @param[in] newline Pointer to the OR INTRODUCTION 1 ProofLine
 * @return true if the ProofLine is valid else false
 */
bool check_valid_or_i1(ProofLine *newline);

/**
 * @relatesalso ProofLine
 * @brief Checks validity of given OR INTRODUCTION 2 ProofLine
 * @details Complexity: O(1)
 * @param[in] newline Pointer to the OR INTRODUCTION 2 ProofLine
 * @return true if the ProofLine is valid else false
 */
bool check_valid_or_i2(ProofLine *newline);

/**
 * @relatesalso ProofLine
 * @brief Checks validity of given IMPLICATION ELIMINATION ProofLine
 * @details Complexity: O(1)
 * @param[in] newline Pointer to the IMPLICATION ELIMINATION ProofLine
 * @return true if the ProofLine is valid else false
 */
bool check_valid_impl_e(ProofLine *newline);

/**
 * @relatesalso ProofLine
 * @brief Checks validity of given MODUS TOLLENS ProofLine
 * @details Complexity: O(1)
 * @param[in] newline Pointer to the MODUS TOLLENS ProofLine
 * @return true if the ProofLine is valid else false
 */
bool check_valid_mt(ProofLine *newline);
