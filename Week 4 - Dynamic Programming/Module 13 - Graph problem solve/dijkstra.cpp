#include<bits/stdc++.h>
using namespace std;

#define ll long long int 

vector<pair<ll ,ll >> adj_list[100005];
ll  dis[100005];
ll parent[100005];

void dijkstra(ll  src)
{
    priority_queue<pair<ll ,ll >, vector<pair<ll ,ll >>, greater<pair<ll ,ll >>> pq;

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
                parent[child.first] = par.second;
            }
        }
    }
}

int main()
{
    ll  n, e;
    cin >> n >> e;

    while(e--)
    {
        ll  a, b, c;
        cin >> a >> b >> c;

        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }

    for(ll  i=1; i<=n; i++)
    {
        dis[i] =  LLONG_MAX;
        parent[i] = -1;
    }
        

    dijkstra(1);

    if(dis[n] == LLONG_MAX)
        cout << -1 << endl;

    else 
    {
        int node = n;
        vector <ll> path;
        while(node != -1)
        {
            path.push_back(node);
            node = parent[node];
        }

        reverse(path.begin(), path.end());

        for(ll value : path)
        {
            cout << value << " " ;
        }
    }

    return 0;
}