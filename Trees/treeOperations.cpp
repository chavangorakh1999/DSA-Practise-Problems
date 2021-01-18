#include<bits/stdc++.h>
#include "tree.h"
using namespace std;

TreeNode<int>* takeInput(TreeNode<int>* root){

 
return root;
}

void printTree(TreeNode<int>* root){
    cout<<root->data<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}


int main(){
    TreeNode<int>* root=new TreeNode<int>(10);
}