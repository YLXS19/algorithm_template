//扩展KMP
#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a, b;
ll z[20000010], p[20000010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	ll nb, na, i, l, r, sz, sp;
	nb = b.size();
	na = a.size();
	z[0] = nb;
	r = 0;
	sz = nb + 1;
	for(i = 1; i < nb; ++i){
		z[i] = 0;
		if(i < r) z[i] = min( z[i - l], r - i);
		while(b[z[i]] == b[i + z[i]] && i + z[i] <= nb) ++z[i];
		if(i + z[i] > r) l = i, r = i + z[i];
		sz ^= (i + 1) * (z[i] + 1);
	}
	sp = r = 0;
	for(i = 0; i < na; ++i){
		p[i] = 0;
		if(i < r) p[i] = min( z[i - l], r - i);
		while(b[p[i]] == a[i + p[i]] && p[i] < nb && i + p[i] < na) ++p[i];
		if(i + p[i] > r) l = i, r = i + p[i];
		sp ^= (i + 1) * (p[i] + 1);
	}
	cout << sz << endl << sp << endl;
}