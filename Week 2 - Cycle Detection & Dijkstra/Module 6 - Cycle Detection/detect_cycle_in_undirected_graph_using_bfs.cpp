#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
bool vis[105] = {false};
int parent[105] = {-1};
bool flag;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] =  true;

    while(!q.empty())
    {
        int par = q.front();
        q.pop();

        for(int child : adj_list[par])
        {
            if(vis[child] && parent[par]!=child)
                flag = true;

            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                parent[child] = par;
            }
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
            bfs(i);
        }
    }

    if(flag) cout  << "Cycle Detected";
    else cout << "No Cycle";

    return 0;
}