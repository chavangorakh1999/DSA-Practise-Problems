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

Node * insertInorder(Node *root, Node *temp)
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
        
    }
    if (root->data < temp->data)
    {
        temp->right=root->right;
        temp->rightBit=root->rightBit;
        root->left=temp;
        root->leftBit=1;
        root->right=temp;
    }
    return root;
}
static Node *head = new Node(999);

Node *helper(Node *root, int data)
{
    Node *temp = new Node(data);
    if (root == NULL)
    {
        root = temp;
        head->left = root;
        head->leftBit = 1;
        head->right = head;
        head->rightBit = 1;
        return root;
    }
    Node *dupliRoot=root;
    while(dupliRoot){
        if(dupliRoot->data > temp->data){
            
            if(dupliRoot->left!=NULL && dupliRoot->rightBit==0){
                dupliRoot=dupliRoot->left;
            }else{
                break;
            }
            
        }
        if(dupliRoot->data < temp->data){
            if(dupliRoot->right!=NULL  && dupliRoot->leftBit==0){
                dupliRoot=dupliRoot->right;
            }else{
                break;
            }
        }
    }
    if (dupliRoot->data > temp->data)
    {
        temp->right = dupliRoot;
        temp->rightBit = 1;
        temp->left = dupliRoot->left;
        temp->leftBit = 1;
        dupliRoot->left = temp;
        dupliRoot->leftBit=0;
    }
    if (dupliRoot->data < temp->data)
    {
        temp->right=dupliRoot->right;
        temp->rightBit=dupliRoot->rightBit;
        temp->left=dupliRoot;
        temp->leftBit=1;
        dupliRoot->right=temp;
    }
    return root;
}


int main()
{
    int n;
    cin >> n;
    Node*root=NULL;
    while(n--){
        int data;
        cin>>data;
        root=helper(root,data);
    }
   
    return 0;
}
