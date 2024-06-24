//SPFA
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void spfa(int u){
	q.push(u);
	vis[u]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(int i=h[x];i!=-1;i=ne[i]){
			int y=v[i];
			if(dis[x]+w[i]<dist[y]){
				dis[y]=dis[x]+w[i];
				if(!vis[y])vis[y]=1,q.push(y);
			}
		}
	}
}