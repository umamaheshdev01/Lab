#include <bits/stdc++.h>
using namespace std;

int getMax(vector<int> k)
{
    return *max_element(k.begin(),k.end());
}


void countingSort(vector<int> &A,int e)
{
    int n = A.size();
    vector<int> output(n);
    vector<int> count(10,0);
    
    for(int i=0;i<n;i++)
    {
        count[(A[i]/e)%10]++;
    }
    
    for(int i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }
    
    for(int i=n-1;i>=0;i--)
    {
        output[count[(A[i]/e)%10]-1] = A[i];
        count[(A[i]/e)%10]--;
    }
    
    for(int i=0;i<n;i++)
    {
        A[i] = output[i];
    }
}

void radixSort(vector<int> &A)
{
    int max = getMax(A);
    
    for(int e=1;max/e>0;e*=10)
    {
        countingSort(A,e);
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
    radixSort(A);
    for(auto x: A)
    {
        cout<<x<<" ";
    }
}
