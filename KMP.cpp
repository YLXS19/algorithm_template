//KMP
#include<bits/stdc++.h>
using namespace std;
string a,b;
int p[1001];
void pre(){
	p[0]=-1;
	int i,j=-1;
	for(i=0;i<b.size()-1;i++){
		while(j>-1&&b[i+1]!=b[j+1])j=p[j];
		if(b[i+1]==b[j+1])j++;
		p[i+1]=j;
	}
}
int main(){
	while(cin>>a){
		if(a=="#")break;
		cin>>b;
		pre();
		int i,j=-1,ans=0,n=a.size()-1;
		// for(i=0;i<b.size();i++)cout<<p[i]<<" ";
		// cout<<endl;
		for(i=-1;i<n;i++){
			while(j>-1&&a[i+1]!=b[j+1])j=p[j];
			if(a[i+1]==b[j+1])j++;
			if(j==b.size()-1){
				ans++;
				j=-1;
				//j=p[j];
			}
		}
		printf("%d\n",ans);
	}
}