#include "BST.h"

//---Public

BST::BST() {
    root = NULL;
}

BST::~BST() {
    destroyTree();
}

void BST::getRoot() {
    std::cout << this->root->keyValue;
}

int BST::getKnots() {
    knoten(this->root);
    return knotenAnzahl;
}

int BST::getTreeHeight() {
    return getTreeHeight(this->root);
}

void BST::printSetupAlphabetical(){
    outputAlphabetically(this->root);
}

node* BST::doubleNode(){
    return this->root;
}

void BST::incrementRepeat(char current){
    incrementRepeat(current, this->root);
}

void BST::callPrintRepeat(){
    printRepeat(this->root);
}

void BST::reRootCall(){
    insertNode('F');
    node* newRoot = returnNode('F', this->root);
    reRoot(newRoot);
}

/*The public version of the insert function takes care of the case where the root has not been initialized by allocating
 * the memory for it and setting both child nodes to NULL and setting the key_value to the value to be inserted. If the
 * root node already exists, insert is called with the root node as the initial node of the function, and the recursive
 * insert function takes over.*/
void BST::insertNode(char key) {
if(root != NULL){
        insertNode(key, root);
    } else {
        root = new node;
        root->keyValue = key;
        root->left = NULL;
        root->right = NULL;
    }
}

/*The public version of the search function is used to set off the search recursion at the root node, keeping it from
 * being necessary for the user to have access to the root node.*/
bool BST::search(char key){
    return search(key, root);
}

void BST::callTrav2() {
    inOrderTrav(this->root);
}

//Each level is worked through before continuing to the next
void BST::callTrav1(){
    levelOrderTrav(this->root);
}

/*The public version of the destroy tree function is merely used to initialize the recursive destroy_tree function which
 * then deletes all the nodes of the tree. */
void BST::destroyTree() {
    destroyTree(root);
}

//---Private

//Destroys a single leaflet
void BST::destroyTree(node* leaf) {
    if(leaf != NULL){
        destroyTree(leaf->left);
        destroyTree(leaf->right);
        delete leaf;
    }
}

void BST::insertNode(char key, node* leaf) {
    if(key < leaf->keyValue){               //Wenn übergebener Key kleiner ist als der aktuelle Key, gehe linken Baum entlang
        if(leaf->left != NULL){             //Wenn nach links kein Nullzweig erreicht ist
            insertNode(key, leaf->left);    //Rufe funktion neu auf mit neu übergebenen Key
        } else {
            leaf->left = new node;          //Neuen Node erstellen nach links
            leaf->left->keyValue = key;     //Keyvalue des Nodes setzen
            leaf->left->left = NULL;        //Setzt den linken Child auf NULL
            leaf->left->right = NULL;       //Setzt den rechten Child auf NULL
        }
    }
    else if(key >= leaf->keyValue){         //Wenn übergebener Key grösser/gleich den aktuellen key, gehe Baum rechts entlang
        if(leaf->right != NULL){            //Wenn nach rechts kein Nullzweig erreicht ist 
            insertNode(key, leaf->right);   //Rufe funktion neu auf mit neu übergebenen Key
        } else {                            //Ansonsten
            leaf->right = new node;         //Neuen Node nach rechts erstellen
            leaf->right->keyValue = key;    //Keyvalue des Nodes setzen
            leaf->right->left = NULL;       //Setzt den linken Child auf NULL
            leaf->right->right = NULL;      //Setzt den rechten Child auf NULL
        }
    }
}

bool BST::search(char key, node* leaf) {
    if(leaf != NULL){
        if(key == leaf->keyValue){          //Wenn der Keyvalue gefunden ist, den Node Zurück geben
            return true;
        }
        if(key < leaf->keyValue){           //Wenn der Keyvalue kleiner ist als aktueller Node
            return search(key, leaf->left); //Suche nach links weiter
        }
        else {
            return search(key, leaf->right);//Sonst, suche nach rechts weiter
        }
    } else {
        return false;                        //Wenn keyvalue nicht im Baum existiert, NULL zurück geben
    }
}

node* BST::returnNode(char key, node* leaf) {
    if(leaf != NULL){
        if(key == leaf->keyValue){          //Wenn der Keyvalue gefunden ist, den Node Zurück geben
            return leaf;
        }
        if(key < leaf->keyValue){           //Wenn der Keyvalue kleiner ist als aktueller Node
            return returnNode(key, leaf->left); //Suche nach links weiter
        }
        else {
            return returnNode(key, leaf->right);//Sonst, suche nach rechts weiter
        }
    } else {
        return 0;                        //Wenn keyvalue nicht im Baum existiert, NULL zurück geben
    }
}

void BST::incrementRepeat(char current, node* leaf){
    if(leaf != NULL){
        if(current == leaf->keyValue){          //Wenn der Keyvalue gefunden ist, den Node Zurück geben
            leaf->repeatingValue++;
        }
        if(current < leaf->keyValue){           //Wenn der Keyvalue kleiner ist als aktueller Node
            incrementRepeat(current, leaf->left); //Suche nach links weiter
        }
        else {
            incrementRepeat(current, leaf->right);//Sonst, suche nach rechts weiter
        }
    }
}

void BST::outputAlphabetically(node* root){
    if(!root){
        return;
    }
    outputAlphabetically(root->left);
    std::cout << root->keyValue << ' ';
    outputAlphabetically(root->right);
}

int BST::getTreeHeight(node* root){
    if (!root){
        return 0;
    } else {
     return 1 + std::max(getTreeHeight(root->left), getTreeHeight(root->right));   
    }
}

void BST::printRepeat(node* root){
    if(!root){
        return;
    }
    printRepeat(root->left);
    std::cout << root->keyValue << ": " << root->repeatingValue << std::endl;
    printRepeat(root->right);
}

//Traversierung
void BST::inOrderTrav(node* n) {
    if(n == nullptr){
        return;
    }
    if(n->left != NULL){
        inOrderTrav(n->left);
    }
    std::cout << n->keyValue << " ";
    if(n->right != NULL){
        inOrderTrav(n->right);
    }
}

void BST::levelOrderTrav(node* n) {
    if(n == nullptr){
        return;
    }
    std::queue<node*> q{};
    q.push(n);
    while(!q.empty()){
        n = q.front();
        q.pop();
        std::cout << n->keyValue << " ";
        if(n->left != nullptr){
            q.push(n->left);
        }
        if(n->right != nullptr){
            q.push(n->right);
        }
    }
}

void BST::knoten(node* root){
    if(root == nullptr){
        return;
    }
    if(root->left != NULL){
        knotenAnzahl++;
        knoten(root->left);
    }
    if(root->right != NULL){
        knotenAnzahl++;
        knoten(root->right);
    }
}

void BST::reRoot(node* y){
    
    node* x = y->left;
    node* subTree = x->right;
    
    x->right = y;
    y->left = subTree;
}
