#include <iostream>
using namespace std;

template <typename T>
class Node {
	public:
		T data;
		Node<T> * next;

		Node(T data ){
			this->data=data;
			next=NULL;
		}
};
template <typename T>
class Stack{
	Node<T> * head;
	int size;
	public:
	Stack(){
		head=NULL;
		size=0;
	}

	int getSize(){
		return size;
	}
	bool isEmpty(){
		return size==0;
	}
	void push(T data){
		Node<T> *newNode= new Node<T>(data); 
		newNode->next=head;
		head=newNode;
		size++;
	}
	T pop(){
		T data=head->data;
		Node<T> *temp=head;
		head=head->next;
		delete temp;
		size--;
		return data;
	}
	T top(){
		return isEmpty()?0: head->data;
	}

};

