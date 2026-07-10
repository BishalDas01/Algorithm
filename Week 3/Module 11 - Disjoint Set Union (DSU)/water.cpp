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
        vector<int> h(n);
        for(int i=0; i<n; i++)
        {
            cin >> h[i];
        }

        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int mi1 , mi2;

        for(int i=0; i<n; i++)
        {
            if(max1 < h[i])
            {
                max1 = h[i];
                mi1 = i;
            }
        }

        // h.erase(h.begin()+mi1);


        for(int i=0; i<h.size(); i++)
        {
            if(max2 < h[i] && h[i]<max1)
            {
                max2 = h[i];
                mi2 = i;
            }
        }

        if(mi1>mi2) cout << mi2 << " " << mi1 << endl;
        else cout << mi1 << " " << mi2 << endl;
    }

    return 0;
}