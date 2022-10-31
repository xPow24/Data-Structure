#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10001;
int up[MAXN][17], depth[MAXN];
vector<int> children[MAXN];
void bfs(int a) {
    for (int k : children[a]) {
        depth[k] = depth[a] + 1;
        up[k][0] = a;
        for (int i = 1; i <= 16; ++i) {
            up[k][i] = up[up[k][i - 1]][i - 1];
        }
        bfs(k);
    }
}
int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int cur = depth[a] - depth[b];
    for (int i = 16; i >= 0; --i) {
        if (cur & (1 << i)) a = up[a][i];
    }
    if (a == b) return a;
    for (int i = 16; i >= 0; --i) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, q, u, v, m; 
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        for (int j = 1; j <= m; ++j) {
            int x; cin >> x;
            children[i].push_back(x);
        }
        if (m) bfs(i);
    }
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}
