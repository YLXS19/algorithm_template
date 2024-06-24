#include <bits/stdc++.h>
using namespace std;

const int M = 10000005;
int n;
int link[M], g[M][2];
bool vis[M];

bool dfs(int x) {
	for (int i = 0; i < 2; ++i) {
		int y = g[x][i];
		if (vis[y]) continue;
		vis[y] = true;
		if (link[y] == -1 || dfs(link[y])) {
			link[y] = x;
			return true;
		}
	}
	return false;
}

int hungary() {
	int ans = 0;
	memset(link, -1, sizeof link);
	for (int i = 1; i <= n; ++i) {
		memset(vis, 0, sizeof vis);
		ans += dfs(i);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(link, -1, sizeof link);
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> g[i][0] >> g[i][1];
	}
	cout << hungary();
}