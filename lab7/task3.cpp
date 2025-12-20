#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M; 
    
    vector<vector<pair<int, int>>> adj(N+1);

    for(int i=0; i < M ; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> dist(N+1, INF);
    dist[1] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,1});

    while(!pq.empty()){
        auto[curDanger, u] = pq.top();
        pq.pop();

        if(curDanger>dist[u]) continue;

        for(auto[v,w]:adj[u]){
            int newDanger = max(dist[u], w);
            if(newDanger < dist[v]){
                dist[v] = newDanger;
                pq.push({dist[v], v});
            }
        }
    }
    for(int i = 1; i<=N; i++){
        if(dist[i]==INF) cout << -1 <<" ";
        else cout<<dist[i]<<" ";
    }
    cout << "\n";
    return 0;
}