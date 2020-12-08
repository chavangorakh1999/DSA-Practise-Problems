#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *takeInput()
{

    int data;
    Node *head = new Node;
    Node *tail = new Node;
    cin >> data;
    head = NULL;
    tail = NULL;
 
    while (data != -1)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }

    return head;
}

Node * insert(Node * head ,int i,int data)
{
    Node * newNode= new Node;
    Node *temp=head;
    newNode->data=data;
    int count=0; 
    if(i==0){
        newNode->next=head;
        head=newNode;
        return head;
    }
    while(temp != NULL && count<i-1 ){
        temp=temp->next;
        count++;
    }
    if(temp!=NULL){
    newNode->next=temp->next;
    temp->next=newNode;
    }
    return head;
}

Node * Delete(Node *head,int i){
    Node *temp;
    temp=head;
    if(i==0){
        head=head->next;
        delete temp;
        return head;
    }
    int count=0;
    while(temp != NULL && count < i-1){
        temp= temp->next;
        count++;
    }
    if(temp!=NULL){
    Node *extra =temp->next;
    temp->next=extra->next;
    delete extra;
    }
    return head;
}

int len(Node *head){
    int val=0;
    if(head!=NULL){
     val=len(head->next)+1;
    }
    return val;
}

Node * recInsert(Node *head,int i,int data)
{
    Node * newNode= new Node;
    newNode->data=data;
    Node *temp;
     if(head==NULL){
        return head;
    }
    if(i==0){
        newNode->next=head;
        head=newNode;
        return head;
    }
    
    temp=recInsert(head->next,i-1,data);
    head->next=temp;
    return head;
}

Node * recDelete(Node *head,int i){
    Node *temp=head;
    Node *sec;
    if(head==NULL){
       
        return NULL;
    }
    if(i==0){
        head=head->next;
        delete temp;
        return head;
    }

    sec= recDelete(head->next,i-1);
    head->next=sec;
    return head;

}

int main()
{

    Node *head = takeInput();
    print(head);
    cout<<"\n";
    int i,data;
    // cin>>i>>data;
    cin>>i;
    // head=insert(head,i,data);
    head=recDelete(head,i);
    // head= recInsert(head,i,data);
    print(head);

    cout<<endl<<len(head);
    return 0;
}