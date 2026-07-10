#include<bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
int level[1005][1005];
pair<int, int> parnet[1005][1005];
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool valid(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=m) return false;
    return true;
}

void bfs(int si, int sj) 
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while(!q.empty())
    {
        auto par = q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            int ci = par.first + directions[i].first;
            int cj = par.second + directions[i].second;

            if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] != '#')
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                parnet[ci][cj] = {par.first,par.second};
                level[ci][cj] = level[par.first][par.second] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> grid[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    memset(parnet,-1,sizeof(parnet));

    int si,sj,di,dj;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            else if(grid[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }
    
    bfs(si,sj);

    if(vis[di][dj])
    {
        pair<int,int> nij = {di,dj};

        while(grid[nij.first][nij.second] != 'R')
        {
            if(grid[nij.first][nij.second] == 'D')
            {
                nij = parnet[nij.first][nij.second];
                continue;
            }
            grid[nij.first][nij.second] = 'X';
            nij = parnet[nij.first][nij.second];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}