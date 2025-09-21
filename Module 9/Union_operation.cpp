#include <bits/stdc++.h>
using namespace std;
int par[1005];
int grp_sz[1005]

int find(int node)
{
    if(par[node])
    {
        return true;
    }
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}
void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if(grp_sz(leader1) > grp_sz(leader2))
    {
        par[leader2] = leader1;
        grp_sz[leader1] += grp_sz[leader2];
    }
    else
    {
        par[leader1] = leader2;
        grp_sz[leader2] += grp_sz[leader1];
    }
}
int main() {
    memset(par,-1,sizeof(par));
    memset(grp_sz,1,sizeof(grp_sz));
    dsu_union(1,2);
    for (int i = 0; i < 6; i++)
    {
        cout << i << " -> " << par[i] << endl;
    }
    
    return 0;
}