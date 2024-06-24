//倍增算法
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
int fa[10001],p[10001][101],L[10001];
void swap(int *p1,int *p2){
	int i=*p1;
	*p1=*p2;
	*p2=i;
}
void pre(int n){
	for(i=0;i<n;j++){
		for(int j=0;1<<j<n;j++){
			p[i][j]=-1;
		}
	}
	for(i=0;i<n;i++){
		p[i][0]=fa[i];
	}
	for(int j=1;1<<j<n;j++){
		for(int i=0;i<n;i++){
			if(p[i][j-1]!=-1){
				p[i][j]=p[p[i][j-1]][j-1];
			}
		}
	}
}
int LAC(int u,int v){
	int tmp,log,i;
	if(L[u]<L[v])swap(u,v);
	for(log=1;1<<log<=L[u];log++);
	log--;
	//下面的for使，u和v位于同一层;
	for(i=log;i>=0;i--){
		if(l[u]-(1<<i)>L[v])u=p[u][i];
	}
	if(u==v)return u;
	for(i=log;i>=0;i--){
		if(p[u][i]!=-1&&p[u][i]!=p[v][i])u=p[u][i],v=p[v][i];
	}
	return fa[u];
}
//ST
int po(int a,int n){
	int ans=1;
	while(n){
		if(n%2){
			ans*=a;
			ans%=mod;
		}
		n/=2;
		a*=a;
		a%=mod;
	}
	return ans;
}
m[i][0]=i;
if(a[m[i][j-1]]<a[m[i+1<<(j-1)][j-1]])m[i][j]=m[i][j-1];
else m[i][j]=m[i+2<<(j-1)][j-1];
k=[log(j-i+1)]
if(a[m[i][k]]<a[m[j-1<<k+1][k]])RMQ(i,j)=m[i][k];
else RMQ(i,j)=m[j-1<<k+1][k];