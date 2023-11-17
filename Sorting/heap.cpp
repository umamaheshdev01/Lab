#include <bits/stdc++.h>
using namespace std;

// Max Heap

void maxHeapify(vector<int> & heap,int n,int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left<n && heap[largest]<heap[left])
    {
        largest = left;
    }
    
    if(right<n && heap[largest]<heap[right])
    {
        largest = right;
    }
    
    if(i != largest)
    {
        swap(heap[i],heap[largest]);
        maxHeapify(heap,n,largest);
    }
}

void buildMaxHeap(vector<int> &heap)
{
    int n =  heap.size();
    
    for(int i= n/2 - 1;i>=0;i--)
    {
        maxHeapify(heap,n,i);
    }
}

void heapSort_1(vector<int> &heap)
{
    int n = heap.size();
    
    for(int i=n-1;i>=0;i--)
    {
        swap(heap[0],heap[i]);
        maxHeapify(heap,i,0);
    }
}

// Min Heap

void minHeapify(vector<int> & heap,int n,int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left<n && heap[smallest]>heap[left])
    {
        smallest = left;
    }
    
    if(right<n && heap[smallest]>heap[right])
    {
        smallest = right;
    }
    
    if(i != smallest)
    {
        swap(heap[i],heap[smallest]);
        minHeapify(heap,n,smallest);
    }
}

void buildMinHeap(vector<int> &heap)
{
    int n =  heap.size();
    
    for(int i= n/2 - 1;i>=0;i--)
    {
        minHeapify(heap,n,i);
    }
}

void heapSort_2(vector<int> &heap)
{
    int n = heap.size();
    
    for(int i=n-1;i>=0;i--)
    {
        swap(heap[0],heap[i]);
        minHeapify(heap,i,0);
    }
}

int main()
{
    cout<<"Enter the number of elements:";
    int n;
    cin>>n;
    
    vector<int> A(n);
    for(auto &x : A)
    {
        cin>>x;
    }
    
    cout<<"After sorting :"<<endl;
    heapSort_1(A);
    for(auto x: A)
    {
        cout<<x<<" ";
    }
}

