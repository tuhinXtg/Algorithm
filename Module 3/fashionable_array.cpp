#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a,a+n);
        int mn = a[0];
        int mx = a[n-1];
        if(mn%2 == 0 && mx%2 == 0)
            cout << 0 << endl;
        else 
        {
            int i = 0,cntmn = 0;
            while (a[i]%2 != mx%2)
            {
                i++;
                cntmn++;
            }
            int j = n-1,cntmx = 0;
            while (mn%2 != a[j]%2)
            {
                j--;
                cntmx++;
            }
            cout << min(cntmn,cntmx) << endl;
        }   
    }
    
    return 0;
}