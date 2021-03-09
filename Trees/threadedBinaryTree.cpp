#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;
    int rightBit;
    int leftBit;

    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
        rightBit=0;
        leftBit=0;
    }
    ~Node(){
        delete left;
        delete right;
    }

};

void insert(Node* root,Node* temp){
    if(root->data > temp->data){
        if(root->left==NULL){
            root->left=temp;
            temp->left=root->left;
            temp->right=root;
            root->leftBit=1;
        }else{
            insert(root->left,temp);
        }
    }else if(root->data <temp->data){
        if(root->right==NULL){
            root->right=temp;
            temp->right=root->right;
            temp->left=root;
            root->rightBit=1;
        }else{
            insert(root->right,temp);
        }
    }
}
 Node* head= new Node(999);

void create(Node* root){
    int data;
    cin>>data;
    Node* temp=new Node(data);
    if(root==NULL){
        root=temp;
        head->right=head;
        head->rightBit=1;
        head->left=root;
        head->leftBit=1;
        root->left=head;
        root->right=head;
        
    }else{
        insert(root,temp);
    }
    
}

void preorder(Node* head){
    Node* temp= head->left;
    while(temp!=head){
        while(temp->leftBit!=0){
            cout<<temp->data;
            temp=temp->left;
        } 
        cout<<temp->data;
        while(temp->rightBit==0){
            temp=temp->right;
            if(temp==head){
                return;
            }
        }
        temp=temp->right;
    }
}


int main()
{
    int n;
    cin>>n;
    Node *root=NULL;
    while(n--){
        create(root);
    };
    preorder(head);

    return 0;
}