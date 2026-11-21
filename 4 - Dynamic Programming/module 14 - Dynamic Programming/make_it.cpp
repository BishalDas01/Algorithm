#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        bool flag = false;

        int i=1;
        while(i<=n)

        {
            if(i==n) 
            {
                flag = true;
                break;
            }
            else if(i*2<=n)
            {
                i *= 2;
            }
            else 

            {
                i += 3;
            }
        }

        if(flag == true) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}