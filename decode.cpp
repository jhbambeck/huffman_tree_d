#include <iostream>
#include <fstream>
#include "Hufftree_d.h"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 4) std::cout << "Incorrect number of arguments";
    ifstream tree(argv[1]);
    if(!tree) cout << "Unable to open tree file";
    ifstream encoded(argv[2], std::ios::binary | std::ios::out);
    if(!encoded) cout << "Unable to open encoded file";
    ofstream message(argv[3]);

    Hufftree_d huff;
    huff.populate(tree);
    //huff.printPre();
    huff.genMessage(encoded, message);
    return 0;
}
