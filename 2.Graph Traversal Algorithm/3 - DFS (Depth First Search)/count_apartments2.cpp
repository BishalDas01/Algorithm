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

void dfs(int si, int sj,  int &count)
{
    vis[si][sj] = true;
    count++;

    for(int i=0; i<4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj]=='.')
        {
            dfs(ci,cj,count);
        }
    }
}


int main()
{
    cin >> r >> c;

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin >> grid[i][j];
    
    memset(vis,false,sizeof(vis));
    vector<int> v;
    
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            int count = 0;
            if(grid[i][j]=='.'  && !vis[i][j])
            {
                dfs(i,j, count);
                v.push_back(count);
            }
        }
    }

    if(v.empty()) cout << "0";

    else
    {
    sort(v.begin(),v.end());
    for(int val : v)
    {
        cout << val << " ";
    }
    }
    

    return 0;
}