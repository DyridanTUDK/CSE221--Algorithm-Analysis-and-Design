#include <bits/stdc++.h>
using namespace std;

int main(){
     ios::sync_with_stdio(false);
     cin.tie(nullptr);
     int N,M;
     if(!(cin>>N>>M)) return 0;
     vector<int> u(M) , v(M),w(M);
     for (int i = 0; i < M; i++) cin>>u[i];
     for (int i = 0; i < M; i++) cin>>v[i];
     for (int i = 0; i < M; i++) cin>>w[i];

    vector<vector<pair<int,int>>> adj(N+1);
    for (size_t i = 0; i < M; i++)
    {
        if(u[i]>=1 && u[i] <=N){
            adj[u[i]].push_back({v[i], w[i]});
        }
    }
    
    for (size_t i = 1; i <= N; i++)
    {
        cout << i << ": ";
        for(auto &e : adj[i]){
            cout << "(" << e.first << "," << e.second << ") ";
        }
        cout << "\n";
    }
    
    return 0;

}