#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int weight;
    int value;
};

int knapsack(int cap,const vector<Item> & items)
{
    int n = items.size();
    vector<vector<int>>  dp(n+1,vector<int>(cap+1,0));
    
    for(int i=1;i<=n;i++)
    {
        for(int w=0;w<=cap;w++)
        {
            if(items[i-1].weight<=w)
            {
                dp[i][w] = max(dp[i-1][w],items[i-1].value + dp[i-1][w-items[i-1].weight]);
            }
            else
            {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    return dp[n][cap];
}

int main()
{
    vector<Item> items = {{2, 12}, {1, 10}, {3, 20}, {2, 15}};
    int capacity = 5;

    int maxValue = knapsack(capacity, items);

    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;

}
