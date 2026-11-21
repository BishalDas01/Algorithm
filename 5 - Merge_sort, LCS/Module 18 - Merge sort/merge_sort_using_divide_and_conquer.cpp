#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int l, int mid, int r)
{
    int n = mid - l + 1;
    vector<int> left(n);
    int k = l;
    for(int i=0; i<n; i++)
    {
        left[i] = v[k];
        k++;
    }

    int m = r - mid;
    vector<int> right(m);
    k = mid+1;
    for(int i=0; i<m; i++)
    {
        right[i] = v[k];
        k++;
    }

    int i=0, j=0, curr=l;
    while(i<n && j<m)
    {
        if(left[i] < right[j])
        {
            v[curr] = left[i];
            curr++;
            i++;
        }
        else 
        {
            v[curr] = right[j];
            curr++;
            j++;
        }
    }

    while(i<n)
    {
        v[curr] = left[i];
        i++;
        curr++;
    }

    while(j<m)
    {
        v[curr] = right[j];
        j++;
        curr++;
    }
}

void mergeSort(vector<int> &v, int l, int r)
{
    if(l >= r) return;

    int mid = (l+r) / 2;
    mergeSort(v, l, mid);
    mergeSort(v, mid+1, r);
    merge(v, l, mid, r);
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter " << n << " elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
    }
    
    mergeSort(v, 0, n-1);

    for(int val : v)
    {
        cout << val << " ";
    }

    return 0;
}








// #include<bits/stdc++.h>
// using namespace std;

// void conquer(vector<int> &c, int l, int mid, int r)
// {
//     int n = mid - l + 1;
//     int left[n];
//     int k = l;
//     for(int i=0; i<n; i++)
//     {
//         left[i] = c[k];
//         k++;
//     }

//     int m = r - mid;
//     int right[m];
//     k = mid+1;
//     for(int i=0; i<m; i++)
//     {
//         right[i] = c[k];
//         k++;
//     }

//     int i=0, j=0, curr=l;
//     while(i<n && j<m)
//     {
//         if(left[i] < right[j])
//         {
//             c[curr] = left[i];
//             i++;
//             curr++;
//         }

//         else 
//         {
//             c[curr] = right[j];
//             j++;
//             curr++;
//         }
//     }

//     while(i<n)
//     {
//         c[curr] = left[i];
//         i++;
//         curr++;
//     }

//     while(j<m)
//     {
//         c[curr] = right[j];
//         j++;
//         curr++;
//     }
// }

// void divide(vector<int> &v, int l, int r)
// {
//     if(l>=r) return;

//     int mid = (l+r) / 2;
//     divide(v, l, mid);
//     divide(v, mid+1, r);
//     conquer(v, l, mid, r);
// }

// int main()
// {
//     int n;
//     cout << "koliza, Enter the size of array: ";
//     cin >> n;
//     vector<int> v(n);
//     cout << "Meri jaan, Enter " << n << " elements: ";
//     for(int i=0; i<n; i++)
//     {
//         cin >> v[i];
//     }
    
//     divide(v, 0, n-1);

//     for(int i=0; i<n; i++)
//     {
//         cout << v[i] << " ";
//     }

//     return 0;
// }