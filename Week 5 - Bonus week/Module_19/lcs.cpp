#include<bits/stdc++.h>
using namespace std;

string a, b, lcs_str;
int dp[1005][1005];

int lcs(int i, int j)
{
    if(i<0 || j<0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(a[i] == b[j])
    {
        lcs_str.push_back(a[i]);
        return dp[i][j] = lcs(i-1, j-1) + 1;
    }

    else 
    {
        int op1 = lcs(i-1, j);
        int op2 = lcs(i, j-1);
        return dp[i][j] = max(op1, op2);
    }
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> a >> b;
    cout << lcs(a.size()-1, b.size()-1) << endl;
    reverse(lcs_str.begin(), lcs_str.end());
    cout << lcs_str ;

    return 0;
}