#include<iostream>
using namespace std;

template <typename T>
class queue{
T *data;
int frontIndex;
int nextIndex;
int size;
int capacity;
    public:
    queue(int givenSize){
        data=new T[size];
        frontIndex=-1;
        nextIndex=0;
        size=0;
        capacity=givenSize;
    }
    void enqueue(T value){
        if(size==capacity){
           T *newdata=new T[2*capacity];
           int j=0;
           for(int i=frontIndex;i<capacity;i++){
               newdata[j++]=data[i];
           }
           for(int i=0;i<frontIndex;i++){
               newdata[j++]=data[i];
           }
           delete [] data;
           data=newdata;
           frontIndex=0;
           nextIndex=capacity;
           capacity*=2;
        }
        data[nextIndex]=value;
        if(frontIndex==-1) frontIndex=nextIndex;
        nextIndex= (nextIndex + 1) % capacity; 
        size++;

    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    T dequeue(){
        if(isEmpty()){
            cout<<"Queue is Empty";
        }
        T ans=data[frontIndex];
        frontIndex =(frontIndex +1) % capacity;
        size--;
        if(size==0){
            frontIndex=-1;
            nextIndex=0;
        }
        return ans;

    }

};