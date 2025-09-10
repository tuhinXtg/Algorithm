#include <bits/stdc++.h>
using namespace std;

vector<int> adj_mat[1005];

int main() {
    int n, e;
    cin >> n >> e;

    while (e--) {
        int a, b;
        cin >> a >> b;
        adj_mat[a].push_back(b); 
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        bool found = false;

        if (a == b) {
            found = true; 
        } else {
            for (int child : adj_mat[a]) {
                if (child == b) {
                    found = true;
                    break;
                }
            }
        }

        if (found) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
