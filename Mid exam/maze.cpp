#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> d = {{1,0},{-1,0},{0,1},{0,-1}};
int si, sj;

bool valid(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m) return false;
    if(grid[i][j] == '#') return false;
    if(vis[i][j]) return false;
    return true;
}

bool dfs(int si, int sj) {
    vis[si][sj] = true;

    if(grid[si][sj] == 'D') 
        return true;

    for (int k = 0; k < 4; k++) {
        int ci = si + d[k].first;
        int cj = sj + d[k].second;

        if(valid(ci, cj)) {
            if(dfs(ci, cj)) {
                if(grid[si][sj] == '.')
                    grid[si][sj] = 'X'; 
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'R') {
                si = i;
                sj = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    dfs(si, sj);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}
