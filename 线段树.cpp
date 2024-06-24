//线段树
#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[100000],A,B;
struct str{
	int v,lmax,rmax;
}s[200000];
void build(int l,int r,int rt){
	if(l==r){
		s[rt].v=1;
		s[rt].lmax=s[rt].rmax=l;
		return;
	}
	int m=(l+r)>>1,rr=rt<<1;
	//cout<<(l+r)<<endl;
	build(l,m,rr);
	build(m+1,r,rr+1);
	s[rt].v=max(s[rr].v,s[rr+1].v);
	if(a[m]<a[m+1]){
		s[rt].v=max(s[rr+1].lmax-s[rr].rmax+1,s[rt].v);
		if(s[rr].lmax==m)s[rt].lmax=s[rr+1].lmax;
		else s[rt].lmax=s[rr].lmax;
		if(s[rr+1].rmax==m+1)s[rt].rmax=s[rr].rmax;
		else s[rt].rmax=s[rr+1].rmax;
		
	}
	else{
		s[rt].lmax=s[rr].lmax;
		s[rt].rmax=s[rr+1].rmax;
	}
}
void update(int l,int r,int rt){
	if(l==r){
		s[rt].v=1;
		s[rt].lmax=s[rt].rmax=l;
		return;
	}
	int m=(l+r)>>1,rr=rt<<1;
	if(A<=m)update(l,m,rr);
	else update(m+1,r,rr+1);
	s[rt].v=max(s[rr].v,s[rr+1].v);
	if(a[m]<a[m+1]){
		s[rt].v=max(s[rr+1].lmax-s[rr].rmax+1,s[rt].v);
		if(s[rr].lmax==m)s[rt].lmax=s[rr+1].lmax;
		else s[rt].lmax=s[rr].lmax;
		if(s[rr+1].rmax==m+1)s[rt].rmax=s[rr].rmax;
		else s[rt].rmax=s[rr+1].rmax;
		
	}
	else{
		s[rt].lmax=s[rr].lmax;
		s[rt].rmax=s[rr+1].rmax;
	}
}
int fin(int l,int r,int rt){
	if(A<=l&&r<=B){
		return s[rt].v;
	}
	int m=(l+r)>>1,rr=rt<<1,aws=0;
	if(A<=m)aws=fin(l,m,rr);
	if(B>m)aws=max(aws,fin(m+1,r,rr+1));
	//cout<<A<<" B="<<B<<" m="<<m<<endl;
	if(A<=m&&B>m&&a[m]<a[m+1]){
		//cout<<"aws"<<endl;
		int lx=max(s[rr].rmax,A),rx=min(s[rr+1].lmax,B);
		aws=max(aws,rx-lx+1);
	}
	return aws;
}
int main(){
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&m);
		int i;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		build(0,n-1,1);
		//for(i=1;i<=2*n;i++)cout<<s[i].v<<" "<<s[i].lmax<<" "<<s[i].rmax<<endl;
		//cout<<endl;
		while(m--){
			char c;
			while(scanf("%c",&c))if(c=='Q'||c=='U')break;
			scanf("%d%d",&A,&B);
			if(c=='Q'){
				printf("%d\n",fin(0,n-1,1));
			}
			else{
				a[A]=B;
				update(0,n-1,1);
				//for(i=1;i<=2*n;i++)cout<<s[i].v<<" "<<s[i].lmax<<" "<<s[i].rmax<<endl;
				//cout<<endl;
			}
		}
	}
}