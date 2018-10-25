#include "BTree.h"

// Uses an initialization list instead of copy constructors
BTree::BTree(char token) : token(token), left(nullptr), right(nullptr) {}

BTree::~BTree() {
    // manually deallocate the left and right subtrees
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
    // To improve performance, we store the inorder string when the function is first called.
    // All subsequent calls just return that string, instead of traversing the entire tree again and again.
    // We assume that once this function is called, the tree won't be modified.
    if (!inorder.empty())
        return inorder;
    if (left)
        inorder += left->get_inorder();
    inorder += token;
    if (right)
        inorder += right->get_inorder();
    return inorder;
}
