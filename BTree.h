#include <string>

#ifndef BTREE_H
#define BTREE_H

class BTree {
    std::string inorder;
public:
    char token;
    BTree *left;
    BTree *right;

    explicit BTree(char token);

    ~BTree();

    void add_left_child(BTree *left);

    void add_right_child(BTree *right);

    std::string get_inorder();
};

#endif
