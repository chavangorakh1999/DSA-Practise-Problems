#include "bstTakeInput.h"

class Node
{

public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

BinarySearchTreeNode<int> *arrayInput(int *arr, int startIndex, int endIndex)
{
    if (startIndex > endIndex)
    {
        return NULL;
    }

    int mid = (startIndex + endIndex) / 2;
    BinarySearchTreeNode<int> *root = new BinarySearchTreeNode<int>(arr[mid]);
    root->left = arrayInput(arr, startIndex, mid - 1);
    root->right = arrayInput(arr, mid + 1, endIndex);
    return root;
}

void printTree(BinarySearchTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinarySearchTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinarySearchTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " : ";
        BinarySearchTreeNode<int> *leftNode = front->left;
        if (leftNode != NULL)
        {
            cout << "L" << leftNode->data;
            pendingNodes.push(leftNode);
        }
        BinarySearchTreeNode<int> *rightNode = front->right;
        if (rightNode != NULL)
        {
            cout << "R" << rightNode->data;
            pendingNodes.push(rightNode);
        }
        cout << endl;
    }
}

vector<int> *rootToNodePath(BinarySearchTreeNode<int> *root, int data)
{

    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> *leftOutput = rootToNodePath(root->left, data);
    if (leftOutput != NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int> *rightOutput = rootToNodePath(root->right, data);
    if (rightOutput != NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else
    {
        return NULL;
    }
}

void binaryTreeToLL(BinarySearchTreeNode<int> *root)
{
    BinarySearchTreeNode<int> *current, *left, *temp;
    if (root == NULL || root->left == NULL && root->right == NULL)
    {
        return;
    }
    binaryTreeToLL(root->left);
    left = root->left;
    root->left = NULL;
    temp = root->right;
    root->right = left;
    current = root;
    while (current->right != NULL)
    {
        current = current->right;
    }
    if (temp != NULL)
    {
        current->right = temp;
        binaryTreeToLL(temp);
    }
    else
    {
        binaryTreeToLL(root->right);
    }
}

pair<Node*,Node*> bstToLL(BinarySearchTreeNode<int>*root){
    if(root==NULL){
        pair<Node*,Node*> output;
        output.first=NULL;
        output.second=NULL;
        return output;
    }
    Node* midNode=new Node(root->data);
    pair<Node*,Node*> leftOutput=bstToLL(root->left);
    pair<Node*,Node*> rightOutput=bstToLL(root->right);
    if(leftOutput.first!=NULL && leftOutput.second!=NULL){
        leftOutput.second->next=midNode;
    }
    if(rightOutput.first!=NULL && rightOutput.second!=NULL){
         midNode->next=rightOutput.first;
    }
    
     pair<Node*,Node*> result;
     result.first=leftOutput.first;
     result.second=rightOutput.second;
     return result;
}




int main()
{
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};

    BinarySearchTreeNode<int> *root = arrayInput(arr, 0, 6);
    printTree(root);
    vector<int> *result = rootToNodePath(root, 7);
    for (auto x : *result)
    {
        cout << x << " ";
    }
    // cout<<endl;
    // binaryTreeToLL(root);
    // while(root!=NULL){
    //     cout<<root->data<<" ";
    //     root=root->right;
    // }
    // preOrder(root);
     pair<Node*,Node*> res=bstToLL(root);
    while(res.first->next!=NULL){
        cout<<res.first->data<<" ";
        res.first=res.first->next;
    }
    delete result;
    delete root;
    return 0;
}