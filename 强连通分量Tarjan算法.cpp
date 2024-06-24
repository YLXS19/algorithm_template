//强连通分量Tarjan算法
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector<int>e[20010];
set<int>ans[20010];
int dfn[20010], low[20010], tot;
int stk[20010], instk[20010], top;
int scc[20010], siz[20010], cnt;
bool vis[20010];
void tarjan(int x){
	dfn[x] = low[x] = ++tot;
	stk[++top] = x;
	instk[x] = 1;
	for(int y : e[x]){
		if(!dfn[y]){
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}else if(instk[y]){
			low[x] = min(low[x], low[y]);
		}
	}
	if(low[x] == dfn[x]){
		++cnt;
		int y;
		do{
			y = stk[top--];
			instk[y] = 0;
			scc[y] = cnt;
			++siz[cnt];
			ans[cnt].insert(y);
		}while(y != x);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, i;
	cin >> n >> m;
	for(i = 1; i <=	m; ++i){
		int u, v;
		cin	>> u >> v;
		e[u].pb(v);
	}
	for(i = 1; i <= n; ++i){
		if(!dfn[i]) tarjan(i);
	}
	// int ans = 0;
	// for(i = 1; i <= cnt; ++i){
		// if(siz[i] > 1) ++ans;
	// }
	// cout << ans;
	cout << cnt << endl;
	for(i = 1; i <= n; ++i){
		if(!vis[scc[i]]){
			vis[scc[i]] = 1;
			for(int j : ans[scc[i]]){
				cout << j << " ";
			}
			cout << endl;
		}
	}
}