//2-sat
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000010
#define M 1000010
int n, m;
int h[2][N << 1], to[2][M << 1], ne[2][M << 1], cn;
bool vis[N << 1];
int q[N << 1], t;
int scc[N << 1], siz[N << 1], cnt;
int ans[N];
void dfs1(int x){
	vis[x] = 1;
	for(int i =  h[1][x]; i; i = ne[1][i]){
		if(!vis[to[1][i]]) dfs1(to[1][i]);
	}
	q[++t] = x;
}
void dfs2(int x){
	vis[x] = 0;
	scc[x] = cnt;
	++siz[cnt];
	for(int i =  h[0][x]; i; i = ne[0][i]){
		if(vis[to[0][i]]) dfs2(to[0][i]);
	}
}
void dfs(int x){
	vis[x] = 1;
	if(x > n){
		vis[x - n] = 1;
		ans[x - n] = 1;
	}else{
		vis[x + n] = 1;
		ans[x] = 0;
	}
	for(int i =  h[0][x]; i; i = ne[0][i]){
		if(!vis[to[0][i]]) dfs(to[0][i]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i;
	cin >> n >> m;
	bool flag = 0;
	for(int i = 1; i <= m; ++i){
		int x, y, jx, jy, nx, ny;
		cin >> x >> jx >> y >> jy;
		if(jx){
			nx = x;
		}else{
			nx = x + n;
		}
		if(jy){
			ny = y;
		}else{
			ny = y + n;
		}
		int yy = y + jy * n;
		int yx = x + jx * n;
		ne[0][++cn] = h[0][nx];
		h[0][nx] = cn;
		to[0][cn] = yy;
		ne[0][++cn] = h[0][ny];
		h[0][ny] = cn;
		to[0][cn] = yx;
		ne[1][cn] = h[1][yx];
		h[1][yx] = cn;
		to[1][cn] = ny;
		ne[1][--cn] = h[1][yy];
		h[1][yy] = cn;
		to[1][cn] = nx;
		++cn;
	}
	for(t = 0, i = 1; i <= n << 1; ++i){
		if(!vis[i]) dfs1(i);
	}
	for(i = n << 1; i >= 1; --i){
		if(vis[q[i]]){
			++cnt;
			dfs2(q[i]);
		}
	}
	for(i = 1; i <= n ; ++i){
		if(scc[i] == scc[i + n]) flag = 1;
	}
	if(flag){
		cout << "IMPOSSIBLE\n";
	}else{
		cout << "POSSIBLE\n";
		for(i = n << 1; i >= 1; --i){
			if(!vis[q[i]]) dfs(q[i]);
		}
		for(i = 1; i <= n; ++i){
			cout << ans[i] << " ";
		}
	}
}