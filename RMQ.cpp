#include<bits/stdc++.h>
using namespace std;
int u, v, n, m, a[100005], r[230997][23];
void RMQ() {
  for (int i = 1; i <= n; i++) r[i][0] = a[i];
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      r[i][j] = min(r[i][j - 1], r[i + (1 << (j - 1))][j - 1]);
    }
  }
}
void solve() {
  RMQ();
  while (m--) {
     cin >> u >> v;
     int k = log2(v - u + 1);
     cout << min(r[u][k], r[v - (1 << k) + 1][k]) << endl;
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  solve();
}
