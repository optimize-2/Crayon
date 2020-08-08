#include<bits/stdc++.h>
using namespace std;

int n,m,ans;
bool close[20][20];
string col="00000000000";
map<string,bool>mp;



void dfs(int x,int step) {
	//cout<<x<<" "<<col[x]<<" "<<step<<endl;
	
	for(int i=1;i<=n;i++)
		if(col[x]==col[i]&&close[x][i]&&col[x]!=0&&x!=i) {
			//cout<<"  "<<x<<" "<<i<<" "<<close[x][i]<<endl;
			return;
		}
	
	if(step==n&&mp[col]==0) {
		//cout<<col<<endl;
		mp[col]=1;
		ans++;
		return;
	}
	for(int i=1;i<=n;i++) {
		if(x!=i&&col[i]=='0') {
			for(int c=1;c<=4;c++) {
				if(col[x]==c+'0'&&close[x][i]) continue;
				col[i]=c+'0';
				dfs(i,step+1);
			}
			col[i]='0';
		}
	}
}


int main() {
//	freopen("colour.in","r",stdin);
//	freopen("colour.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++) {
		int a,b;
		cin>>a>>b;
		close[a][b]=1;
		close[b][a]=1;
	}
	/*
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			cout<<close[i][j];
		}
		cout<<endl;
	}
	*/
	col[1]='1';
	dfs(1,1);
	col[1]='2';
	dfs(1,1);
	col[1]='3';
	dfs(1,1);
	col[1]='4';
	dfs(1,1);
	cout<<ans;
}
