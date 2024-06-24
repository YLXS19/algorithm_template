#include<bits/stdc++.h>
char s[1000011];
bool vis[1000011];
int id=0,tr[1000011][128],cnt[1000011],q[1000011],p[1000011];
void bTree(){
	int i,k=0;
	for(i=0;s[i];i++){
		int x=s[i];
		if(!tr[k][x])tr[k][x]=++id;
		k=tr[k][x];
	}
	cnt[k]++;
}
void pre(){
	int hh=0,tt=-1,i;
	for(i=0;i<128;i++){
		if(tr[0][i])q[++tt]=tr[0][i];
	}
	while(hh<=tt){
		int x=q[hh++];
		for(i=0;i<128;i++){
			int y=tr[x][i];
			if(!y)tr[x][i]=tr[p[x]][i];
			else{
				p[y]=tr[p[x]][i];
				q[++tt]=y;
			}
		}
	}
}
int main(){
	int cn=0,i,j,ans=0;
	scanf("%d",&cn);
	for(i=0;i<cn;i++){
		scanf("%s",s);
		bTree();
	}
	pre();
	scanf("%s",s);
	for(i=0,j=0;s[i];i++){
		int x=s[i];
		j=tr[j][x];
		int y=j;
		while(y&&vis[y]==0){
			ans+=cnt[y];
			cnt[y]=0;
			y=p[y];
			vis[y]=1;
		}
	}
	printf("%d\n",ans);	
}