#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of childrens of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            
            int childData;
            cout<<"Enter "<<i<<"th child for"<<front->data<<endl;
            cin>>childData;
            TreeNode<int>* child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

TreeNode<int> *takeInput()
{
    int data;
    cout << "Enter data" << endl;
    cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);
    int n;
    cout << "Enter number of children for " << data;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        TreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
         cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++){
           cout<<front->children[i]->data<<",";
           pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }

  
}

int numNodes(TreeNode<int> * root){
    int sum=1;
    for(int i=0;i<root->children.size();i++){
        sum +=numNodes(root->children[i]);
    }
    return sum;
}


int height(TreeNode<int>* root){
    int ht=0;
    for(int i=0;i<root->children.size();i++){
        int childHeight=height(root->children[i]);
        ht=max(childHeight,ht);
    }
    ht+=1;

    return ht;
}

void printKthLevelElements(TreeNode<int>* root,int k){
    if(k==0){
        cout<<root->data<<" ,";
        return;
    }
    for(int i=0;i<root->children.size();i++){
        printKthLevelElements(root->children[i],k-1);
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    cout<<endl;
    cout<<"Number Of Nodes : "<<numNodes(root)<<endl;

    cout<<"Height of Tree is : "<<height(root)<<endl;

    printKthLevelElements(root,2);
}