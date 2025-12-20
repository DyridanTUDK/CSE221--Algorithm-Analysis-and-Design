#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const  ll INF = 1e18;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M ,S, D;
    cin >> N >> M >> S >> D;

    vector<int> u(M), v(M);
    vector<int> w(M);

    for(int i = 0; i < M; i++) cin >> u[i];
    for(int i = 0; i < M; i++) cin >> v[i];
    for(int i = 0; i < M; i++) cin >> w[i];


    vector<vector<pair<int,int>>> adj(N+1);

    for(int i = 0; i<M ; i++){
        adj[u[i]].push_back({v[i], w[i]});
    }

    // Dijsktra
    vector<ll> dist(N+1, INF);
    vector<int> parent(N+1,-1);

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    dist[S] = 0;
    pq.push({0,S});

    while(!pq.empty()){
        auto[cd, node] = pq.top();
        pq.pop();

        if(cd>dist[node]) continue;

        for (auto [next,wt]:adj[node])
        {
            if(dist[node]+wt < dist[next]){
                dist[next] = dist[node] + wt;
                parent[next] = node;
                pq.push({dist[next], next});
            }
        }
        
    }

    if(dist[D] == INF){
        cout << -1 << '\n';
        return 0; 
    }

    vector<int> path;
    for(int curr = D; curr!= -1; curr = parent[curr]){
        path.push_back(curr);
    }
    reverse(path.begin(), path.end());

    cout << dist[D] << "\n";
    for(int node: path){
        cout<<node<<" ";
    }
    cout << "\n";

    return 0 ;
}