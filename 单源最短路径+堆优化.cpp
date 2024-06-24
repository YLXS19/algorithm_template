#include<bits/stdc++.h>
using namespace std;
int n,m,ss,h[100001],ans[100001];
bool vis[100001]={0};
struct str{
	int to,dis,next;
}e[200001];
struct que{
	int x,d;
	friend bool operator<(que q1,que q2){
		return q1.d>q2.d;
	}
}s,f;
int main(){
	cin>>n>>m>>ss;
	memset(h,-1,sizeof(h));
	for(int i=1;i<=n;i++)ans[i]=2147483647;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[i].to=v;
		e[i].dis=w;
		e[i].next=h[u];
		h[u]=i;
	}
	priority_queue<que>q;
	s.d=0;
	s.x=ss;
	q.push(s);
	while(!q.empty()){
		s=q.top();
		q.pop();
		if(vis[s.x])continue;
		vis[s.x]=1;
		ans[s.x]=s.d;
		for(int k=h[s.x];k!=-1;k=e[k].next){
			if(vis[e[k].to])continue; 
			f.x=e[k].to;
			f.d=e[k].dis+s.d;
			q.push(f);
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}