#include <bits/stdc++.h>
// creates by "Hooku30"
using namespace std ;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#define int long long int
#define loop(i,a,b) for(int i = a ; i < b;i++)
#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define take(a) \
    loop(i, 0, n) { cin >> a[i]; }
#define take1(a) \
    loop(i, 1, n + 1) { cin >> a[i]; }
#define tc(t) \
    int t;    \
    cin >> t; \
    while (t--)
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define INF 0x3f3f3f3f

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

class Edge
{
    public:
        int src,dest,weight ;
};  

class Graph
{
    public:
        int V,E ;
        Edge *edge ;
};

Graph* create_graph(int V,int E)
{
    Graph* graph = new Graph ;
    graph->V = V ;
    graph->E = E ;
    graph->edge = new Edge[E];
    return graph ;
}

void print_arr(int dist[],int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; i++)
        cout << i << " \t\t " << dist[i] << endl;
}

void bellman_ford(Graph* graph , int src)
{
    int V = graph->V ;
    int E = graph->E ;
    int dist[V] ;

    for(int i = 0 ;i < V;i++)
        dist[i] = INT_MAX ;
    dist[src] = 0 ;

    bool counter ;
    for(int i = 1 ; i <= V-1;i++)
    {
        counter = true ;
        for(int j = 0 ; j < E ;j++)
        {
            int u = graph->edge[j].src ;
            int v = graph->edge[j].dest ;
            int weight = graph->edge[j].weight ;
            if(dist[u] != INT_MAX && dist[u] + weight < dist[v] )
            {
                dist[v] = dist[u] + weight ;
                counter = false ;
            }
        }
        if(counter == true)
            break ;
    }

    // checking for -ve cycle only if counter is false 
    if(counter == false)
    {   
        for(int i = 0 ; i < E ; i++)
        {
            int u = graph->edge[i].src ;
            int v = graph->edge[i].dest ;
            int weight = graph->edge[i].weight ;
            if(dist[u] != INT_MAX && dist[v] > dist[u] + weight)
            {
                cout << "Graph contain -ve weight cycle ";
                return ;
            } 
        }
    }

    print_arr(dist,V);
    return ;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int V = 5; 
    int E = 8; 
    Graph* graph = create_graph(V, E);
 
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;
 
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;
 
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;
 
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;
 
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;

    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;

    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;
 
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;

    bellman_ford(graph,0);

    // uncomment to check for -ve cycle
    // // graph having -ve cycle 
    // int V = 4; 
    // int E = 5; 
    // Graph* graph = create_graph(V, E);
 
    // graph->edge[0].src = 1;
    // graph->edge[0].dest = 2;
    // graph->edge[0].weight = 4;
 
    // graph->edge[1].src = 0;
    // graph->edge[1].dest = 4;
    // graph->edge[1].weight = 5;

    // graph->edge[2].src = 2;
    // graph->edge[2].dest = 4;
    // graph->edge[2].weight = 5;

    // graph->edge[3].src = 4;
    // graph->edge[3].dest = 3;
    // graph->edge[3].weight = 3;

    // graph->edge[4].src = 3;
    // graph->edge[4].dest = 2;
    // graph->edge[4].weight = -10;
 
	  // bellman_ford(graph, 1);

    return 0 ;
}
