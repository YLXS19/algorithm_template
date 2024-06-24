#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i,j,n
	cin>>n;
	for(i=2;i<n;i++){
		if(!vis[i])p[++cnt]=i;
		for(j=1;j<cnt&&i*p[j]<n;j++){
			vis[i*p[j]]=1;
			//p[j];
			if(i%p[j]==0)break;
		}
	}
	
}