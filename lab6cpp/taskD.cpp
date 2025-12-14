#include <bits/stdc++.h>
using namespace std;


pair<int, int> bfs_farther(int start, const vector<vector<int>>&adj, vector<int>& parent, vector<int>& dist){
    int n = adj.size()-1;
    parent.assign (n+1, -1);
    dist.assign(n+1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    parent[start] = -1;

    int far_node = start;
    while(!q.empty()){
        int u = q.front() ; q.pop();
        for(int v: adj[u]){
            if(dist[v]==-1){
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
                if(dist[v]>dist[far_node]) far_node = v;
            }
        }
    }
    return {far_node, dist[far_node]};
}


int main(){
    int N, M;
    cin >> N;
    M = N-1;

    vector<vector<int>> adj(N+1);
    for(int i = 0; i<M;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<int> parent, dist;

    auto p1 = bfs_farther(1,adj,parent,dist);
    int A = p1.first;

    auto p2 = bfs_farther(A, adj,parent, dist);
    int B = p2.first;

    int diameter_length = p2.second;

    vector<int> path;
    int cur = B;
    while(cur != - 1){
        path.push_back(cur);
        cur=parent[cur];
    }

    cout << diameter_length<< "\n";
    cout << A << " " << B << "\n";
    return 0;
}

