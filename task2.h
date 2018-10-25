#ifndef TASK2_H
#define TASK2_H

#include <vector>
#include "BTree.h"
/**
 * @brief Class containing segregated information about a ProofLine
 */
class ProofLine {
public:
    int line_num; /**< Line number of current ProofLine */
    BTree *formula; /**< Root of binary tree created from expression in input string */
    std::string rule_literal; /**< String of rule inputted */
    ProofLine *line1; /**< Pointer to ProofLine with given line_num */
    ProofLine *line2; /**< Pointer to ProofLine with given line_num */
    bool is_valid_formula; /**< Whether current ProofLine is true or false */

    /**
     * @brief A constructor of ProofLine for given inputs
     * @param[in] line_num Line number of current ProofLine
     * @param[in] parts Vector of strings created by splitting of input string with delimiter '/'
     * @param[in] prev_lines Vector of pointers to all previous ProofLine
     */
    ProofLine(int line_num, std::vector<std::string> parts, std::vector<ProofLine *> prev_lines);
};

/**
 * @relatesalso ProofLine
 * @brief Makes new ProofLine object using the input string
 * @param[in] s Input string obtained from user
 * @param[in] line_num Line number of current ProofLine
 * @param[in] prev_lines Vector containing all previous ProofLine pointers
 * @return Pointer to newly created ProofLine object
 */
ProofLine *parse_line(std::string s, int line_num, std::vector<ProofLine *> prev_lines);

/**
 * @relatesalso ProofLine
 * @brief Checks validity of user-given proof
 */
void validate_proof();

#endif
