#include<bits/stdc++.h>
#define nax 1000010
#define ll long long int 
using namespace std;
typedef pair<int,int> p;
const long long int INF = 100000000000;

vector<vector<ll> >graph(nax,vector<ll>());
vector<vector<ll> >cost(nax,vector<ll>());
vector<ll>dis(nax);

void g_clear()
{
    for(ll i=0; i<nax; i++){
        graph[i].clear();
        cost[i].clear();
    }
}

void dijkstra(ll destination,ll src)
{
    for(ll i=0; i<nax; i++) dis[i] = INF; 
    
    dis[src] = 0;
    
    priority_queue<p> q;
    q.push({src,0});
    
    while(!q.empty()){
        ll s = q.top().first;
        ll d = q.top().second;
        
        q.pop();
        
        for(ll i=0; i<graph[s].size(); i++){
            ll node = graph[s][i];
            
            if(dis[s] + cost[s][i] < dis[node]){
                dis[node] = dis[s] + cost[s][i];
                q.push({node,dis[node]});
            }
        }
    }
}

int main()
{
        ios_base::sync_with_stdio(0);
        ll test;
        cin>>test;
        while(test--){
            g_clear();
            
            ll n,m;
            cin>>n>>m;
            
            for(ll i=0; i<m; i++){
                ll u,v,c;
                cin>>u>>v>>c;
                
                graph[u].push_back(v);        //point to be noted--- "it's a directed graph"//
                
                cost[u].push_back(c);
            }
            ll a,b;
            cin>>a>>b;
            
            dijkstra(b,a);
            
            if(dis[b] == INF){
                cout<<"NO"<<endl;
            }
            else{
                cout<<dis[b]<<endl;
            }
            dis.clear();
         
        }
    return 0;
}
