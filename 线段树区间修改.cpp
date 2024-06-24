//线段树区间修改
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int N,M,Q,L,R,C;
struct str{
	ll lz,v;
}st[400010];
void build(int l,int r,int rt){
	st[rt].lz=0;
	if(l==r){
		st[rt].v=1;
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
	st[rt<<1].v+=st[rt].lz*ln;
	st[rt<<1|1].v+=st[rt].lz*rn;
	st[rt].lz=0;
}
void update(int l,int r,int rt){
	if(L<=l&&r<=R){
		st[rt].v+=C*(r-l+1);
		st[rt].lz+=C;
		return;
	}
	int m=(l+r)>>1;
	if(st[rt].lz)pushdown(rt,m-l+1,r-m);
	if(L<=m)update(l,m,rt<<1);
	if(R>m)update(m+1,r,rt<<1|1);
	st[rt].v=st[rt<<1|1].v+st[rt<<1].v;
}
ll query(int l,int r,int rt){
	if(L<=l&&r<=R)return st[rt].v;
	if(L>r||R<l)return 0;
	int m=(l+r)>>1;
	if(st[rt].lz)pushdown(rt,m-l+1,r-m);
	return query(l,m,rt<<1)+query(m+1,r,rt<<1|1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		 cin>>N>>M>>Q;
		 build(1,N,1);
		 while(M--){
		 	cin>>L>>R>>C;
		 	update(1,N,1);
		 }
		 while(Q--){
		 	cin>>L>>R;
		 	cout<<query(1,N,1)<<endl;
		 }
	}
}