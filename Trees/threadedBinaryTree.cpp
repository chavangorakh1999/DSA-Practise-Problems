#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int rightBit;
    int leftBit;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        rightBit = 0;
        leftBit = 0;
    }
    ~Node()
    {
        delete left;
        delete right;
    }
};

void insertInorder(Node *root, Node *temp)
{
    if (root == NULL)
    {
        root = temp;
    }
    if (root->data > temp->data)
    {
        temp->right = root;
        temp->rightBit = 1;
        temp->left = root->left;
        temp->leftBit = 1;
        root->left = temp;
        root->leftBit = 0;
    }
    if (root->data < temp->data)
    {
        temp->right=root->right;
        temp->rightBit=root->rightBit;
        root->left=temp;
        root->leftBit=1;
        root->right=temp;     
    }
}

Node *helper(Node *root, int data)
{
    Node *temp = new Node(data);
    if (root == NULL)
    {
        Node *head = new Node(999);
        root = temp;
        head->left = root;
        head->leftBit = 1;
        head->right = head;
        head->rightBit = 1;
    }
    Node *dupliRoot=root;
    while(dupliRoot){
        if(dupliRoot->data > temp->data){
            dupliRoot=dupliRoot->left;
        }
        if(dupliRoot->data < temp->data){
            dupliRoot=dupliRoot->right;
        }
    }
    insertInorder(dupliRoot, temp);
    return root;
}

Node * inorder(Node * root){
    Node * position;
    if(root->rightBit==0){
        return root->right;
    }else{
        position=root->right;
        while(position->leftBit==1){
            position=position->left;
        }
        return position;
    }
}

void print(Node * root){
    Node *temp=root;
    while (1)
    {
        temp=inorder(root);
        if(temp==root) return;
        cout<<temp->data;
    }
    
}

int main()
{
    int n;
    cin >> n;
    Node*root;
    while(n--){
        int data;
        cin>>data;
        root=helper(root,data);
    }
    print(root);
    return 0;
}