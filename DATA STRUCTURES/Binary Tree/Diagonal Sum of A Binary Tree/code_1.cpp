//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 15/04/19.
//  Copyright © 2019 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <queue>
using namespace std;

struct bnode {
    int data;
    bnode *left;
    bnode *right;
};

class btree {
public:
    bnode *root;
    btree();
    void insert();
    void display();
    bnode* newNode(int);
    void printDiagonal(bnode*);
};
btree::btree() {
    
    root = NULL;
}
bnode* btree:: newNode(int value) {
    
    bnode* temp=new bnode;
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void btree:: insert() {
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(9);
    root->left->right = newNode(6);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->right->left->right = newNode(7);
    root->right->left->left = newNode(12);
    root->left->right->left = newNode(11);
    root->left->left->right = newNode(10);
}
void btree::display() {
    
    insert();
    cout << "\nDiagonal Traversal\n";
    printDiagonal(root);
}

void btree::printDiagonal(bnode* root) {
    if (root == NULL) {
        return;
    }
    queue<bnode*> q;
    q.push(root);
    q.push(NULL);
    int sum = 0;
    while (!q.empty()) {
        bnode* temp = q.front();
        q.pop();
        if (temp == NULL) {
            if (q.empty()) {
                cout << "\nSum\t:\t" << sum << endl;
                sum = 0;
                return;
            }
            cout << "\nSum\t:\t" << sum << endl;
            cout << endl;
            sum = 0;
            q.push(NULL);
        }
        else {
            while (temp) {
                sum += temp->data;
                cout << temp->data << "\t";
                if (temp->left) {
                    q.push(temp->left);
                }
                temp = temp->right;
            }
        }
    }
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
