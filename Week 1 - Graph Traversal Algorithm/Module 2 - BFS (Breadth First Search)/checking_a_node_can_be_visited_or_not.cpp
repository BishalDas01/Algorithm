#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005] = {false};

void bfs(int src)
{
    queue <int> q;
    q.push(src);
    vis[src] = true;

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

    int src, dst;
    cin >> src >> dst;

    bfs(src);

    if(vis[dst]) cout << "YES";
    else cout << "NO";

    return 0;
}