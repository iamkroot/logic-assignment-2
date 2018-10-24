#include <string>

#ifndef BTREE_H
#define BTREE_H

/**
 * Defines a BTree class which has the following data:
 * A char named token
 * Two BTree pointers to the left and right of node
 */
class BTree {
    std::string inorder;
public:
    char token;
    BTree *left;
    BTree *right;

    /**
    * Constructor for creating a BTree object
    * @param token The character using which a new BTree object will be created
    */
    explicit BTree(char token);

    /**
     * Deconstructor to delete the BTree objects
     */
    ~BTree();
    /**
     * A function to assign left BTree pointer
     * @param left The pointer to BTree object which has to be assigned
     */
    void add_left_child(BTree *left);

    /**
     * A function to assign right BTree pointer
     * @param right The pointer to BTree object which has to be assigned
     */
    void add_right_child(BTree *right);
    /**
     * A function for traversing the parse tree inorder
     * @return A string with infix expression without brackets
     */
    std::string get_inorder();
};

#endif
