#include "AVLTree.h"
#include <iostream>
using namespace std;

int main(){

    AVLTree* tree = new AVLTree();

    tree->setRoot(tree->insert(tree->getRoot(), 1));
    tree->setRoot(tree->insert(tree->getRoot(), 12));
    tree->setRoot(tree->insert(tree->getRoot(), 0));
    tree->setRoot(tree->insert(tree->getRoot(), 13));
    tree->setRoot(tree->insert(tree->getRoot(), 22));
    tree->setRoot(tree->insert(tree->getRoot(), 22));
    tree->setRoot(tree->insert(tree->getRoot(), 33));
    tree->setRoot(tree->insert(tree->getRoot(), 44));
    tree->setRoot(tree->insert(tree->getRoot(), 55));
    tree->setRoot(tree->insert(tree->getRoot(), 2));
    
    cout<<"IN ORDER: ";
    tree->printTreeInOrder(tree->getRoot()); 
    cout<<"\n";
    cout<<"PRE ORDER: ";
    tree->printTreePreOrder(tree->getRoot());
    cout<<"\n";
    cout<<"POST ORDER: ";
    tree->printTreePostOrder(tree->getRoot());


    // tree->findMax();
    cout<<"\n";
    cout<<"MIN: "<<tree->findMin() <<endl;
    cout<<"MAX: "<<tree->findMax() <<endl;
    cout<<"\n";
    cout<<"CONTAINS(12): "<<tree->contains(12) <<endl;
    cout<<"CONTAINS(-5): "<<tree->contains(-5) <<endl;
    cout<<"CONTAINS(0): "<<tree->contains(0) <<endl;
    cout<<"CONTAINS(0, root->left): "<<tree->contains(0, tree->getRoot()->left) <<endl;
    cout<<"CONTAINS(10, root): "<<tree->contains(10, tree->getRoot()) <<endl;

    tree->setRoot(tree->remove(12, tree->getRoot()));
    cout<<"CONTAINS(12): "<<tree->contains(12) <<endl;
    
    cout<<"POST ORDER: ";
    tree->printTreePostOrder(tree->getRoot());
    cout<<"\n";


    // tworznie takiego samego
    AVLTree* newTree1 = new AVLTree(AVLTree());
    newTree1->setRoot(newTree1->insert(newTree1->getRoot(), 1));

    cout<<"POST ORDER (newTree1): ";
    newTree1->printTreeInOrder(newTree1->getRoot());
    cout<<"\n";


    // kopiowanie
    AVLTree* newTree = new AVLTree(*tree);

    cout<<"POST ORDER (newTree): ";
    newTree->printTreePostOrder(newTree->getRoot());

    newTree->makeEmpty(&newTree->getRefRoot());

    cout<<"\n";
    cout<<"POST ORDER (newTree): ";
    newTree->printTreePostOrder(newTree->getRoot());
    cout<<"\n";

    // operator=(const AVLTree& tree)
    AVLTree *assigTree = tree;

    cout<<"POST ORDER (assigTree): ";
    newTree->printTreePostOrder(assigTree->getRoot());
    cout<<"\n";

}