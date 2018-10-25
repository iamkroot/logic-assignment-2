#include <iostream>
#include "task1.h"
#include "task2.h"

using namespace std;

int main() {
    int part;
    cout << "Logic Assignment 2\n";
    cout << "Part 1: Infix->postfix->parse_tree->infix converter.\n";
    cout << "Part 2: A tool for verifying whether a certain proof of a given sequent is valid or not.\n";
    while (true) {
        cout << "Enter Part number to run it (0 to exit): ";
        cin >> part;
        cin.ignore(1);  // ignore \n
        if (!part)
            break;
        else if (part == 1) {
            string infix;
            cout << "Enter the infix expression: ";
            getline(cin, infix);
            string pf = infix_to_postfix(infix);
            cout << "Postfix: " << pf << endl;
            BTree *root = postfix_to_parse_tree(&pf);
            cout << "Parse tree infix: " << parse_tree_to_infix(root) << endl;
            cout << "This formula is well formed.\n";
            cout << '\n';
        } else if (part == 2) {
            validate_proof();
        } else {
            cout << "Invalid Input" << endl;
        }
    }
}