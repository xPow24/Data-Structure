const int size = sqrt(N);

// sort query so that the sum of all abs(l[i] - l[i + 1]) + abs(r[i] - r[i + 1]) (i = 1 -> N - 1) is minimized.

// standard
struct Query {
  int l, r;
  bool operator < (const Query& A) const {
    return (A.l / size != l / size ? l / size < A.l / size : r < A.r);
  }
};


// hilbert curve

#define int long long

const int logn = 20;
const int maxn = 1 << logn;
 
int gilbertOrder(int x, int y) {
  const int logn = __lg(max(x, y) * 2 + 1) | 1;
  const int maxn = (1ll << logn) - 1;
  int res = 0;
  for (int s = 1ll << (logn - 1); s; s >>= 1) {
    bool rx = x & s, ry = y & s;
    res = (res << 2) | (rx ? ry ? 2 : 1 : ry ? 3 : 0);
    if (!rx) {
      if (ry) x ^= maxn, y ^= maxn;
      swap(x, y);
    }
  }
  return res;
}
 
struct Query {
  int l, r, idx;
  int ord;
	
  void calcOrder() {
    ord = gilbertOrder(l, r);
  }

  bool operator < (const Query& A) const {
    return ord < A.ord;
  }
};



