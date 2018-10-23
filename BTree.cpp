#include "BTree.h"

BTree::BTree(char token) : token(token), left(nullptr), right(nullptr) {}

BTree::~BTree() {
    delete left;
    delete right;
}

void BTree::add_left_child(BTree *left) {
    this->left = left;
}

void BTree::add_right_child(BTree *right) {
    this->right = right;
}

std::string BTree::get_inorder() {
    if (!inorder.empty())
        return inorder;
    if (left)
        inorder += left->get_inorder();
    inorder += token;
    if (right)
        inorder += right->get_inorder();
    return inorder;
}
