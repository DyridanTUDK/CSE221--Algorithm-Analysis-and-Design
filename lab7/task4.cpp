#include <bits/stdc++.h>
using namespace std;

using ll =  long long;
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M,S,D;
    cin >> N >> M >> S >> D;

    vector<ll> w(N+1);
    for(int i =1 ; i<=N; i++){
        cin >> w[i];
    }

    vector<vector<int>> adj(N+1);
    for(int i = 0; i < M; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<ll> dist(N+1, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;

    dist[S]=w[S];
    pq.push({dist[S], S});

    while (!pq.empty())
    {
        auto[cd,u] = pq.top();
        pq.pop();

        if(cd>dist[u]) continue;
        for(int v: adj[u]){
            ll newCost = dist[u] + w[v];
            if(newCost < dist[v]){
                dist[v] = newCost;
                pq.push({dist[v],v});
            }
        }
    }
    if(dist[D] == INF){
        cout << -1 << "\n";
    }
    else{
        cout << dist[D] << "\n";
    }

    return 0;
}