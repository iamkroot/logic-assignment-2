#include <string>

#ifndef BTREE_H
#define BTREE_H

/**
 * @brief Class to represent a Binary Tree
 * @details This will be used to store the parse tree of the propositional formulas
 * 
 */
class BTree {
    std::string inorder;
public:
    char token; /**< Char containing data for current node in binary tree */
    BTree *left; /**< Pointer to left node in binary tree */
    BTree *right; /**< Pointer to right node in binary tree */

    /**
    * @brief Constructor for creating a BTree object
    * @details Complexity: O(1)
    * @param token Character using which a new BTree object will be created
    */
    explicit BTree(char token);  // prevent implicit conversion by the compiler

    /**
     * @brief Destructor for given binary tree
     * @details Complexity: O(1)
     */
    ~BTree();
    /**
     * @brief A function to assign left BTree pointer
     * @details Complexity: O(1)
     * @param left The pointer to BTree object which has to be assigned
     */
    void add_left_child(BTree *left);

    /**
     * @brief A function to assign right BTree pointer
     * @details Complexity: O(1)
     * @param right The pointer to BTree object which has to be assigned
     */
    void add_right_child(BTree *right);
    /**
     * @brief A function for traversing the parse tree inorder
     * @details Complexity: O(number of nodes in tree) on first run; O(1) on subsequent calls
     * @return A string with infix expression without brackets
     */
    std::string get_inorder();
};

#endif
