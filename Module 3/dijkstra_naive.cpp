#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,e;
    cin >> n >> e;
    vector<pair<int,int>> adj_lst[n];
    while (e--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        adj_lst[a].push_back({b,c});
        adj_lst[b].push_back({a,c}); 
    }
    for (int i = 0; i < n; i++)
        {
            cout << i << " -> ";
            for(pair<int,int> child : adj_lst[i])
            {
                cout << child.first << " " << child.second << " , ";
            }
            cout << endl;
        }
    return 0;
}