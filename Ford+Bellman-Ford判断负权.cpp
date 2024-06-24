//Ford+Bellman-Ford判断负权
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int k,i,j;
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}//Ford
	for(k=1;k<=n;k++){
		for(i=1;i<=m;i++){
			if(dis[v[i]]>dis[u[i]]+w[i]){
				dis[v[i]]=dis[u[i]]+w[i];
			}
		}
	}//Bellman-Ford
	bool flag=0;
	for(i=1;i<=m;i++){
		if(dis[v[i]]>dis[u[i]]+w[i])flag=1;
	}
	if(flag==1)//有负权；
	
}