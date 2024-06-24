//manacher
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
string s;
char c[30000000];
int d[30000000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	int i;
	int n = s.size() * 2 + 1;
	int k = 0;
	int l, r = 1;
	c[0] = '$';
	c[++k] = '#';
	for (i = 0; i < s.size(); ++i){
		c[++k] = s[i];
		c[++k] = '#';
	}
	d[1] = 1;
	for (i = 2; i <= n; ++i){
		if (i <= r) d[i] = min(d[r - i + l], r - i + 1);
		while (c[i - d[i]] == c[i + d[i]]) ++d[i];
		if(i + d[i] - 1 > r) l = i - d[i] + 1, r = i + d[i] - 1;
	}
	int ans = 0;
	for(i = 1; i <= n; ++i) ans = max(ans, d[i]);
	cout << ans - 1;
}