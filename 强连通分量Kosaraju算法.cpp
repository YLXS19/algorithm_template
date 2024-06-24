//强连通分量Kosaraju算法
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int h[2][20010], ne[2][100010], to[2][100010];
int f[20010], q[20010], t;
int scc[20010], siz[20010], cnt;
bool vis[20010];
set<int> ans[20010];
void dfs1(int x){
	vis[x] = 1;
	for(int i =  h[0][x]; i; i = ne[0][i]){
		if(!vis[to[0][i]]) dfs1(to[0][i]);
	}
	q[++t] = x;
}
void dfs2(int x, int y){
	vis[x] = 0;
	f[x] = y;
	scc[x] = cnt;
	++siz[cnt];
	ans[cnt].insert(x);
	for(int i =  h[1][x]; i; i = ne[1][i]){
		if(vis[to[1][i]]) dfs2(to[1][i], y);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, i;
	cin >> n >> m;
	for(i = 1; i <= m; ++i){
		int u, v;
		cin >> u >> v;
		ne[0][i] = h[0][u];
		h[0][u] = i;
		to[0][i] = v;
		ne[1][i] = h[1][v];
		h[1][v] = i;
		to[1][i] = u;
	}
	for(t = 0, i = 1; i <= n; ++i){
		if(!vis[i]) dfs1(i);
	}
	for(i = n; i >= 1; --i){
		if(vis[q[i]]){
			++cnt;
			dfs2(q[i], q[i]);
		}
	}
	int ans = 0;
	for(i = 1; i <= cnt; ++i){
		if(siz[i] > 1) ++ans;
	}
	cout << ans;
	// cout << cnt << endl;
	// for(i = 1; i <= n; ++i){
		// if(!vis[scc[i]]){
			// vis[scc[i]] = 1;
			// for(int y : ans[scc[i]]){
				// cout << y << " ";
			// }
			// cout << endl;
		// }
	// }
}