//sg函数
#include<bits/stdc++.h>
using namespace std;
int k,s[101],l[101],h[101],m,aws,f[10001];
int sg(int x);
int main(){
	while(cin>>k){
		if(k==0)return 0;
		for(int i=1;i<=k;i++){
			cin>>s[i];
		}
		sort(s+1,s+k+1);
		cin>>m;
		memset(f,-1,sizeof(f));
		f[0]=0;
		for(int i=1;i<=m;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>h[j];
			}
			if(f[h[1]]==-1)f[h[1]]=sg(h[1]);
			aws=f[h[1]];
			for(int j=2;j<=l[i];j++){
				if(f[h[j]]==-1)f[h[j]]=sg(h[j]);
				aws^=f[h[j]];
			}
			//for(int i=0;i<=100;i++)cout<<f[i]<<endl;
			//cout<<aws;
			if(aws)cout<<"W";
			else cout<<"L";
		}
		//for(int i=0;i<=100;i++)cout<<i<<" "<<f[i]<<endl;
		cout<<endl;
	}
}
int sg(int x){
	int t,v[1001]={0};
	for(int i=1;i<=k;i++){
		t=x-s[i];
		if(t<0)break;
		if(f[t]==-1)f[t]=sg(t);
		v[f[t]]=1;
	}
	for(int i=0;;i++){
		if(!v[i])return i;
	}
}