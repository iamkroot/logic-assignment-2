#include <iostream>
#include "task1.h"

using namespace std;

int main(){
    string pf = infix_to_postfix("~~p^q>~(rVp)>~qVp");
    cout<<pf<<endl;
    BTree* root = postfix_to_parse_tree(&pf);
    cout<<parse_tree_to_infix(root);
    return 0;
}
