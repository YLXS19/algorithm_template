//线段树+离散化
#include<bits/stdc++.h>
using namespace std;
int n,s[400001],a;
void update(int l,int r,int rt){
	if(l==r){
		s[rt]=1;
		return;
	}
	int m=(r+l)>>1,rr=rt<<1;
	if(a<=m)update(l,m,rr);
	else update(m+1,r,rr+1);
	s[rt]=s[rr]+s[rr+1];
}
int fin(int l,int r,int rt){
	if(a<=l){
		return s[rt];
	}
	int m=(r+l)/2,rr=rt*2;
	if(a<=m)return fin(l,m,rr)+fin(m+1,r,rr+1);
	else return fin(m+1,r,rr+1);
}
struct str{
	int v,d,p;
}st[100001];
bool cmp1(str t1,str t2){
	return t1.v<t2.v;
}
bool cmp2(str t1,str t2){
	return t1.p<t2.p;
}
int main(){
	while(scanf("%d",&n)==1){
		int i;
		long long ans=0;
		memset(s,0,sizeof(s));
		for(i=1;i<=n;i++){
			scanf("%d",&st[i].v);
			st[i].p=i;
		}
		sort(st+1,st+n+1,cmp1);
		for(i=1;i<=n;i++){
			st[i].d=i;
		}
		sort(st+1,st+n+1,cmp2);
		for(i=1;i<=n;i++){
			a=st[i].d;
			update(1,n,1);
			a++;
			ans+=fin(1,n,1);
		}
		printf("%lld\n",ans);
	}
}