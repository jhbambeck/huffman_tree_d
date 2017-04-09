#include <iostream>
#include <fstream>
#include "Hufftree_d.h"

using namespace std;

int main()
{
    ifstream tree;
    tree.open("tree");
    if(!tree) cout << "Unable to open tree file";

    Hufftree_d huff;
    huff.populate(tree);
    huff.printPre();
    return 0;
}
