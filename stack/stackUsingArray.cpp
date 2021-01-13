#include <bits/stdc++.h>
using namespace std;

class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;

    public:

   StackUsingArray(){
        data=new int[4];
        nextIndex=0;
        capacity=4;
    }

    void push(int val){
        if(nextIndex == capacity){
            int *newData=new int[2 * capacity];
            for(int i=0;i<capacity;i++){
                newData[i]=data[i];
            }
            delete [] data;
            data=newData;
            capacity *= 2;
        }
        data[nextIndex]=val;
        nextIndex++;
    }
    int pop(){

        if(isEmpty()){
            cout<<"Stack is Empty";
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }
    int size(){
        return nextIndex;
    }

    bool isEmpty(){
        return nextIndex == 0;
    }
    int top(){
          if(isEmpty()){
            cout<<"Stack is Empty";
            return INT_MIN;
        }
        return data[nextIndex-1];
    }
};


