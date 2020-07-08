#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll cnt=0, node, edge;

bool bipartite2(vector<vector<ll> > &graph, ll src, ll color[], ll node)
{
    color[src] = 1;
    queue<ll>q;
    q.push(src);
    
    while(!q.empty())
    {
        ll x = q.front();
        q.pop();
        
        
        for(ll i=0; i<graph[x].size(); i++){
            ll y = graph[x][i];
            
            if(color[y] == -1){
                color[y] = 1 - color[x];
                q.push(y);
             }
             
             else if(color[y] == color[x])
                return false;
        }
    }
    return true;        
}

bool bipartite(vector<vector<ll> > &graph, ll node)
{
    ll color[2005];
    for(int i=1; i<=node; i++)
        color[i] = -1;
    
    for(ll i=1; i<=node; i++){
        if(color[i] == -1){
            if(bipartite2(graph, i , color, node) == false)
                return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll test;
    cin >> test;
    
    while(test--){
        cin >> node >> edge;
        
        vector<vector<ll> > graph(node+2,vector<ll>());
        
        for(ll i=0; i<edge; i++){
            ll u,v;
            cin >> u >> v;
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
            
        if(bipartite(graph,node)){
            cout << "Scenario #" << ++cnt << ":" << endl;
            cout << "No suspicious bugs found!" << endl;
        }
            
        else{
            cout << "Scenario #" << ++cnt << ":" << endl;
            cout << "Suspicious bugs found!" << endl;
        }
        
        for(int i=0; i<node; i++){
            graph[i].clear();
        }
         
     }
     
     return 0;
}
        
                
