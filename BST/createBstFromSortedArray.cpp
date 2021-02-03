#include "bstTakeInput.h"

BinarySearchTreeNode<int> *arrayInput(int *arr,int startIndex, int endIndex){
    if(startIndex>endIndex){
        return NULL;
    }
    
    int mid=(startIndex+endIndex)/2;
    BinarySearchTreeNode<int> *root= new BinarySearchTreeNode<int>(arr[mid]);
    root->left=arrayInput(arr,startIndex,mid-1);
    root->right =arrayInput(arr,mid+1,endIndex);
    return root;
}

void printTree(BinarySearchTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    queue<BinarySearchTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinarySearchTreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<" : ";
        BinarySearchTreeNode<int>* leftNode=front->left;
    if(leftNode!=NULL){
        cout<<"L"<<leftNode->data;
        pendingNodes.push(leftNode);
    }
    BinarySearchTreeNode<int>* rightNode=front->right;
    if(rightNode!=NULL){
         cout<<"R"<<rightNode->data;
        pendingNodes.push(rightNode);
    }
    cout<<endl;
    }
}

int main()
{
    int arr[7]={1,2,3,4,5,6,7};

    BinarySearchTreeNode<int>* root=arrayInput(arr,0,6);
    printTree(root);
    return 0;
}