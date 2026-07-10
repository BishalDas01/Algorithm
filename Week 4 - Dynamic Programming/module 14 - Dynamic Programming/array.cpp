#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int nums[n];

    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }

    int count[n] = {0};

    for(int i=0; i<n; i++)
    {
        count[nums[i]]++;
    }

    for(int i=0; i<n; i++)
    {
        if(count[i]>0)
        {
            if(count[i]==1)
            {
                cout << i;
            }
        }
    }

    return 0;
}