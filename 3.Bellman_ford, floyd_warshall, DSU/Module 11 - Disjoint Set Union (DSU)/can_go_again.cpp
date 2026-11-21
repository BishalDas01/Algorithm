#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    long long a, b;
    long long c;
    Edge(long long a, long long b, long long c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

vector<Edge> edge_list;
long long dis[1005];

int main()
{
    long long n, e;
    cin >> n >> e;

    while (e--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    for (int i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
    }

    int src;
    cin >> src;
    dis[src] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            if (dis[ed.a] != LLONG_MAX && dis[ed.a] + ed.c < dis[ed.b])
            {
                dis[ed.b] = dis[ed.a] + ed.c;
            }
        }
    }

    bool cycle = false;

    for (auto ed : edge_list)
    {
        if (dis[ed.a] != LLONG_MAX && dis[ed.a] + ed.c < dis[ed.b])
        {
            cycle = true;
        }
    }

    if (cycle == true)
        cout << "Negative Cycle Detected";

    int t;
    cin >> t;
    while (t--)
    {
        long long d;
        cin >> d;

        if(cycle == true) continue;
        else if(dis[d] == LLONG_MAX) cout << "Not Possible" << endl;
        else cout << dis[d] << endl;
    }

    return 0;
}