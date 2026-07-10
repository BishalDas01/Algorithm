#include<bits/stdc++.h>
using namespace std;

char grid[105][105];
bool vis[105][105] = {false};
vector <pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
int r, c;

bool valid(int i, int j)
{
    if(i<0 || i>=r || j<0 || j>=c) return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;

    while(!q.empty())
    {
        pair<int,int> par = q.front();
        q.pop();

        cout << par.first << " " << par.second << endl;

        for(int i=0; i<4; i++)
        {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;
            if(valid(ci,cj) && !vis[ci][cj])
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
            }
        }
    }
}

int main()
{
    cin >> r >> c;
    
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin >> grid[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;
    bfs(si,sj);

    return 0;
}