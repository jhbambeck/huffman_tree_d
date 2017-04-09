#ifndef HUFFTREE_D_H
#define HUFFTREE_D_H
#include <iostream>
#include <fstream>

class Hufftree_d
{
public:
    struct Node
    {
        char ch;
        Node* left;
        Node* right;
    };
    Node* root = nullptr;

    void populate(std::ifstream&);
    void populateRec(Node*&, std::ifstream&);
    void printPre()
        { printPreRec(root); };
    void printPreRec(Node*);
};

#endif // HUFFTREE_D_H
