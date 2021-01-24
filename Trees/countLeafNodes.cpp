#include<bits/stdc++.h>
#include "tree.h"

int findLeafNode(TreeNode<int>* root){
    int leafNodes=0;
    if(root->children.size()==0){
        return leafNodes+=1;
    }
    for(int i=0;i<root->children.size();i++){
        leafNodes+=findLeafNode(root->children[i]);
    }
    
    return leafNodes;
}
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


int main(){
       TreeNode<int> *root = takeInputLevelWise();
    cout<<endl;
    cout<<"Leaf Nodes are : "<< findLeafNode(root);
    
}