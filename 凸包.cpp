//凸包
#include<bits/stdc++.h>
using namespace std;
int n,x[50001],y[50001],p[50000],ans[50001],cn;
int direction(int a,int b,int c,int d){
	return (x[b]-x[a])*(y[d]-y[c])-(x[d]-x[c])*(y[b]-y[a]);
}
double lon(int a,int b){
	return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
bool cmp(int a,int b){
	if(direction(n,a,n,b)>=0)return 1;
	else return 0;
}
int main(){
	while(scanf("%d",&n)==1){
		int i,k,yy=99999;
		for(i=1;i<=n;i++){
			p[i]=i;
			scanf("%d%d",&x[i],&y[i]);
			if(yy>y[i]){
				yy=y[i];
				k=i;
			}
		}
		int xk=x[k],yk=y[k];
		x[k]=x[n];
		y[k]=y[n];
		x[n]=xk;
		y[n]=yk;
		sort(p+1,p+n,cmp);
		cn=2;
		ans[0]=n;
		ans[2]=p[2];
		ans[1]=p[1];
		for(i=3;i<n;i++){
			while(direction(ans[cn-1],ans[cn],ans[cn],p[i])<0)cn--;
			if(direction(ans[cn-1],ans[cn],ans[cn],p[i])==0){
				if(lon(p[i],ans[cn-1])>lon(ans[cn],ans[cn-1]))ans[++cn]=p[i];
				else{
					int an=ans[cn];
					ans[cn]=p[i];
					ans[++cn]=an;
				}
				continue;
			}
			ans[++cn]=p[i];
		}
		//
		int aws=0,j,l;
		for(i=0;i<=cn;i++){
			for(j=0;j<=cn;j++){
				if(i==j)continue;
				for(l=0;l<=cn;l++){
					if(l==j||l==i)continue;
					int di=abs(direction(ans[i],ans[j],ans[i],ans[l]));
					aws=max(di,aws);
				}
			}
		}
		printf("%.2f\n",0.5*aws);
	}
}