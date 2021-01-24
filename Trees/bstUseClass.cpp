#include <bits/stdc++.h>
#include "binarySearchTree.h"
using namespace std;

BinarySearchTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter root Data" << endl;
    cin >> rootData;
    BinarySearchTreeNode<int> *root = new BinarySearchTreeNode<int>(rootData);
    queue<BinarySearchTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinarySearchTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter Left child of" << front->data << endl;
        int leftChild;
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinarySearchTreeNode<int> *child = new BinarySearchTreeNode<int>(leftChild);
            front->left = child;
            pendingNodes.push(child);
        }
         cout << "Enter Right child of" << front->data << endl;
        int rightChild;
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinarySearchTreeNode<int> *child = new BinarySearchTreeNode<int>(rightChild);
            front->right = child;
            pendingNodes.push(child);
        }
    }

    return root;
}

void printTreeLevelWise(BinarySearchTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    queue<BinarySearchTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinarySearchTreeNode<int>* front= pendingNodes.front();\
        pendingNodes.pop();
        cout<<front->data<<":";
        if(front->left!=NULL)
        {
        cout<<"L"<<front->left->data<<" ";
        pendingNodes.push(front->left);
        }
        if(front->right!=NULL)
        {
        cout<<"R"<<front->right->data<<" ";
        pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}

int main()
{
    BinarySearchTreeNode<int>* root=takeInput();
    printTreeLevelWise(root);
    return 0;
}