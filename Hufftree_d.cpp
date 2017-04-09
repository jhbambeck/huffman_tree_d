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

void Hufftree_d::genMessageRec(Node* nodePtr, std::ifstream& encoded, std::ofstream& message)
{
    if(nodePtr->ch == '+');
    else if(nodePtr->ch != '$')
    {
        char c = nodePtr->ch;
        standardize(c);
        message << c;
        genMessageRec(root, encoded, message);
    }
    else
    {
        char c;
        encoded >> c;
        if(c == '0')
        {
            genMessageRec(nodePtr->left, encoded, message);
        }
        else
        {
            genMessageRec(nodePtr->right, encoded, message);
        }
    }
}

void Hufftree_d::standardize(char& c)
{
    if(c == '-')
    {
        c = ' ';
        std::cout << "standardizing";
    }
    if(c == '!') c = '/n';
}
