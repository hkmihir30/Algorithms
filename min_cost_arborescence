#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF 2e10

class Graph
{
	public:
        ll V,M;
        vector <pair<ll , double >> *adj ;
        vector <double> cost;
        vector <ll> parent;
        vector <ll> id;
        vector <ll> done;

		Graph(ll V,ll M)
		{
			this->V = V ;
            this->M = M ;
			adj = new vector<pair<ll ,double >> [V+1] ;
            for(ll i = 0 ; i <= V ; i++)
            {
                cost.push_back(INF);
                id.push_back(-1);
                done.push_back(-1);
                parent.push_back(-1);
            }
		}

		Graph(ll V)
		{
			this->V = V ;
			adj = new vector<pair<ll ,double >> [V+1] ;
		}

		void add_edge(ll u , ll v , double weight)
		{
			adj[u].push_back(make_pair(v,weight));
		}

        void tolological_sort()
        {
            // in used for storing in degrees of each nodes 
            ll in[V] = {0} ,i=0,j=0,vstd = 0;

            while(i < V)
            {
                vector <pair <ll,double>> :: iterator it ;
                for(it = adj[i].begin() ; it != adj[i].end() ; it++)
                {
                    in[it->first]++ ;
                }
                i++ ;
            }

            ll count = 0 ;
            for(j = 0 ; j < V ; j++)
            {
                if(in[j] == 0)
                    count++ ;
            }

            // priority queue used for lexicographically ordering 
			priority_queue <pair<ll , double > , vector<pair<double,ll>>, 
			 							greater<pair<double,ll>>> pq ;

            for(j = 0 ; j < V ; j++)
            {
                if(!in[j])
                    pq.push(make_pair(j,1));
            }

            vector <ll> topo ;

            while(!pq.empty())
            {
                i = (pq.top()).first ;
                pq.pop();

                vector <pair <ll, double>> :: iterator it ;
                for(it = adj[i].begin(); it != adj[i].end() ; it++)
                {
                    in[it->first]-- ;
                    if(!in[it->first])
                    {
                        pq.push(make_pair(it->first,1));
                    }
                }

                topo.push_back(i);
                vstd++ ;
            }

            if(vstd == V)
            {
                for(i = 0 ; i < V ; i++)
                    cout << topo[i]+1 << " ";
                cout << "\n";
            }
            else // cycle exists 
            {
                cout << "-1\n";
                return ;
            }

        }

		void dijkstra(ll src,ll dest)
		{
            // priority queue used to keep the edge with minimum length at the top 
			priority_queue <pair<double , ll > , vector<pair<double,ll>>, 
			 							greater<pair<double,ll>>> pq ;

            // initialize dist of each node as INF from the source 
			vector <double> path(V , INF);
            ll i , j ;
			pq.push(make_pair(0,src));
		    path[src] = 0 ;

			while(!pq.empty())
			{
				i = (pq.top()).second ;
				pq.pop();

				vector <pair<ll,double>>:: iterator it ;
				for(it = adj[i].begin();it != adj[i].end();it++)
				{
					ll v = it->first ;
					double weight = it->second ;

                    // relaxation 
                    if(path[i]+weight < path[v])
                    {
                        path[v] = path[i]+weight ;
                        pq.push(make_pair(path[v],v));
                    }
					
				}
			}
            cout << path[dest] << "\n";
		}

        void bfs(ll src, ll dest)
        {
            ll i ;
            vector <ll> visited(V,0);
            vector <ll> dist(V,INF);

            visited[src] = 1 ;
            dist[src] = 0 ;

            queue <ll> q ;
            q.push(src);

            while(!q.empty())
            {
                ll u = q.front();
                q.pop();
                vector <pair<ll,double>>:: iterator it ;
                for(it = adj[u].begin(); it != adj[u].end() ; it++)
                {
                    if(visited[it->first] == 0)
                    {
                        visited[it->first] = 1 ;
                        dist[it->first] = dist[u]+1 ;
                        q.push(it->first);
                    }
                    if(it->first == dest)
                    {
                        cout << dist[it->first] << "\n";
                        return ;
                    }
                }
                visited[u] = 2 ;
            }
            cout << "-1\n";
        }

        void min_cost_arbor(ll source)
        {
            ll N = V ;

            ll i,j ;
            ll res = 0 ;
            while(1)
            {
                cost = {INF} ;
                vector <pair<ll,double>>:: iterator it ;
                ll u = 1 ;
                while(u <= N)
                {
                    for(it = adj[u].begin(); it != adj[u].end() ; it++)
                    {
                        ll v = it->first ;
                        ll weight = it->second ;

                        if(cost[v] > weight && u != v)
                        {
                            cost[v] = weight ;
                            parent[v] = u ;
                        }
                    }
                    u++ ;
                }
                
                for(i = 1 ; i <= N ; i++)
                {
                    if(source == i)
                        continue ;
                    else if(cost[i] == INF)
                        return ;
                }

                ll count = 0 ;
                for(i = 1 ; i <= N ; i++)
                {
                    id[i] = -1 ;
                    done[i] = -1 ;
                }

                cost[source] = 0 ;

                for(i = 1 ; i <= N ; i++)
                {
                    res += cost[i];
                    ll v = i ;
                    while(done[v] != i && id[v] == -1 && v != source)
                    {
                        done[v] = i ;
                        v = parent[v] ;
                    }

                    if(v != source && id[v] == -1)
                    {
                        for(j = parent[v] ; j != v ; j = parent[j])
                        {
                            id[j] = count ;
                        }
                        id[v] = count++ ;
                    }
                }

                if(count == 0 )
                    break ;

                for(i = 1 ; i <= N ; i++)
                {
                    if(id[i] == -1)
                        id[i] = count++ ;
                }

                Graph grf_temp(N,M);
                u = 1 ;
                while(u <= N)
                {
                    for(it = adj[u].begin(); it != adj[u].end() ; it++)
                    {
                        ll v = it->first ;
                        double weight = it->second ;

                        if(id[u] != id[v])
                            grf_temp.add_edge(id[u],id[v],weight-cost[v]);
                        else
                            grf_temp.add_edge(id[u],id[v],weight);
                    }
                    u++ ;
                }
                N = count ;
                source = id[source];
                this->V = N ;
                this->adj = grf_temp.adj ;
            }
            cout << res << "\n";
        }

        // used to free the allocated space
        ~Graph()
        {
            free(adj) ;
        }
};



int main()
{
    ll t ;
    cin >> t ;
    while(t--)
    {
        ll N , M , source ;
        cin >> N >> M >> source ;
        Graph grf(N,M);
        
        ll i ;
        for(i = 0 ; i < M ; i++)
        {
            ll u,v ;
            cin >> u >> v ;

            double w ;
            cin >> w ;
            grf.add_edge(u,v,w);
        }
        grf.min_cost_arbor(source);
    }
    return 0 ;
}
