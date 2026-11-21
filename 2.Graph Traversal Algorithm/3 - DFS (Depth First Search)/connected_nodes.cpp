#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj_list[n];
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }   

    int t;
    cin >> t;
    while(t--)
    {
        int q;
        cin >> q;
        if(adj_list[q].empty()) cout << "-1";
        else 
        {
            sort(adj_list[q].begin(), adj_list[q].end(), greater<int>());
            for(int val : adj_list[q])
                cout << val << " ";
        }
        
        cout << endl;
    }

    return 0;
}