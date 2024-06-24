哈希表
#include<bits/stdc++.h>
using namespace std;
#define MA 700001
int p[101],g[MA],f[MA];
int has(int x){
	int k=x;
	x%=MA;
	if(x<0)x+=MA;
	while(f[x]!=0&&g[x]!=k){
		x=(x+1)%MA;
	}
	return x;
}
int main(){
	int i,j,a,b,c,d;
	for(i=1;i<=100;i++)p[i]=i*i;
	while(scanf("%d%d%d%d",&a,&b,&c,&d)==4){
		if((a>0&&b>0&&c>0&&d>0)||(a<0&&b<0&&c<0&&d<0)){
			printf("0\n");
			continue;
		}
		memset(g,0,sizeof(g));
		memset(f,0,sizeof(f));
		for(i=1;i<=100;i++){
			for(j=1;j<=100;j++){
				int k=a*p[i]+b*p[j],x;
				x=has(k);
				g[x]=k;f[x]++;
			}
		}
		int ans=0;
		for(i=1;i<=100;i++){
			for(j=1;j<=100;j++){
				int k=-(c*p[i]+d*p[j]),x;
				x=has(k);
				ans+=f[x];
			}
		}
		printf("%d\n",ans*16);
	}
}