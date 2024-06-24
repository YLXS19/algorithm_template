#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	inv[1]=1;
	for(int i=2;i<=N;i++){
		inv[i]=(ll)(p-p/i)*inv[p%i]%p;
	}
}