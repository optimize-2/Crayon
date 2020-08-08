//Luogu P3371
#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int pre[200005];
struct edge
{
	int v,w;
	edge(int a,int b)
	{
		v=a,w=b;
	}
	bool operator < (const edge& rw )const
	{
		return w>rw.w;
	}
};
priority_queue<edge>q;
vector<edge>u[200010];
bool vst[100010];
int n,m,x,len[100010];
void dijkstra(int x)
{
	for(int i=1; i<=n; i++)
	{
		len[i]=0x3f3f3f3;
	}
	len[x]=0;
	q.push(edge(x,0));
	while(!q.empty())
	{
		edge tmp=q.top();
		q.pop();
		if(vst[tmp.v]==1) continue;
		vst[tmp.v]=1;
		for(int i=0; i<u[tmp.v].size(); i++)
		{
			edge y=u[tmp.v][i];
			if(len[y.v]>y.w+tmp.w)
			{
				len[y.v]=y.w+tmp.w;
				q.push(edge(y.v,len[y.v]));
			}
		}
	}
}
int main()
{
	cin>>n>>m>>x;
	for(int i=0;i<m;i++)
	{
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		u[uu].push_back(edge(vv,ww));
	}
	dijkstra(x);
	for(int i=1;i<=n;i++)
		if(len[i]==0x3f3f3f3)cout<<2147483647<<" ";
else cout<<len[i]<<' ';
		cout<<endl;
}