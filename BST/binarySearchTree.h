#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinarySearchTreeNode{
    public:
    T data;
    BinarySearchTreeNode<T> * left;
    BinarySearchTreeNode<T> * right;

    BinarySearchTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinarySearchTreeNode(){
        delete left;
        delete right;
    }
};