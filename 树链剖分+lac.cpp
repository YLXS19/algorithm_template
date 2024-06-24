//树链剖分+lac
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define N 1000100
#define M 1000100
struct str{
	int to,ne;
}e[M];
int L,R,n,m,q,k,dfn,h[N],siz[N],son[N],de[N],fa[N],top[N],Oid[N],Nid[N],va[N];
void swap(int *p1,int *p2){
	int i=*p1;
	*p1=*p2;
	*p2=i;
}
void dfs1(int x,int fath){
	int i;
	siz[x]=1;de[x]=de[fath]+1;
	fa[x]=fath;
	for(i=h[x];i;i=e[i].ne){
		int t=e[i].to;
		if(t==fath)continue;
		dfs1(t,x);
		siz[x]+=siz[t];
		if(siz[son[x]]<siz[t])son[x]=t;
	}
}
void dfs2(int x,int topx){
	int i;
	top[x]=topx;
	//Nid[x]=++dfn;
	//Oid[dfn]=x;
	if(son[x])dfs2(son[x],topx);
	for(i=h[x];i;i=e[i].ne){
		if(e[i].to==fa[x]||e[i].to==son[x])continue;
		dfs2(e[i].to,e[i].to);
	}
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(de[top[x]]<de[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	return de[x] < de[y] ? x : y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	de[0]=siz[0]=0;
	int i,s;
	cin>>n>>q>>s;
	dfn=0;
	// memset(h,0,sizeof(h));
	// for(i=1;i<=n;i++)cin>>va[i];
	for(i=1;i<n;i++){
		int ii=i<<1,u,v;
		cin>>u>>v;
		e[ii].ne=h[u];
		e[ii].to=v;
		h[u]=ii;
		e[ii-1].ne=h[v];
		e[ii-1].to=u;
		h[v]=ii-1;
	}
	dfs1(s,0);
	dfs2(s,s);
	while(q--){
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << endl;
	}
}