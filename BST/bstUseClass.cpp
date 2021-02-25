#include <bits/stdc++.h>
#include "binarySearchTree.h"
using namespace std;
#define COUNT 5

BinarySearchTreeNode<int> *takeTreeInput()
{
    int rootData;
    cout << "Enter root Data: ";
    cin >> rootData;
    BinarySearchTreeNode<int> *root = new BinarySearchTreeNode<int>(rootData);
    queue<BinarySearchTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinarySearchTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int leftChild;
        cout << "Enter Left Child of " << front->data << endl;
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinarySearchTreeNode<int> *child = new BinarySearchTreeNode<int>(leftChild);
            front->left = child;
            pendingNodes.push(child);
        }
        int rightChild;
        cout << "Enter right child of " << front->data << endl;
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

BinarySearchTreeNode<int> *findNode(BinarySearchTreeNode<int> *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    if (root->data > data)
    {
        findNode(root->left, data);
    }
    if (root->data < data)
    {
        findNode(root->right, data);
    }
    cout << "DATA NOT FOUND" << endl;
    return NULL;
}

void printInRange(BinarySearchTreeNode<int> *root, int min, int max)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data > min)
    {
        printInRange(root->left, min, max);
    }
    if (min <= root->data && max >= root->data)
    {
        cout << root->data << " ";
    }
    if (root->data <= max)
    {

        printInRange(root->right, min, max);
    }
}

BinarySearchTreeNode<int>* minValueNode(BinarySearchTreeNode<int>*root){
    BinarySearchTreeNode<int>* current= root;
        while(current && current->left !=NULL){
            current=current->left;
        }
        return current;
}


BinarySearchTreeNode<int> *deleteNode(BinarySearchTreeNode<int> *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data > data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = deleteNode(root->right, data);
    }
    else {
        if(root->left==NULL){
            BinarySearchTreeNode<int>* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            BinarySearchTreeNode<int>* temp=root->left;
            free(root);
            return temp;
        }

        BinarySearchTreeNode<int>* temp= minValueNode(root->right);

        root->data= temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
    

}

BinarySearchTreeNode<int> *insertNode(BinarySearchTreeNode<int> *root, int data)
{
    if (root == NULL)
    {
        root = new BinarySearchTreeNode<int>(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    else
    {
        root->left = insertNode(root->left, data);
    }
    return root;
}

bool isBST(BinarySearchTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data < min || root->data > max)
    {
        return false;
    }
    bool isLeftOk = isBST(root->left, min, root->data - 1);
    bool isRightOk = isBST(root->right, root->data, max);
    return isLeftOk && isRightOk;
}

void print2DUtil(BinarySearchTreeNode<int> *root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->right, space);
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << "\n";
    print2DUtil(root->left, space);
}

int main()
{
    BinarySearchTreeNode<int> *root = takeTreeInput();
    root = insertNode(root, 55);
    print2DUtil(root, 0);
    root=deleteNode(root,60);
    print2DUtil(root, 0);

    return 0;
}