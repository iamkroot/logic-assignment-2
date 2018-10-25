#include <string>

#ifndef BTREE_H
#define BTREE_H

/**
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
    * @param token Character using which a new BTree object will be created
    */
    explicit BTree(char token);

    /**
     * @brief Deconstructor for given binary tree
     */
    ~BTree();
    /**
     * @brief A function to assign left BTree pointer
     * @param left The pointer to BTree object which has to be assigned
     */
    void add_left_child(BTree *left);

    /**
     * @brief A function to assign right BTree pointer
     * @param right The pointer to BTree object which has to be assigned
     */
    void add_right_child(BTree *right);
    /**
     * @brief A function for traversing the parse tree inorder
     * @return A string with infix expression without brackets
     */
    std::string get_inorder();
};

#endif
