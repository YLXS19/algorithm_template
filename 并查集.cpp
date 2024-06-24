//并查集
#include<bits/stdc++.h>
using namespace std;
int N,M,le[10001],ran[10001];
int l(int x){
	while(x!=le[x])x=le[x];
	return x;
}
int main(){
	cin>>N>>M;
	int i,t,a,b;
	for(i=1;i<=N;i++){
		le[i]=i;
		ran[i]=1;
	}
	while(M--){
		scanf("%d%d%d",&t,&a,&b);
		int la=l(a),lb=l(b);
		if(t==1&&la!=lb){
			if(ran[lb]>ran[la]){
				le[la]=lb;
				ran[lb]=max(ran[la]+1,ran[lb]);
			}
			else{
				le[lb]=la;
				ran[la]=max(ran[lb]+1,ran[la]);
			}
		}
		if(t==2){
			if(la==lb)puts("Y");
			else puts("N");
		}
	}
}