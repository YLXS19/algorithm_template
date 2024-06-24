//带权并查集
#include<bits/stdc++.h>
using namespace std;
#define N 50010
int fa[N], re[N];
int find(int x){
	int f = fa[x];
	if(f != x){
		fa[x] = find(f);
		re[x] = (re[x] + re[f]) % 3;
		return fa[x];
	}else return x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k, i, ans = 0;
	cin >> n >> k;
	for(i = 1; i <= n ; ++i){
		fa[i] = i;
	}
	while(k--){
		int t, x, y;
		cin >> t >> x >> y;
		if(x > n || y > n){
			++ans;
			continue;
		}
		int fx = find(x);
		int fy = find(y);
		if(t == 1){
			if(fx == fy && re[x] != re[y]){
				++ans;
			}else if(fx != fy){
				fa[fx] = fy;
				re[fx] = (re[y] - re[x] + 3) % 3;
				// re[x] + re[fx] == re[y]
			}
		}else{
			if(fx == fy && (re[x] - re[y] + 3) % 3 != 1){
				++ans;
			}else if(fx != fy){
				fa[fx] = fy;
				re[fx] = (re[y] - re[x] + 4) % 3;
				// re[x] + re[fx] - re[y] == 1
			}
		}
	}
	cout << ans;
}