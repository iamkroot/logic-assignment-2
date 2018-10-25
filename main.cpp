#include <iostream>
#include "task1.h"
#include "task2.h"

using namespace std;

int main(){
    int part;
    cout<<"Logic Assignment 2"<<endl;
    cout<<"Part 1: Infix->postfix->parse_tree->infix converter "<<endl;
    cout<<"Part 2: A tool for verifying whether a certain proof of a given sequent is valid or not"<<endl;
    cout<<"Enter Part number to run it:\t";
    cin>>part;
    if(part==1) {
        string infix;
        cout << "Enter the infix expression:\t";
        getline(cin, infix);
        string pf = infix_to_postfix(infix);
        cout << "Postfix: \t\t\t\t\t" << pf << endl;
        BTree *root = postfix_to_parse_tree(&pf);
        cout << "Parse tree infix: \t\t\t" << parse_tree_to_infix(root);
        cout << '\n';
        return 0;
    }
    else if(part==2) {
        validate_proof();
        return 0;
    }
    else {
        cout<<"Invalid Input"<<endl;
    }
}