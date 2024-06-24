#include<stdio.h>
int N,a[100001];
void p(int l,int r){
	int i=l,j=r,k,mid=a[(l+r)/2];
	while(i<=j){
		while(mid>a[i])i++;
		while(mid<a[j])j--;
		if(i<=j){
			k=a[i];
			a[i]=a[j];
			a[j]=k;
			i++;
			j--;
		}
	}
	if(j>l)p(l,j);
	if(i<r)p(i,r);
}
int main(){
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++){
		scanf("%d",&a[i]);
	}
	p(1,N);
	for(i=1;i<=N;i++){
		printf("%d ",a[i]);
	}
}
