#include <bits/stdc++.h>
using namespace std;
bool vis[105];
vector<int> adj_lst[105];
bool pathvis[105];
bool cycle;
void dfs(int src)
{
    vis[src] = true;
    pathvis[src] = true;
    for (int child : adj_lst[src])
    {
        if(!vis[child])
        {
            dfs(child);
        }
        else if(pathvis[child])
        {
            cycle = true;
        }
    }
    pathvis[src] = false;
}
int main() {
    int n,e;
    cin >> n >> e;
    memset(vis,false,sizeof(vis));
    memset(pathvis,false,sizeof(pathvis));
    while (e--)
    {
        int a,b;
        cin >> a >> b;
        adj_lst[a].push_back(b);
    }
    cycle = false;
    for (int i = 0; i < n; i++)
    {
        if(!vis[i])
            dfs(i);
    }
    if(cycle) 
        cout << "Cycle detected" << endl;
    else 
        cout << "No cycle" << endl;

    return 0;
}