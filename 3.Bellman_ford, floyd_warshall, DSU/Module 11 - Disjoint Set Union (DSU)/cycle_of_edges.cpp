#include<bits/stdc++.h>
using namespace std;

int leader[100005];
int group_size[100005];

int find(int node)
{
    if(leader[node] == -1)
    {
        return node;
    }

    int parent = find(leader[node]);
    leader[node] = parent;
    return parent;
}

void dsu_union(int a, int b)
{
    int leader1 = find(a);
    int leader2 = find(b);

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
    memset(leader,-1,sizeof(leader));
    memset(group_size,1,sizeof(group_size));

    int n, e;
    cin >> n >> e;
    
    int cycle = 0;

    while(e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = find(a);
        int leaderB = find(b);

        if(leaderA == leaderB) cycle++;
        else dsu_union(a,b);
    }

    cout << cycle;

    return 0;
}