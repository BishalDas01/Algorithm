#include<bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
int r, c;

bool valid(int i, int j)
{
    if(i<0 || i>=r || j<0 || j>=c) return false;
    return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for(int i=0; i<4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] != '#')
            dfs(ci,cj);
    }
}

int main()
{
    cin >> r >> c;

    int si, sj, di, dj;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 'A')
            {
                si = i;
                sj = j;
            }

            else if(grid[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }
    memset(vis,false,sizeof(vis));

    dfs(si,sj);

    if(vis[di][dj]) cout << "YES";
    else cout << "NO";

    return 0;
}