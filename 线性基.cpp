//线性基；
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll d[61],a[100001];
bool check(ll x){
	for(int j=60;j>=0;j--){
		if(x&(1LL<<j)){
			if(d[j]==0){
				return false;
			}else x^=d[j];
		}
	}
	return (x==0);
}
ll find(){
	ll ans=0;
	for(int i=60;i>=0;i--){
		if(((1LL<<i)&ans)==0&&d[i])ans^=d[i];
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<n;i++){
		ll x=a[i];
		for(int j=60;j>=0;j--){
			if(x&(1LL<<j)){
				if(d[j]==0){
					d[j]=x;
					break;
				}
				else x^=d[j];
			}
		}
	}
}