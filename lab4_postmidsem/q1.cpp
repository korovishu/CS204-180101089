#include<bits/stdc++.h>
using namespace std;

class graph
{
private:
	int n;
	list<int> *adj;
	int *color;
public:
	
	graph(int n);
	void add_edge(int v, int w);
	bool is_bipartite(int v);
	bool whole_graph();
};
graph::graph(int n)
{
	this->n=n;
	adj=new list<int>[n];
	color = new int[n];
}
void graph::add_edge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}
bool graph::is_bipartite(int v)
{
	color[v]=2;
	list<int> q;
	q.push_back(v);
	while(!q.empty())
	{
		int s=q.front();
		q.pop_front();
		for(auto i:adj[s])
		{
			if(color[i]==color[s]) return false;
			else if(!color[i])
			{
				if(color[s]==2) color[i]=1;
				else color[i]=2;
				q.push_back(i);
			}
		}
	}
	return true;
}
bool graph::whole_graph()
{
	for(int i=0; i<n; i++)
	{
		if(!color[i])
		{
			if(!is_bipartite(i)) return false;
		}
	}
	return true;
}


int main()
{
	int n,m;cin>>n>>m;
	graph g(n);
	while(m--)
	{
		int v,w;cin>>v>>w;
		g.add_edge(v,w);
	}
	if(g.whole_graph()) cout<<"YES\n";
	else cout<<"NO\n";
}
