#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj_list[105];
int dis[105];

void dijkstra(int src)
{
    queue<pair<int,int>> q;
    q.push({src,0});
    dis[src] = 0;

    while(!q.empty())
    {
        auto par = q.front();
        q.pop();

        for(auto child : adj_list[par.first])
        {
            if(par.second + child.second < dis[child.first])
            {
                dis[child.first] = par.second + child.second;
                q.push({child.first, dis[child.first]});
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
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }

    for(int i=0; i<n; i++)
    {
        dis[i] = INT_MAX;
    }
    
    dijkstra(0);

    for(int i=0; i<n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }

    return 0;
}