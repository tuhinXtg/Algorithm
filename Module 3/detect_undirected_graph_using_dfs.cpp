#include <bits/stdc++.h>
using namespace std;
bool vis[105];
vector<int> adj_lst[105];
int parent[105];
bool cycle;
void dfs(int src)
{
    vis[src] = true;
    for (int child : adj_lst[src])
    {
        if(!vis[child])
        {
            dfs(child);
            parent[child] = src;
        }
    }
    
}
int main() {
    int n,e;
    cin >> n >> e;
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    while (e--)
    {
        int a,b;
        cin >> a >> b;
        adj_lst[a].push_back(b);
        adj_lst[b].push_back(a);
    }
    cycle = false;
    for (int i = 0; i < n; i++)
    {
        if(!vis[i])
            dfs(i);
    }
    if(cycle) cout << "Cycle detected" << endl;
    else cout << "No cycle" << endl;

    return 0;
}