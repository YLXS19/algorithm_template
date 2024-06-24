//哈夫曼编码
#include<bits/stdc++.h>
using namespace std;
string str;
int n[27],l,aws,a,b;
int main(){
	int i;
	while(cin>>str){
		if(str=="END")return 0;
		memset(n,0,sizeof(n));
		l=str.size();
		for(i=0;i<l;i++){
			if(str[i]=='_')n[26]++;
			else n[str[i]-'A']++;
		}
		priority_queue<int,vector<int>,greater<int>>q;
		aws=0;
		for(i=0;i<27;i++){
			if(n[i])q.push(n[i]);
		}
		if(q.size()==1)aws=q.top();
		while(q.size()>1){
			a=q.top();
			q.pop();
			b=q.top();
			q.pop();
			aws+=a+b;
			q.push(a+b);
			//printf("sum=%d aws=%d\n",a+b,aws);
		}
		printf("%d %d %.1f\n",l*8,aws,l*8/1.0/aws);
	}
}