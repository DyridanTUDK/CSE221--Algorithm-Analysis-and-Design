#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, S, T;
    cin >> N >> M >> S >> T;

    vector<vector<pair<int,int>>> adj(N+1);

    for(int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    auto dijkstra = [&](int src){
        vector<ll> dist(N+1, INF);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){
            auto [cd, node] = pq.top();
            pq.pop();
            if(cd > dist[node]) continue;

            for(auto [nxt, wt] : adj[node]){
                if(dist[node] + wt < dist[nxt]){
                    dist[nxt] = dist[node] + wt;
                    pq.push({dist[nxt], nxt});
                }
            }
        }
        return dist;
    };

    vector<ll> distA = dijkstra(S); // Alice: S → i
    vector<ll> distB = dijkstra(T); // Bob:   T → i

    ll bestTime = INF;
    int bestNode = -1;

    for(int i = 1; i <= N; i++){
        if(distA[i] == INF || distB[i] == INF) continue;
        ll meetTime = max(distA[i], distB[i]);
        if(meetTime < bestTime || 
          (meetTime == bestTime && i < bestNode)){
            bestTime = meetTime;
            bestNode = i;
        }
    }

    if(bestNode == -1){
        cout << -1 << "\n";
    } else {
        cout << bestTime << " " << bestNode << "\n";
    }

    return 0;
}
