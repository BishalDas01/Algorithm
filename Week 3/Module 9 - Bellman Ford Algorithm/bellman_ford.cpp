#include<bits/stdc++.h>
using namespace std;

class Edge
{
    public:
    int a;
    int b;
    int c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

vector<Edge> edge_list;
int dis[1005];

int main()
{
    int n, e;
    cin >> n >> e;

    while(e--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a,b,c));
    }

    for(int i=0; i<n; i++)
    {
        dis[i] = INT_MAX;
    }

    dis[0] = 0;

    for(int i=0; i<n-1; i++)
    {
        for(auto ed : edge_list)
        {
            if(dis[ed.a] + ed.c < dis[ed.b] && dis[ed.a]!=INT_MAX)
            {
                dis[ed.b] = dis[ed.a] + ed.c;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }

    return 0;
}