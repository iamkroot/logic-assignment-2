#include <iostream>
#include "task2.h"

using namespace std;

int main(){
    vector<ProofLine*> v;
    ProofLine* pl1 = parse_line("p >r/P", 1, v);
//    cout<<pl1->formula->get_inorder()<<endl;
//    cout<<pl1->is_valid_formula;
    v.push_back(pl1);
    ProofLine* pl2 = parse_line("~r/P", 2, v);
//    cout<<pl2->formula->get_inorder()<<endl;
//    cout<<pl2->is_valid_formula;
    v.push_back(pl2);
    ProofLine* pl3 = parse_line("~p/MT/1/2", 3, v);
    cout<<pl3->formula->get_inorder()<<endl;
    cout<<pl3->is_valid_formula;
//    string pf = infix_to_postfix("~~p^q>~(rVp)>~qVp");
//    cout<<pf<<endl;
//    BTree* root = postfix_to_parse_tree(&pf);
//    cout<<parse_tree_to_infix(root);
    return 0;
}
