//后缀自动机
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
using LL = long long;
const int N = 1e6 + 100;
const int M = 5e6 + 100;
const int mod = 1e9 + 7;
LL cnt[N << 1], ans = 0;
int tot = 1, np = 1;
int fa[N << 1], ch[N << 1][26], len[N << 1];
string s;
vector <int> e[N << 1];
void extend(int c){
	int p =  np;
	np = ++tot;
	len[np] = len[p] + 1;
	cnt[np] = 1;
	for(; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
	if(!p) fa[np] = 1;
	else{
		int q = ch[p][c];
		if(len[q] == len[p] + 1) fa[np] = q;
		else{
			int nq = ++tot;
			len[nq] = len[p] + 1;
			fa[nq] = fa[q];
			fa[q] = nq;
			fa[np] = nq;
			for(; p && ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
			memcpy(ch[nq], ch[q], sizeof(ch[q]));
		}
	}
}
void dfs(int u){
	for(auto v : e[u]){
		dfs(v);
		cnt[u] += cnt[v];
	}
	if(cnt[u] > 1) ans = max(ans, cnt[u] * len[u]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for(int i = 0; s[i]; ++i){
		extend(s[i] - 'a');
	}
	for(int i = 2; i <= tot; ++i){
		e[fa[i]].pb(i);
	}
	dfs(1);
	cout << ans;
}