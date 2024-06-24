//普通母函数
#include<bits/stdc++.h>
using namespace std;
int c1[121],c2[121];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,i,j,k;
	while(cin>>n){
		for(i=0;i<=n;i++){
			c2[i]=0;
			c1[i]=0;
		}
		for(i=0;i<=n;i++){
			c1[i]=1;
		}
		for(i=2;i<=n;i++){
			for(j=0;j<=n;j++){
				for(k=0;k+j<=n;k+=i){
					c2[j+k]+=c1[j];
				}
			}
			for(j=0;j<=n;j++){
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		cout<<c1[n]<<endl;
	}
}