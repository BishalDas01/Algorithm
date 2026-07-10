#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
bool vis[105] = {false};
int parent[105] = {-1};
bool flag;

void dfs(int src)
{
    vis[src] = true;
    for(int child : adj_list[src])
    {
        if(vis[child] && parent[src] != child)
            flag = true;

        if(!vis[child])
        {
            parent[child] = src;
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    flag = false;

    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }

    if(flag) cout  << "Cycle Detected";
    else cout << "No Cycle";

    return 0;
}