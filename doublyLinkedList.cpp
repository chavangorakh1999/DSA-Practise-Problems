
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

Node *Delete(Node *head, int i)
{
    Node *temp = head;
    int count = 0;
    if (i == 0)
    {
        head = head->next;
        head->prev = NULL;
        delete temp;
        return head;
    }
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        Node *extra = temp->next;
        extra->next->prev = temp;
        temp->next = extra->next;
        delete extra;
    }
    return head;
}

Node *insert(Node *head, int i, int data)
{
    Node *newNode = new Node(data), *temp = head;
    int count = 0;
    if (head == NULL)
    {
        return NULL;
    }
    if (i == 0)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
    return head;
}

Node *takeInput()
{

    Node *head = NULL, *temp = NULL;
    int data;
    cin >> data;

    while (data != -1)
    {
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode;
        }
        cin >> data;
    }

    return head;
}

void print(Node *head)
{

    // while(head->next!=NULL){

    //     head=head->next;
    // }
    while (head != NULL)
    {
        cout << head->data << " ";
        // head=head->prev;
        head = head->next;
    }
}

Node *merge(Node *head1, Node *head2)
{
    Node *finalHead = NULL, *finalTail = NULL;
    if (head1 == NULL && head2 == NULL)
        return NULL;
    else if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;
    else
    {
        while (head1 != NULL && head2 != NULL)
        {
            if (head1->data >= head2->data)
            {
                if (finalHead == NULL)
                {
                    finalHead = head2;
                    finalTail = finalHead;
                    head2 = head2->next;
                }
                else
                {
                    finalTail->next = head2;
                    finalTail = finalTail->next;
                    head2 = head2->next;
                }
            }
            else
            {
                if (finalHead == NULL)
                {
                    finalHead = head1;
                    finalTail = finalHead;
                    head1 = head1->next;
                }
                else
                {
                    finalTail->next = head1;
                    finalTail = finalTail->next;
                    head1 = head1->next;
                }
            }
        }
        if(head2==NULL){
            finalTail->next=head1;
            finalTail=head1;
            // finalTail=finalTail->next;
        
        }else
        {
            finalTail->next=head2;
            finalTail=head2;
        }
        
        return finalHead;
    }
}


void splitList(Node* start, Node** ll1,Node** ll2) {
   //similar to flyod's tortoise algorithm
   Node* slow = start;
   Node* fast = start -> next;
   while(fast!= NULL) {
      fast = fast -> next;
      if(fast!= NULL) {
         slow = slow -> next;
         fast = fast -> next;
      }
   }
   *ll1 = start;
   *ll2 = slow -> next;
   //spliting
   slow -> next = NULL;
}

void mergeSort(Node **start){
     Node *head1,*head2;
    Node *head=*start;
     
    if ((head == NULL) || (head->next == NULL))
    {
       return;
    }
     splitList(head,&head1,&head2);
   
    mergeSort(&head1);
    mergeSort(&head2);

    *start=merge(head1,head2);
    return;
   
    
}

int main()
{
    int i, data;
    Node *head = NULL;
    head=takeInput();
    // Node *head1 = takeInput(), *head2 = takeInput();
    // print(head1);
    mergeSort(&head);
    cout << "\n";
    // cin>>i>>data;
    // cin>>i;
    // head=insert(head,i,data);
    // head=Delete(head,i);
    print(head);
    return 0;
}