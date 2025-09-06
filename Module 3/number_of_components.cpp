#include <bits/stdc++.h>
using namespace std;
vector<int> adj_mat[1005];
bool vis[1005];

void dfs(int src)
{
    cout << src << " ";
    vis[src] = true;
    for (int child : adj_mat[src])
    {
        if(vis[child] == false)
            dfs(child);
    }
}
int main() {
    int n,e ;
    cin >> n >> e;
    while (e--)
    {
        int a,b;
        cin >> a >> b;
        adj_mat[a].push_back(b);
        adj_mat[b].push_back(a);   
    }
    memset(vis,false,sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
            cout << endl;
        }
    }
    
    return 0;
}