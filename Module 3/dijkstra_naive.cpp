#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj_lst[105];
int dis[105];

void dijkstra(int src)
{
    queue<pair<int,int>> q;
    q.push({src,0});
    dis[src] = 0;
    while (!q.empty())
    {
        pair<int,int> par = q.front();
        q.pop();
        int par_node = par.first;
        int par_distance = par.second;
        for(auto child : adj_lst[par_node])
        {
            int child_node = child.first;
            int child_distance = child.second;
            if(par_distance + child_distance < dis[child_node])
            {
                dis[child_node] = par_distance + child_distance;
                q.push({child_node, dis[child_node]});
            }
        }
    }
    
}
int main() {
    int n,e;
    cin >> n >> e;
    while (e--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        adj_lst[a].push_back({b,c});
        adj_lst[b].push_back({a,c}); 
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        cout << i <<" -> "<< dis[i] <<  endl;
    }
    return 0;
}