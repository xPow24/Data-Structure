#include<bits/stdc++.h>
using namespace std;
int u, v, n, m, a[100005], r[230997][23];
void RMQ()
{
	int i, j;
	for (i = 1; i <= n; i++) r[i][0] = a[i];
	for (j = 1; (1 << j) <= n; j++) //1 << x tuc la dich bit 1 sang trai x lan, hay 1*2^x
	{
		for (i = 1; i + (1 << j) - 1 <= n; i++)
		{
			r[i][j] = min(r[i][j - 1], r[i + (1 << (j - 1))][j - 1]);
		}
	}
}
void solve()
{
	int k;
	RMQ();
	while (m--)
	{
		cin >> u >> v;
		k = log2(v - u + 1); //log2 duoc dung trong C++98 nen thoai mai
		cout << min(r[u][k], r[v - (1 << k) + 1][k]) << endl;
	}
}
int main()
{
  cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	solve();
}
