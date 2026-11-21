#include<bits/stdc++.h>
using namespace std;
vector <int> adj_list[1005];
bool vis[1005] = {false};

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vis[source] = true;

    while(!q.empty())
    {
        int val = q.front();
        q.pop();

        cout << val << " ";

        for(int cnct : adj_list[val])
        {
            if(!vis[cnct])
            {
                q.push(cnct);
                vis[cnct] = true;
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

    bfs(0);

    return 0;
}