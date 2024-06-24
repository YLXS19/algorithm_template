//trie
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
string s[100010],t;
int tr[3000010][130],cnt[3000010],vis[3000010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T,n,q,i,j,k;
	cin>>T;
	while(T--){
		cin>>n>>q;
		int id=0,idx=0;
		for(i=0;i<n;++i){
			cin>>s[i];
			int p=0;
			for(j=0;j<s[i].size();++j){
				if(!tr[p][s[i][j]]){
					tr[p][s[i][j]]=++id;
				}
				p=tr[p][s[i][j]];
				++cnt[p];
			}
			k=s[i].size();
		}
		while(q--){
			cin>>t;
			//cout<<t<<endl;
			int p=0;
			for(i=0;i<t.size();++i){
				if(!tr[p][t[i]]){
					p=0;
					break;
				}
				p=tr[p][t[i]];
				//cout<<int(t[i])<<" "<<t[i]<<" "<<p<<" "<<cnt[p]<<endl;
			}
			cout<<cnt[p]<<endl;
		}
		for(i=0;i<id;++i){
			cnt[i]=0;
			for(j=0;j<130;j++)tr[i][j]=0;
		}
	}
}