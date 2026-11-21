#include<bits/stdc++.h>
using namespace std;

int value[1005], weight[1005];

int knapsack(int i, int cap)
{
    if(i<0 || cap<=0) return 0;

    if(weight[i] <= cap)
    {
        int op1 = knapsack(i-1, cap - weight[i]) + value[i];
        int op2 = knapsack(i-1, cap);
        return max(op1, op2);
    }

    else 
    {
        return knapsack(i-1, cap);
    }
}

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter " << n << " values: ";
    for(int i=0; i<n; i++)
        cin >> value[i];

    cout << "Enter " << n << " weights: ";
    for(int i=0; i<n; i++)
        cin >> weight[i];
    
    int cap;
    cout << "Enter the capacity: ";
    cin >> cap;

    int maxValue = knapsack(n-1, cap);

    cout << maxValue;

    return 0;
}