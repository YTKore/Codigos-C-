#include <bits/stdc++.h>
using namespace std;
typedef vector<int>vi;
typedef pair<int, int>ii;
typedef vector<ii>vii;
#define pb push_back
#define INF 1000000000
vector<vii> G;
vi dist(10001, INF);
vi parent(10001, 0);
int cont=0;
void dijkstra(int n)
{
  dist[n] = 0;
  parent[n]=n;
  priority_queue<ii, vector<ii>, greater<ii> > pq;
  pq.push(ii(0, n));
  while(!pq.empty())
  {
  	ii front=pq.top();
   	pq.pop();
    int u=front.second, d=front.first;
		if(d>dist[u])
    continue;
		for(int i=0;i<G[u].size();i++)
		{
      ii v=G[u][i];
  		if(dist[u]+v.second<dist[v.first])
  		{
        dist[v.first]=dist[u]+v.second;
				parent[v.first]=u;
    		pq.push(ii(dist[v.first], v.first));
      }
    }
  }
}
int ans(int x, int c)
{
  if(parent[x]==x or parent[x]==-1)
  return c;
  else
  {
    c++;
    ans(parent[x],c);
  }
}
int main()
{
  int t,n,m,x,y,p,a,b;
  cin>>t;
  while(t--)
  {
    G.clear();
    dist.assign(10001, INF);
    parent.assign(10001, -1);
    cin>>n>>m;
    G.assign(n+1, vii());
    for(int i=0; i<m; i++)
    {
      cin>>x>>y>>p;
      G[x].pb(ii(y, p));
      G[y].pb(ii(x, p));
    }
    cin>>a>>b;
    dijkstra(a);
    /*for(int i=0;i<n;i++)
    {
      cout<<"La distancia de "<<a<<" hasta "<<i<<" es "<<dist[i]<<endl;
    }
    for(int i=0; i<n; i++)
    printf("%d ", parent[i]);
    printf("\n");*/
    cont=0;
    int res=ans(b,cont);
    if(res>0)
    cout<<"DEBES AGUANTAR "<<res<<" MINIBUSES"<<endl;
    else
    cout<<"HOY HAY PARO"<<endl;
  }
}
