#include <iostream>
#include "BST.hpp"
using namespace std;

int main()
{
    // testing out --> delete once inserting and timing dataSetA and dataSetB
    cout << "Creating tree" << endl;
    BST tree(5); // root of 5

    tree.addNode(2); //left child to 5
    tree.addNode(1); //left child to 1
    tree.addNode(4); //right child to 2
    tree.addNode(7); //right child to 5
    tree.addNode(10); //right child of 7
    tree.addNode(8); // left child of 10
    tree.addNode(6); // left child of 7

    cout<<"----------------Intial tree is ---------------"<<endl<<endl;
    tree.print2DUtil(1);

    cout<<"----------------Inorder traversal of the tree is ---------------"<<endl<<endl;
    tree.printTree();
}
