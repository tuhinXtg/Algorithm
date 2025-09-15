#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m) return false;
    if(grid[i][j] == '-') return false;
    if(vis[i][j]) return false;
    return true;
}

int dfs(int si, int sj) {
    vis[si][sj] = true;
    int area = 1;
    for(auto dir : d) {
        int ci = si + dir.first;
        int cj = sj + dir.second;
        if(valid(ci, cj)) {
            area += dfs(ci, cj);
        }
    }
    return area;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    int minArea = INT_MAX;
    bool found = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(grid[i][j] == '.' && !vis[i][j]) {
                int area = dfs(i, j);
                minArea = min(minArea, area);
                found = true;
            }
        }
    }

    if(found) cout << minArea << "\n";
    else cout << -1 << "\n";

    return 0;
}
