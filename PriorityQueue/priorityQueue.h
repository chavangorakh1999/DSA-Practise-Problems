#include <vector>
#include <iostream>
using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getSize()
    {
        return pq.size();
    }
    int getMin()
    {

        if (isEmpty())
        {
            return 0;
        }
        return pq[0];
    }

    void insert(int val)
    {
        pq.push_back(val);

        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[parentIndex] > pq[childIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }
    void display(){
        for(int i=0;i<pq.size();i++){
            cout<<pq[i]<<" ";
        }
    }
    int removeMin(){
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        
        int minIndex,leftChildIndex,rightChildIndex,parentIndex=0;
        leftChildIndex=parentIndex+1;
        rightChildIndex=parentIndex+2;

        return ans;
    }
};