//矩阵快速幂
#include<bits/stdc++.h>
using namespace std;
int n,m,a[100][100],y[100][100],ans[100][100],an[100][100],f[100];
string s;
void multiply(){
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			int aws=0;
			for(k=0;k<n;k++){
				aws+=a[i][k]*y[k][j];
				aws%=2;
			}
			an[i][j]=aws;
		}
	}
}//矩阵乘法
int main(){
	while(scanf("%d",&m)==1){
		cin>>s;
		int i,j;
		n=s.size();
		memset(a,0,sizeof(a));
		memset(ans,0,sizeof(ans));
		ans[0][0]=a[0][0]=a[0][n-1]=1;
		for(i=1;i<n;i++)ans[i][i]=a[i][i]=a[i][i-1]=1;
		while(m){
			if(m%2){
				for(i=0;i<n;i++){
					for(j=0;j<n;j++)y[i][j]=ans[i][j];
				}
				multiply();
				for(i=0;i<n;i++){
					for(j=0;j<n;j++)ans[i][j]=an[i][j];
				}	
			}
			m/=2;
			for(i=0;i<n;i++){
				for(j=0;j<n;j++)y[i][j]=a[i][j];
			}
			multiply();
			for(i=0;i<n;i++){
				for(j=0;j<n;j++)a[i][j]=an[i][j];
			}
		}//快速幂
		for(i=0;i<n;i++){
			int aws=0;
			for(j=0;j<n;j++){
				aws+=ans[i][j]*(s[j]-'0');
				aws%=2;
			}
			f[i]=aws;
		}
		for(i=0;i<n;i++)printf("%d",f[i]);
		printf("\n");
	}
}