#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M,S,D;
    cin >> N >> M >> S >> D;

    vector<vector<pair<int,int>>> adj(N+1);
    for(int i = 0; i < M; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<ll> dist1(N+1, INF) , dist2(N+1, INF);
    priority_queue< pair<ll,int>, vector<pair<ll, int>>, greater<>> pq;

    dist1[S] = 0;
    pq.push({0,S});

    while(!pq.empty()){
        auto[cd, u] = pq.top();
        pq.pop();
        if(cd>dist2[u]) continue;
        for(auto[v,w]: adj[u]){
            ll nd  = cd + w; 
            if(nd < dist1[v]){
                dist2[v] = dist1[v];
                dist1[v] = nd;
                pq.push({nd,v});
            }
            else if(nd>dist1[v] && nd<dist2[v]){
                dist2[v] = nd;
                pq.push({nd,v});
            }
        }
    }
    if(dist2[D]==INF) cout << -1 << "\n";
    else cout << dist2[D] << "\n";
    
    return 0;

}