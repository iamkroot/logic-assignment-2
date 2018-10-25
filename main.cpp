#include <iostream>
#include "task1.h"
#include "task2.h"

using namespace std;

int main(){
    string infix;
    cout<<"Enter the infix expression:\t";
    getline(cin, infix);
    string pf = infix_to_postfix(infix);
    cout<<"Postfix: \t\t\t\t\t"<<pf<<endl;
    BTree* root = postfix_to_parse_tree(&pf);
    cout<<"Parse tree infix: \t\t\t"<<parse_tree_to_infix(root);
    cout<<'\n';
    validate_proof();
    return 0;
}
