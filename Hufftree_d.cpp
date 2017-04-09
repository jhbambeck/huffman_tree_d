#include "Hufftree_d.h"

void Hufftree_d::populate(std::ifstream& tree)
{
    populateRec(root, tree);
}

void Hufftree_d::populateRec(Node*& nodePtr, std::ifstream& tree)
{
    char c;
    tree >> c;
    if(!tree.eof())
    {
        if(c == '/')
        {
            nodePtr = nullptr;
        }
        else
        {
            nodePtr = new Node;
            nodePtr->ch = c;
            populateRec(nodePtr->left, tree);
            populateRec(nodePtr->right, tree);
        }
    }
}

void Hufftree_d::printPreRec(Node* nodePtr)
{
    if(nodePtr == nullptr) std::cout << "/";
    else
    {
        std::cout << nodePtr->ch;
        printPreRec(nodePtr->left);
        printPreRec(nodePtr->right);
    }
}
