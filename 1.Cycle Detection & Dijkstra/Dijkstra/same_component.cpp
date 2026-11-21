#include<bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};

void dfs(int si, int sj)
{
    vis[si][sj] = true;

    for(int i=0; i<4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if(!vis[ci][cj] && grid[ci][cj]=='.')
        {
            dfs(ci,cj);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> grid[i][j];
        }
    }
    memset(vis,false,sizeof(vis));

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    dfs(si,sj);

    if(vis[di][dj]) cout << "YES";
    else cout << "NO";

    return 0;
}