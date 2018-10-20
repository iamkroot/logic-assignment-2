#include "BTree.h"
#include "operators.h"
#include <cstdlib>

BTree::BTree(char data) : data(data), left(NULL), right(NULL) {}

BTree::~BTree(){
    delete left;
    delete right;
}

void BTree::add_left_child(char data){
    this->left = new BTree(data);
}

void BTree::add_left_child(BTree* left){
    this->left = left;
}

void BTree::add_right_child(char data){
    this->right = new BTree(data);
}

void BTree::add_right_child(BTree* right){
    this->right = right;
}