//
//  main.cpp
//  SerializeBST
//
//  Created by JORGE SUAREZ RIVAYA on 7/17/12.
//  Copyright (c) 2012 Trasgu. All rights reserved.
//
// Design an algorithm and write code to serialize and deserialize a binary 
// tree. Writing the tree to a file is called ‘serialization’ and reading back 
// from the file to reconstruct the exact same binary tree is ‘deserialization’.
//

#include <iostream>

using namespace std;

typedef struct Node {
    char value;
    Node * left;
    Node * right;
} Node;

string serialize (Node *);
string deserializeTree (Node *&, string);
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
    
    // create BST (at the end this is a deserialization)
    deserializeTree(root, treeString);
    
    // print deserialized tree
    
    // serialize (write in a file)
    cout << endl << "your input: " << serialize(root) << endl;
    
    // free tree memory
    freeTree (root);
    
    return 0;
}

// put the BST in a file
// we have to determine in which order: preorder, inorder or postorder
// it does not matter, just choose one. (in this case preorder)
string serialize (Node * root) {
    
    string tmp;
    
    if (!root) {
        return "#";
    }
    
    tmp = root->value;
    tmp.append(serialize(root->left)) ;
    tmp.append(serialize(root->right));
    
    return tmp;
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

void freeTree (Node * root) {
    
    if (!root) return;
    if (root->left) freeTree(root->left);
    if (root->right) freeTree(root->right);
    
    free(root);
}
