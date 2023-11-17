#include <bits/stdc++.h>
using namespace std;

typedef double d;

void merge(vector<d> & A,int left,int middle,int right)
{
    // Create two array and split it into left and right
    
    int n1 = middle-left+1;
    int n2 = right-middle;
    
    vector<d> lefta(n1);
    vector<d> righta(n2);
    
    for(int i=0;i<n1;i++)
    {
        lefta[i]=A[left+i];
    }
    
    for(int i=0;i<n2;i++)
    {
        righta[i]=A[middle+i+1];
    }
    
    //start merging the arrays
    
    int i=0,j=0,k=left;
    while(i<n1 && j<n2)
    {
        if(lefta[i]<righta[j])
        {
            A[k++]=lefta[i++];
        }
        else
        {
            A[k++]=righta[j++];
        }
    }
    
    //fill the remaining 
    
    while(i<n1)
    {
        A[k++]=lefta[i++];
    }
    
    while(j<n2)
    {
        A[k++]=righta[j++];
    }
    
}

void mergeSort(vector<d> &A,int left,int right)
{
    if(left<right)
    {
        //divide
        
        int middle = (right+left)/2;
        mergeSort(A,left,middle);
        mergeSort(A,middle+1,right);
        
        //conquer
        
        merge(A,left,middle,right);
    }
}

int main()
{
    cout<<"Enter the number of elements:";
    int n;
    cin>>n;
    
    vector<d> A(n);
    for(auto &x : A)
    {
        cin>>x;
    }
    
    cout<<"After sorting :"<<endl;
    mergeSort(A,0,A.size()-1);
    for(auto x: A)
    {
        cout<<x<<" ";
    }
}

