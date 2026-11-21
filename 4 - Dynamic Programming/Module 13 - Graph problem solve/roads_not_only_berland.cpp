#include<bits/stdc++.h>
using namespace std;

int leader[1005];
int group_size[1005];

int find(int node)
{
    if(leader[node] == -1) return node;
    int par = find(leader[node]);
    leader[node] = par;
    return par;
}

void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);

    if(group_size[leader1] >= group_size[leader2])
    {
        leader[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else 
    {
        leader[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main()
{
    vector <pair<int,int>> rmv;
    vector <pair<int,int>> create;
    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        leader[i] = -1;
        group_size[i] = 1;
    }

    for(int i=0; i<n-1; i++)
    {
        int a, b;
        cin >> a >> b;

        int leader1 = find(a);
        int leader2 = find(b);

        if(leader1 == leader2)
        {
            rmv.push_back({a,b});
        }
        else 
        {
            dsu_union(a,b);
        }
    }

    for(int i=2; i<=n; i++)
    {
        int leader2 = find(1);
        int leadern = find(i);
        if(leader2 != leadern)
        {
            create.push_back({leader2,leadern});
            dsu_union(leader2,leadern);
        }
    }

    cout << rmv.size() << endl;

    for(int i=0; i<rmv.size(); i++)
    {
        cout << rmv[i].first << " " << rmv[i].second << " " << create[i].first << " " << create[i].second << endl;
    }

}