//
//  main.cpp
//  MaxHeight
//
//  Created by JORGE SUAREZ RIVAYA on 7/17/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
// find max height of BST

#include <iostream>

using namespace std;

typedef struct Node {
    char value;
    Node * left;
    Node * right;
} Node;

int getMaxHeight (Node *);
string deserializeTree (Node * &, string);
void freeTree (Node *);

int main(int argc, const char * argv[])
{
    Node * root = NULL;
    string treeString;
    
    // read values
    cout << "    30" << endl;
    cout << "   /  \\ " << endl;
    cout << "  10  20 " << endl;
    cout << " /    / \\ " << endl;
    cout << "50   45  35 " << endl << endl;
    cout << "Insert the tree (example: 30 10 50 # # # 20 45 # # 35 # #) > ";
    cin >> treeString;

    deserializeTree(root, treeString);
    cout << "Max height is: " << getMaxHeight(root) << endl;
    
    freeTree(root);
    
    return 0;
}

string deserializeTree (Node * &node, string treeString){
    
    if (treeString[0] == '#') {
        node = NULL;
        treeString = treeString.substr(1);
        return treeString;
    }
    
    node = new Node;
    node->value = treeString[0];
    treeString = deserializeTree(node->left, treeString.substr(1));
    treeString = deserializeTree(node->right, treeString);
    
    return treeString;
}

int getMaxHeight (Node * tree) {
    int lh, rh;
    
    if (!tree) {
        return 0;
    }
    
    lh = getMaxHeight(tree->left);
    rh = getMaxHeight(tree->right);
    
    if (lh>rh) {
        return ++lh;
    } else {
        return ++rh;
    }
    
}

void freeTree (Node * root) {
    
    if (!root) return;
    if (root->left) freeTree(root->left);
    if (root->right) freeTree(root->right);
    
    free(root);
}
