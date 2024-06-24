//树链剖分+路径修改
#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct str{
	ll lz,v;
}st[200010];
struct st{
	int to,ne;
}e[100001];
ll a[50001];
int n,p,C,dfn,h[50001],siz[50001],son[50001],de[50001],fa[50001],top[50001],Oid[50001],Nid[50001];
void swap(int *p1,int *p2){
	int i=*p1;
	*p1=*p2;
	*p2=i;
}
void build(int l,int r,int rt){
	st[rt].lz=0;
	if(l==r){
		st[rt].v=a[Oid[l]];
		return;
	}
	int m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	st[rt].v=st[rt<<1|1].v+st[rt<<1].v;
}
void pushdown(int rt,int ln,int rn){
	st[rt<<1].lz+=st[rt].lz;
	st[rt<<1|1].lz+=st[rt].lz;
	//cout<<st[rt<<1].v<<" "<<st[rt<<1|1].v<<endl;
	st[rt<<1].v+=st[rt].lz*ln;
	st[rt<<1|1].v+=st[rt].lz*rn;
	st[rt].lz=0;
	//cout<<rt<<" "<<st[rt<<1].lz<<" "<<st[rt<<1].v<<" "<<st[rt<<1|1].v<<endl;
}
void update(int L,int R,int l,int r,int rt){
	if(L<=l&&r<=R){
		st[rt].v+=C*(r-l+1);
		st[rt].lz+=C;
		return;
	}
	int m=(l+r)>>1;
	if(st[rt].lz)pushdown(rt,m-l+1,r-m);
	if(L<=m)update(L,R,l,m,rt<<1);
	if(R>m)update(L,R,m+1,r,rt<<1|1);
	st[rt].v=st[rt<<1|1].v+st[rt<<1].v;
}
ll query(int x,int l,int r,int rt){
	if(l==r){
		return st[rt].v;
	}
	if(x>r||x<l)return 0;
	int m=(l+r)>>1;
	if(st[rt].lz)pushdown(rt,m-l+1,r-m);
	if(x<=m)return query(x,l,m,rt<<1);
	else return query(x,m+1,r,rt<<1|1);
}
void dfs1(int x,int fath){
	int i;
	siz[x]=1;de[x]=de[fath]+1;
	son[x]=0;fa[x]=fath;
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
	Nid[x]=++dfn;
	Oid[dfn]=x;
	if(son[x])dfs2(son[x],topx);
	for(i=h[x];i;i=e[i].ne){
		if(e[i].to==fa[x]||e[i].to==son[x])continue;
		dfs2(e[i].to,e[i].to);
	}
}
void chain(int x,int y){
	while(top[x]!=top[y]){
		if(de[top[x]]<de[top[y]])swap(x,y);
		update(Nid[top[x]],Nid[x],1,n,1);
		x=fa[top[x]];
	}
	if(de[x]<de[y])swap(x,y);
	update(Nid[y],Nid[x],1,n,1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	de[0]=siz[0]=0;
	int m,i;
	while(cin>>n>>m>>p){
		dfn=0;
		memset(h,0,sizeof(h));
		for(i=1;i<=n;i++)cin>>a[i];
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
		dfs1(1,0);
		dfs2(1,1);
		build(1,n,1);
		while(p--){
			char c;
			int x,c1,c2;
			while(cin>>c)if(c=='I'||c=='D'||c=='Q')break;
			if(c=='Q'){
				cin>>x;
				//cout<<"N="<<Nid[x]<<endl;
				cout<<query(Nid[x],1,n,1)<<endl;
			}
			else{
				cin>>c1>>c2>>C;
				if(c=='D')C*=-1;
				chain(c1,c2);
			}
		}
	}
}
