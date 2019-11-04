 #include <bits/stdc++.h> 
using namespace std; 
#define ll long long
class Edge  
{  
    public: 
    ll src, dest;
    ll weight;  
};  

class Graph  
{  
    public:  
    ll V, E;    
    Edge* edge;  
};  

Graph* createGraph(ll V, ll E)  
{  
    Graph* graph = new Graph;  
    graph->V = V;  
    graph->E = E;  
  
    graph->edge = new Edge[E];  
  
    return graph;  
}  
 
class subset  
{  
    public: 
    ll parent;  
    ll rank;  
};  
    
ll find(subset subsets[], ll i)  
{  
 
    if (subsets[i].parent != i)  
        subsets[i].parent = find(subsets, subsets[i].parent);  
  
    return subsets[i].parent;  
}   
void Union(subset subsets[], ll x, ll y)  
{  
    ll xroot = find(subsets, x);  
    ll yroot = find(subsets, y);  

    if (subsets[xroot].rank < subsets[yroot].rank)  
        subsets[xroot].parent = yroot;  
    else if (subsets[xroot].rank > subsets[yroot].rank)  
        subsets[yroot].parent = xroot;  

    else
    {  
        subsets[yroot].parent = xroot;  
        subsets[xroot].rank++;  
    }  
}  
int myComp(const void* a, const void* b)  
{  
    Edge* a1 = (Edge*)a;  
    Edge* b1 = (Edge*)b;  
    return a1->weight < b1->weight;  
}  
   
ll Max_Cost(Graph* graph)  
{  
    ll V = graph->V;  
    Edge result[V]; 
    ll e = 0; 
    ll i = 0;    
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);  

    subset *subsets = new subset[( V * sizeof(subset) )];  
   
    for (ll v = 0; v < V; ++v)  
    {  
        subsets[v].parent = v;  
        subsets[v].rank = 0;  
    }  
  
    while (e < V - 1 && i < graph->E)  
    {    
        Edge next_edge = graph->edge[i++];  
  
        ll x = find(subsets, next_edge.src);  
        ll y = find(subsets, next_edge.dest);  
        if (x != y)  
        {  
            result[e++] = next_edge;  
            Union(subsets, x, y);  
        }   
    }  
 	ll M=1e9+7;
    ll ans=1; 
    for (i = 0; i < e; ++i)  
        ans=(ans*(result[i].weight))%M;  
    return ans;  
}  
 
int main()  
{  
    ll n,m; cin>>n>>m; 
    Graph* graph = createGraph(n, m);  
  	ll c=0;
  	while(m--)
  	{
  		ll i,j;ll k;
  		cin>>i>>j>>k;
  		graph->edge[c].src = i-1;  
	    graph->edge[c].dest = j-1;  
	    graph->edge[c].weight = k;
	    c++;
  	}
  	
    ll ans= Max_Cost(graph);  
    cout<<ans<<endl;
  
    return 0;  
}  
