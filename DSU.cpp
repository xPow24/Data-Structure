struct DSU {
  vector<int> sz, par;
  DSU(int N) : color(N + 1), sz(N + 1), par(N + 1) {};
  void make_set(int v) {
    sz[v] = 1;
    par[v] = v;
  }
  int find_set(int v) {
    if (par[v] == v) return v;
    return par[v] = find_set(par[v]);
  }
  void join_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u != v) {
      if (sz[u] < sz[v]) swap(u, v);
      par[v] = u;
      sz[u] += sz[v];
    }
  }
};
