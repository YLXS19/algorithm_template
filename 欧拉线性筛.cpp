#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i = 2; i < N; i++){
		if(!vis[i]) p[++cnt] = i;
		for(j = 1; j <= cnt && i * p[j] < N; j++){
			vis[i * p[j]] = p[j];
			if(i % p[j] == 0)break;
		}
	}
}