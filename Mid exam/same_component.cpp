#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m;

bool valid(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m) return false;
    if(grid[i][j] == '-') return false; 
    return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int k = 0; k < 4; k++)
    {
        int ci = si + d[k].first;
        int cj = sj + d[k].second;
        if(valid(ci, cj) && !vis[ci][cj])
        {
            dfs(ci, cj);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    int si, sj, di, dj;
    cin >> si >> sj;
    cin >> di >> dj;

    if (grid[si][sj] == '-' || grid[di][dj] == '-') {
        cout << "NO\n";
        return 0;
    }

    dfs(si, sj);

    if (vis[di][dj]) 
        cout << "YES\n";
    else 
        cout << "NO\n";

    return 0;
}
