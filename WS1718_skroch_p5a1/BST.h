#include <cstdlib>
#include <iostream>
#include <math.h>
#include <queue> 

struct node{
    char keyValue;
    int repeatingValue = 1;
    
    node* left{};
    node* right{};
};

class BST {
public:
    BST();
    ~BST();
    
    void getRoot();
    int getKnots();
    int getTreeHeight();
    void printSetupAlphabetical();
    void callPrintRepeat();    
    void insertNode(char);
    bool search(char);
    
    void callTrav1();
    void callTrav2();
    node* doubleNode();

    void incrementRepeat(char);
    
    void reRootCall();
    
    void destroyTree();
    
private:
    
    void destroyTree(node*);
    void insertNode(char, node*);
    bool search(char, node*);
    node* returnNode(char, node*);
    void incrementRepeat(char, node*);
    void outputAlphabetically(node*);
    int getTreeHeight(node*);
    int returnRepeat(node*);
    void printRepeat(node*);
    void knoten(node*);
    
    void inOrderTrav(node*);
    void levelOrderTrav(node*);
    
    void reRoot(node*);
    

    node* root{};
    int knotenAnzahl = 0;
    
};
