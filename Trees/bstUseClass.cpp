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

BinarySearchTreeNode<int>* createTree(int * In,int * Pre,int InS,int InE,int PreS,int PreE){

if(InS>InE){
    return NULL;
}
int rootData=Pre[PreS];
int rootIndex=-1;
for(int i=InS;i<=InE;i++){
    if(In[i]==rootData){
        rootIndex=i;
        break;
    }
}

int lInS=InS;
int lInE=rootIndex-1;
int rInS=rootIndex+1;
int rInE=InE;
int lPreS=PreS+1;
int lPreE=lInE-lInS + lPreS;
int rPreS=lPreE+1;
int rPreE=PreE;

BinarySearchTreeNode<int>* root=new BinarySearchTreeNode<int>(rootData);
root->left= createTree(In,Pre,lInS,lInE,lPreS,lPreE);
root->right= createTree(In,Pre,rInS,rInE,rPreS,rPreE);
return root;
}

BinarySearchTreeNode<int>* helper(int* In,int* pre,int size){
    return createTree(In,pre,0,size-1,0,size-1);
}


int height(BinarySearchTreeNode<int>* root){
   if(root == NULL){
       return 0;
   }
   return 1 +max( height(root->left),height(root->right));
}

int diameter(BinarySearchTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int option1=  height(root->left) + height(root->right);
    int option2= diameter(root->left);
    int option3= diameter(root->right);
    return max(option1,max(option2,option3));
}

pair<int,int> optimisedDiameter(BinarySearchTreeNode<int>*root){
    if(root==NULL){
        pair<int,int>p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int> leftPair =optimisedDiameter(root->left);
    pair<int,int> rightPair=optimisedDiameter(root->right);
    int lh=leftPair.first;
    int ld=leftPair.second;
    int rh=rightPair.first;
    int rd=rightPair.second;

    int height= 1 + max(lh,rh);
    int diameter=max(lh+rh,max(ld,rd));

    pair<int,int> result;
    result.first=height;
    result.second=diameter;
    return result;

}

int main()
{
    int In[10]={10,4,2,5,1,8,6,3,7,9};
    int Pre[10]={1,2,4,10,5,3,6,8,7,9};
    BinarySearchTreeNode<int>* root=helper(In,Pre,10);
    // printTreeLevelWise(root);
    // cout<<diameter(root)<<endl;
    pair<int,int> ans=optimisedDiameter(root);
    cout<<"Height "<<ans.first<<endl;
    cout<<"Diameter "<<ans.second<<endl;
    return 0;
}