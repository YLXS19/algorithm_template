//指数型母函数
#include<bits/stdc++.h>
using namespace std;
#define ll long long
double c1[11],c2[11];
int A[11],v[11];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,i,j,k;
	A[0]=1;
	for(i=1;i<=10;i++)A[i]=i*A[i-1];
	while(cin>>n>>m){
		for(i=1;i<=n;i++){
			cin>>v[i];
		}
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for(i=0;i<=v[1];i++){
			c1[i]=1.0/A[i];
		}
		for(i=2;i<=n;i++){
			for(j=0;j<=m;j++){
				for(k=0;k<=v[i];k++){
					if(k+j>m)break;
					c2[j+k]+=c1[j]/A[k];
				}
			}
			for(j=0;j<=m;j++){
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		printf("%.0f\n",c1[m]*A[m]);
	}
}