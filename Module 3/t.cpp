#include <bits/stdc++.h>
using namespace std;

vector<int> adj_mat[1005];
bool vis[1005];

void dfs(int src, vector<int> &nodes)
{
    vis[src] = true;
    nodes.push_back(src);

    for (int child : adj_mat[src])
    {
        if (!vis[child])
            dfs(child, nodes);
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_mat[a].push_back(b);
        adj_mat[b].push_back(a);  
    }

    int q;
    cin >> q;
    while (q--)
    {
        int node;
        cin >> node;

        memset(vis, false, sizeof(vis)); 
        vector<int> connected_nodes;

        for (int child : adj_mat[node])
        {
            if (!vis[child])
                dfs(child, connected_nodes);
        }

        if (connected_nodes.empty())
        {
            cout << -1 << "\n";
        }
        else
        {
            sort(connected_nodes.rbegin(), connected_nodes.rend());
            for (int x : connected_nodes)
                cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}
