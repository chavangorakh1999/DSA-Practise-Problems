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

vector<int>* rootToNodePath(BinarySearchTreeNode<int>* root,int data){

    if(root== NULL){
        return NULL;
    }
    if(root->data == data){
        vector<int>* output= new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> * leftOutput= rootToNodePath(root->left,data);
    if(leftOutput!=NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int>* rightOutput= rootToNodePath(root->right,data);
    if(rightOutput!=NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }else{
        return NULL;
    }


}

int main()
{
    int arr[7]={1,2,3,4,5,6,7};

    BinarySearchTreeNode<int>* root=arrayInput(arr,0,6);
    printTree(root);
    vector<int>* result=rootToNodePath(root,7);
    for(auto x : *result){
        cout<<x<<" ";
    }
    return 0;
}