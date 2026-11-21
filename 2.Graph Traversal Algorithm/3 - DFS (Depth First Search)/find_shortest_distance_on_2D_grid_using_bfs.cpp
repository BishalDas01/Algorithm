#include<bits/stdc++.h>
using namespace std;

bool vis[105][105];
vector <pair<int,int>> d = {{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2}};
int r, c;
int level[105][105];

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
    level[si][sj] = 0;

    while(!q.empty())
    {
        pair<int,int> par = q.front();
        q.pop();

        for(int i=0; i<8; i++)
        {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;
            if(valid(ci,cj) && !vis[ci][cj])
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par.first][par.second] + 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> r >> c;

        int si, sj, di, dj;
        cin >> si >> sj >> di >> dj;

        memset(vis,false,sizeof(vis));
        memset(level,-1,sizeof(level));

        bfs(si,sj);

        cout << level[di][dj] << endl;
    }

    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// bool vis[8][8];
// vector <pair<int,int>> d = {{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2}};
// int r, c;
// int level[8][8];

// bool valid(int i, int j)
// {
//     if(i<0 || i>=r || j<0 || j>=c) return false;
//     return true;
// }

// void bfs(int si, int sj)
// {
//     queue<pair<int,int>> q;
//     q.push({si,sj});
//     vis[si][sj] = true;
//     level[si][sj] = 0;

//     while(!q.empty())
//     {
//         pair<int,int> par = q.front();
//         q.pop();

//         for(int i=0; i<8; i++)
//         {
//             int ci = par.first + d[i].first;
//             int cj = par.second + d[i].second;
//             if(valid(ci,cj) && !vis[ci][cj])
//             {
//                 q.push({ci,cj});
//                 vis[ci][cj] = true;
//                 level[ci][cj] = level[par.first][par.second] + 1;
//             }
//         }
//     }
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         cin >> r >> c;

//         int si, sj, di, dj;
//         cin >> si >> sj >> di >> dj;

//         memset(vis,false,sizeof(vis));
//         memset(level,-1,sizeof(level));

//         bfs(si,sj);

//         cout << level[di][dj] << endl;
//     }

//     return 0;
// }
