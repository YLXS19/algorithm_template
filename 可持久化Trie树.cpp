//可持久化Trie树
#include<bits/stdc++.h>
using namespace std;
#define N 300010
#define M 300010
int n, m;
int a, s[N+M], root[N];
int tr[N*50][2], id;
int ver[N*50];
void insert(int ii){
	int x = root[ii] = ++id;
	int y = root[ii - 1];
	ver[x] = ii;
	for(int i = 23; i >= 0; --i){
		int k = s[ii]>>i & 1;
		tr[x][!k] = tr[y][!k];
		tr[x][k] = ++id;
		x = tr[x][k];
		y = tr[y][k];
		ver[x] = ii;
	}
}
int query(int x, int l, int sum){
	int ans = 0;
	for(int i = 23; i >=0 ; --i){
		int k = sum>>i & 1;
		if(ver[tr[x][!k]] >= l){
			ans += 1<<i;
			x = tr[x][!k];
		}else x = tr[x][k];
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	ver[0] = -1;
	root[0] = ++id;
	for(int i = 23; i >= 0; --i){
		tr[id][1] = 0;
		tr[id - 1][0] = ++id;
		
	}
	for(int i = 1; i <= n; ++i){
		cin >> a;
		s[i] = a ^ s[i-1];
		insert(i);
	}
	while(m--){
		char t;
		cin >> t;
		if(t == 'A'){
			cin >> a;
			s[++n] = s[n] ^ a;
			insert(n);
		}else{
			int l, r, x;
			cin >> l >> r >> x;
			cout << query(root[r - 1], l - 1, s[n] ^ x) << endl;
		}
	}
}