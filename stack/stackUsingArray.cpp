#include <bits/stdc++.h>
using namespace std;

template <typename T>

class StackUsingArray{
    T *data;
    int nextIndex;
    int capacity;

    public:

   StackUsingArray(){
        data=new T[4];
        nextIndex=0;
        capacity=4;
    }

    void push(T val){
        if(nextIndex == capacity){
           T  *newData=new T[2 * capacity];
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
   	T  pop(){

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
    T  top(){
          if(isEmpty()){
            cout<<"Stack is Empty";
            return INT_MIN;
        }
        return data[nextIndex-1];
    }
};


