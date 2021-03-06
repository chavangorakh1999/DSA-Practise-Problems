#include<bits/stdc++.h>
#include "binarySearchTree.h"
using namespace std;

BinarySearchTreeNode<int> *takeTreeInput(){
    int rootData;
    cout<<"Enter root Data: ";
    cin>>rootData;
    BinarySearchTreeNode<int>*root= new BinarySearchTreeNode<int>(rootData);
    queue<BinarySearchTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinarySearchTreeNode<int> *front=pendingNodes.front();
        pendingNodes.pop();
        int leftChild;
        cout<<"Enter Left Child of "<<front->data<<endl;
        cin>>leftChild;
        if(leftChild != -1){
            BinarySearchTreeNode<int> *child=new BinarySearchTreeNode<int>(leftChild);
            front->left=child;
            pendingNodes.push(child);
        }
        int rightChild;
        cout<<"Enter right child of "<<front->data<<endl;
        cin>>rightChild;
        if(rightChild != -1 ){
            BinarySearchTreeNode<int>*child= new BinarySearchTreeNode<int>(rightChild);
            front->right=child;
            pendingNodes.push(child);
        }

    }
    
    return root;
}