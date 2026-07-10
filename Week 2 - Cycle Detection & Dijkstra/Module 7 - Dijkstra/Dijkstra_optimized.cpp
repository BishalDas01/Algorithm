#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj_list[105];
int dis[105];

void dijkstra(int src)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,src});
    dis[src] = 0;

    while(!pq.empty())
    {
        auto par = pq.top();
        pq.pop();

        for(auto child : adj_list[par.second])
        {
            if(child.second + par.first < dis[child.first])
            {
                dis[child.first] = child.second + par.first;
                pq.push({dis[child.first], child.first});
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