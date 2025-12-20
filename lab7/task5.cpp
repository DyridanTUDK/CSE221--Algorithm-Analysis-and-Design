#include <bits/stdc++.h>
using namespace std;

using ll = long long; 
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> u(M) , v(M), w(M);
    for(int i = 0 ; i < M ; i++) cin >> u[i];
    for(int i = 0 ; i < M ; i++) cin >> v[i];
    for(int i = 0 ; i < M ; i++) cin >> w[i];

    vector<vector<pair<int, int>>> adj(N+1);
    for(int i = 0; i<M; i++){
        adj[u[i]].push_back({v[i], w[i]});
    }

    vector<vector<ll>> dist(N+1, vector<ll>(2,INF));

    priority_queue<
        tuple<ll, int, int>,
        vector<tuple<ll,int,int>>,
        greater<>
    
    > pq;

    dist[1][0] = dist[1][1] = 0;
    pq.push({0,1,0});
    pq.push({0,1,1});

    while(!pq.empty()){
        auto[cd, node, lastParity] = pq.top();
        pq.pop();
        if(cd>dist[node][lastParity]) continue;
        for(auto[nxt, wt]: adj[node]){
            int edgeParity = wt%2;
            if(edgeParity == lastParity) continue;

            ll newDist = cd + wt;
            if(newDist < dist[nxt][edgeParity]){
                dist[nxt][edgeParity] = newDist;
                pq.push({newDist, nxt, edgeParity});
            }
        }
    }
    ll ans = min(dist[N][0], dist[N][1]);
    if(ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}