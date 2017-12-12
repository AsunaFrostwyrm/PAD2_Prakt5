#include <iostream>
#include <array>
#include <ctime>

#include "BST.h"


using namespace std;

int main() try{
    srand(time(NULL));
    
    static const int arraySize = 9;
    
    BST* tree = new BST;
    
    //Random Fill Array mit chars
    cout << "Pre-implement Chars" << endl;
    for(int i = 0; i < arraySize; i++){
        char insertParameter = rand() % 26 + 'A';
        cout << insertParameter << " ";
        
        //If letter not yet in tree (0 = not in yet), Insert
        if(tree->search(insertParameter) == 0){
            tree->insertNode(insertParameter);
        } else {
            tree->incrementRepeat(insertParameter);
        }
    }
    
    //Sortierte Baumausgabe
    cout << endl << endl << "Automatisch sortierte Chars nach implementierung im Baum" << endl;
    tree->printSetupAlphabetical();
    cout << endl;
    
    //Ursprungswurzel
    cout << endl << "Die Ursprungswurzel ist: ";
    tree->getRoot();
    cout << endl;
    
    //Baumhöhe
    cout << endl << "Der Baum hat " << tree->getTreeHeight() << " ebenen." << endl;
    
    //Knotenanzahl
    cout << endl;
    cout << "Knotenanzahl: " << tree->getKnots();
    cout << endl;
    
    //Suche bestimmen Char im Baum
    char searchFor = rand() % 26 + 'A';
    cout << endl << "Spezifische Suche nach " << searchFor << ": ";
    if(tree->search(searchFor) == 0){
        cout << "nicht gefunden";
    } else {
        cout << "gefunden.";
    }
    cout << endl;
    
    //Repeating Chars
    cout << endl << "Häufigkeit der Chars" << endl;
    tree->callPrintRepeat();
    cout << endl;
    
    //In Order Traversing
    cout << "In Order Traversierung" << endl;
    tree->callTrav2();
    cout << endl;
    
    //Level Order Traversing
    cout << "Level Order Traversierung" << endl;
    tree->callTrav1();
    cout << endl;
    
    
    //----Aufgabe 1b---
    
    
    //Reroot the tree with a new node
    cout << endl;
    tree->reRootCall();
    cout << endl;
    
    //New Traverse Output
    tree->callTrav1();
    cout << endl;
    tree->callTrav2();
    cout << endl;
    tree->getRoot();
    
    return 0;
}

catch(std::exception error){
    cout << error.what() << endl;
    return -2;
}

catch(...){
    cout << "Unknown error" << endl;
    return -1;
}
