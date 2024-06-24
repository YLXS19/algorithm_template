//支配树Lengauer Tarjan
#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define M (N*4)
int n, m;
int h[2][N], ne[2][M], to[2][M];
int dfn[N], id[N], fa[N], in[N], tim;
int sdom[N], idom[N]; 
int anc[N], mn[N];
int deep[N], dp[N][21];
queue<int> q;
struct MAP{
	struct Edge{
		int to, ne;
	}e[M];
	int siz, h[N];
	void addEdge(int x, int y){
		e[++siz].to = y;
		e[siz].ne = h[x];
		h[x] = siz; 
	}
}dfsTree, dfsTreeF, dominate;
void dfs(int x){
	dfn[x] = ++tim;
	id[tim] = x;
	for(int i = h[0][x]; i; i = ne[0][i]){
		int y = to[0][i];
		if(!dfn[y]){
			dfs(y);
			fa[y] = x;
			dfsTree.addEdge(x, y);
		}
	}
}
int find(int x){
	if(x != anc[x]){
		int t = anc[x];
		anc[x] = find(anc[x]);
		if(dfn[sdom[mn[x]]] > dfn[sdom[mn[t]]]){
			mn[x] = mn[t];
		}
	}
	return anc[x];
}
int LCA(int x, int y){
	if(deep[x] < deep[y])swap(x, y);
	int d = deep[x] - deep[y];
	for(int i = 0; i <= 20; ++i){
		if((1 << i) & d){
			x = dp[x][i];
		}
	}
	if(x == y) return x;
	for(int i = 20; i >= 0; --i){
		if(dp[x][i] ^ dp[y][i]){
			x = dp[x][i];
			y = dp[y][i];
		}
	}
	return dp[x][0];
}
void buildDominate(int x){
	int to = dfsTreeF.e[dfsTreeF.h[x]].to;
	for(int i = dfsTreeF.h[x]; i; i = dfsTreeF.e[i].ne){
		int y = dfsTreeF.e[i].to;
		to = LCA(to, y);
	}
	deep[x] = deep[to] + 1;
	dp[x][0] = to;
	dominate.addEdge(to, x);
	for(int i = 1; i <= 20; ++i){
		dp[x][i] = dp[dp[x][i - 1]][i - 1];
	}
}
void dfsDominate(int x){
	idom[x] = 1;
	for(int i = dominate.h[x]; i; i = dominate.e[i].ne){
		int y = dominate.e[i].to;
		dfsDominate(y);
		idom[x] += idom[y];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; ++i){
		int u, v;
		cin >> u >> v;
		ne[0][i] = h[0][u];
		h[0][u] = i;
		to[0][i] = v;
		ne[1][i] = h[1][v];
		h[1][v] = i;
		to[1][i] = u;
	}
	for(int i = 1; i <= n; ++i)if(!dfn[i]) dfs(i);
	for(int i = 1; i <= n; ++i){
		sdom[i] = mn[i] = anc[i] = i;
	}
	for(int i = tim; i >= 2; --i){
		int x = id[i];
		int pos = i;
		for(int j = h[1][x]; j; j = ne[1][j]){
			int y = to[1][j];
			if(dfn[x] > dfn[y]){
				pos = min(pos, dfn[y]);
			}else{
				find(y);
				pos = min(pos, dfn[sdom[mn[y]]]);
			}
		}
		sdom[x] = id[pos];
		anc[x] = fa[x];
		dfsTree.addEdge(sdom[x], x);
	}
	for(int i = 1; i <= n; ++i){
		for(int j = dfsTree.h[i]; j; j = dfsTree.e[j].ne){
			int y = dfsTree.e[j].to;
			++in[y];
			dfsTreeF.addEdge(y, i);
		}
	}
	for(int i = 1; i <= n; ++i){
		if(!in[i]){
			++in[i];
			dfsTree.addEdge(0, i);
			dfsTreeF.addEdge(i, 0);
		}
	}
	q.push(0);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i = dfsTree.h[x]; i; i = dfsTree.e[i].ne){
			int y = dfsTree.e[i].to;
			if(!--in[y]){
				q.push(y);
				buildDominate(y);
			}
		}
	}
	dfsDominate(0);
	for(int i = 1; i <= n; ++i){
		cout << idom[i] << " ";
	}
	cout << endl;
}