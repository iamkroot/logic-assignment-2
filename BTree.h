#include <cstdlib>
#include <string>
#ifndef BTREE_H
#define BTREE_H

class BTree {
    std::string inorder;
public:
    char data;
    BTree* left;
    BTree* right;

    BTree(char data);
    ~BTree();
    void add_left_child(char data);
    void add_left_child(BTree* left);
    void add_right_child(char data);
    void add_right_child(BTree* right);
    std::string get_inorder();
};

#endif
