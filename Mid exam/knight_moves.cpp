#include <bits/stdc++.h>
using namespace std;

bool vis[105][105];
int n, m;

bool isValid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m && !vis[i][j]);
}

vector<pair<int,int>> d = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

int bfs(int si, int sj, int ci, int cj) {
    queue<array<int,3>> q; 
    q.push({si, sj, 0});
    vis[si][sj] = true;

    while (!q.empty()) {
        auto [x, y, steps] = q.front();
        q.pop();

        if (x == ci && y == cj) return steps;

        for (auto mv : d) {
            int nx = x + mv.first;
            int ny = y + mv.second;
            if (isValid(nx, ny)) {
                vis[nx][ny] = true;
                q.push({nx, ny, steps + 1});
            }
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int ki, kj, qi, qj;
        cin >> ki >> kj >> qi >> qj;

        memset(vis, false, sizeof(vis));
        cout << bfs(ki, kj, qi, qj) << "\n";
    }
}
