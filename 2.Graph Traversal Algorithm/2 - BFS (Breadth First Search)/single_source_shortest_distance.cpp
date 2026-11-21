#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005] = {false};
int level[1005];

void bfs(int src)
{
    queue <int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while(!q.empty())
    {
        int val = q.front();
        q.pop();

        for(int v : adj_list[val])
        {
            if(!vis[v])
            {
                q.push(v);
                vis[v] = true;
                level[v] = level[val] + 1;
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

    memset(level,-1,sizeof(level));

    int src, dst;
    cin >> src >> dst;

    bfs(src);

    cout << level[dst];

    return 0;
}