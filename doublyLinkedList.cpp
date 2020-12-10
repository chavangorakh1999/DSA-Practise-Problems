#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int data){
        this->data = data;
        next=NULL;
        prev=NULL;
}                   
};


Node * takeInput(){
    
    Node *head=NULL,*temp=NULL;
    int data;
    cin>>data;
    
   while (data != -1)
   {
       Node *newNode= new Node(data);
    
       if(head==NULL){
           head=newNode;
           temp=head;
       }
       else
       {
            newNode->prev=temp;
            temp->next=newNode;
            temp=newNode; 
       }
       cin>>data;
       
   }

   return head;
}

void print(Node* head){
    while(head->next!=NULL){
        head=head->next;
    }
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->prev;
    }
}

int main(){
    Node* head=takeInput();
    print(head);

    return 0;
}