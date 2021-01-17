#include<iostream>
using namespace std;

template<typename T>
class Node{
     public:
    T data;
    Node<T> *next;
   
    Node(T data){
        this->data=data;
        next=NULL;
    }
};

template<typename T>
class Queue {
    Node<T> *head;
    Node<T> *tail;
    int size;
    public: 
    Queue(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    bool isEmpty(){ 
        return size==0;
    }
    int getSize(){
        return size;
    }
    void enqueue(T element){
        Node<T> *newNode=new Node<T>(element);
        if(isEmpty()){
            head=tail=newNode;
            size=1;
            return;
            
        }
        tail->next=newNode;
        tail=newNode;
        size++;
    }
    T front(){
        if(isEmpty()){ 
            cout<<"Queue Is Empty";
        return 0;
        }
        return head->data;
    }
    T dequeue(){
        if(isEmpty()){ 
            cout<<"Queue Is Empty";
        return 0;
        }
        Node<T> *temp=head;
        head=head->next;
        T ans=temp->data;
        delete temp;
        return ans;

    }

};