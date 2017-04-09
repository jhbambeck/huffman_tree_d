#include <iostream>
#include <fstream>
#include "Hufftree_d.h"

using namespace std;

int main()
{
    ifstream tree("tree");
    if(!tree) cout << "Unable to open tree file";

    ifstream encoded("basic_encoded.bin", std::ios::binary | std::ios::out);
    if(!encoded) cout << "Unable to open encoded file";

    ofstream message("message");

    Hufftree_d huff;
    huff.populate(tree);
    //huff.printPre();
    huff.genMessage(encoded, message);
    return 0;
}
